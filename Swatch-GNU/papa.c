/*		
	Papa/Oscar !
	
	variation autour d'un rŽseau de neurones ;
	d'aprs "RŽseaux neuronaux" de Jean-philippe Rennard.

	Version / 3 aožt 2010.
*/

// -------------------------------------------------------------------------------------------------------------

#include "ext.h"							
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "stdlib.h"
#include "math.h"	
#include "time.h"
#include "ext_common.h"		
#include "ext_systhread.h"
#include "commonsyms.h"
	
// -------------------------------------------------------------------------------------------------------------

#define DEF_SYNAPSE_RED				0.62
#define DEF_SYNAPSE_GREEN			0.55
#define DEF_SYNAPSE_BLUE			0.83
#define DEF_SYNAPSE_ALPHA			1.0
#define DEF_FEEDBACK_RED			1.
#define DEF_FEEDBACK_GREEN			0.6
#define DEF_FEEDBACK_BLUE			0.6
#define DEF_FEEDBACK_ALPHA			1.0
#define DEF_WRONG_RED				0.85
#define DEF_WRONG_GREEN				0.85
#define DEF_WRONG_BLUE				0.85
#define DEF_WRONG_ALPHA				1.0

#define DEF_BOX_B_LINEAIRE_RED		0.92
#define DEF_BOX_B_LINEAIRE_GREEN	0.94
#define DEF_BOX_B_LINEAIRE_BLUE		0.67
#define DEF_BOX_B_LINEAIRE_ALPHA	1.0
#define DEF_BOX_U_SIGMOIDE_RED		0.68
#define DEF_BOX_U_SIGMOIDE_GREEN	0.82
#define DEF_BOX_U_SIGMOIDE_BLUE		0.82
#define DEF_BOX_U_SIGMOIDE_ALPHA	1.0
#define DEF_BOX_B_TANH_RED			0.83
#define DEF_BOX_B_TANH_GREEN		0.74
#define DEF_BOX_B_TANH_BLUE			0.84
#define DEF_BOX_B_TANH_ALPHA		1.0
#define DEF_BOX_B_ERROR_RED			0.95
#define DEF_BOX_B_ERROR_GREEN		0.95
#define DEF_BOX_B_ERROR_BLUE		0.95
#define DEF_BOX_B_ERROR_ALPHA		1.0

#define	DEF_OUT_TAILLE				4
#define DEF_BIAIS					0.
#define DEF_THRESHOLD				0.
#define DEF_APPRENTISSAGE			1.
#define DEF_SDWP					0

#define MAX_OUT_TAILLE				128
#define	MAX_SYNAPSES_NOEUD			128
#define MAX_NOEUDS_COUCHE			128
#define SYNAPSES_TOTAL_MAX			2048 
#define NOEUDS_TOTAL_MAX			512
#define FIFO_TAILLE					512

#define POIDS_FEEDBACK				1.
#define POIDS_WRONG					0.

#define BLANC				 0
#define GRIS				 1
#define NOIR				 2
#define SANS_ISSUE			-1
#define COUCHE_SORTIE		-1
#define SOLITAIRE			-2
#define SYNAPSE				 0
#define SYNAPSE_FEEDBACK	 1
#define SYNAPSE_WRONG		-1
#define NORMAL				 1
#define NOBACKWARD			 0
#define NUMBER_ERROR		-1
#define B_LINEAIRE			 0
#define U_SIGMOIDE			 1
#define B_TANH				 2

// -------------------------------------------------------------------------------------------------------------

typedef struct _noeud {
	t_object	*ptr_o ;
	t_object	*ptr_b ;
	long		flag ;
	long		statut ;
	long		distance ;
	long		transfert ;
	double		potentiel ;
	double		retard_A ;
	double		retard_B ;
	double		signal ;
	double		erreur ;
	double		dump_p ;
	double		dump_s ;
	t_object	*ptr_l[MAX_SYNAPSES_NOEUD] ;
	long		type[MAX_SYNAPSES_NOEUD] ;
	long		dest[MAX_SYNAPSES_NOEUD] ;
	double		poids[MAX_SYNAPSES_NOEUD] ;
	long		index ;
	} t_noeud ;
	
// -------------------------------------------------------------------------------------------------------------

typedef struct _papa {
	t_object			ob ;
	t_object			*me ;
	t_object			*oscar ;
	t_object			*me_box ;
	t_object			*oscar_box ;
	t_noeud				*vrac ;
	long				*graf ;
	long				*graf_topo ;
	t_atomarray			*head_data ;
	t_atomarray			*graf_data ;
	t_atomarray			*synapses_data ;
	double				*out_vecteur ;
	double				*in_vecteur ;
	double				*target_vecteur ;
	long				*fifo ;
	long				head_fifo ;
	long				queue_fifo ;
	long				val_fifo ;
	long				in_taille ;
	long				layer_taille ;
	long				out_taille ;
	long				vrac_taille ;
	long				distance_max ;
	long				sdwp ;
	long				papa_transfert ;
	long				oscar_transfert ;
	long				lock_dump ;
	double				biais ;
	double				threshold ;
	double				apprentissage ;
	double				erreur_totale ;
	t_jrgba				ligne_synapse ;
	t_jrgba				ligne_feedback ;
	t_jrgba				ligne_wrong ;
	t_jrgba				box_b_lineaire ;
	t_jrgba				box_u_sigmoide ;
	t_jrgba				box_b_tanh ;
	t_jrgba				box_b_error ;
	t_systhread_mutex	m_mutex ;
	void				*m_clock ;
	void				*m_out[MAX_OUT_TAILLE] ;
	} t_papa ;
	
// -------------------------------------------------------------------------------------------------------------	
	
void	*papa_new					(t_symbol *s, long argc, t_atom *argv) ;
void	papa_appendtodictionary		(t_papa *x, t_dictionary *bd) ;
void	rebuild_from_data			(t_papa *x) ;
void	papa_free					(t_papa *x) ;

void	papa_assist					(t_papa *x, void *b, long m, long a, char *s) ;

void	papa_dblclick				(t_papa *x) ;
void	papa_clear					(t_papa *x) ;
void	papa_dump					(t_papa *x) ;
void	papa_task					(t_papa *x) ;
void	papa_anything				(t_papa *x, t_symbol *s, long argc, t_atom *argv) ;

void	papa_list					(t_papa *x, t_symbol *s, long argc, t_atom *argv) ;
void	papa_learn					(t_papa *x, t_symbol *s, long argc, t_atom *argv) ;
void	papa_target					(t_papa *x, t_symbol *s, long argc, t_atom *argv) ;

void	propagation					(t_papa *x) ;
double	calcul_erreurs				(t_papa *x) ;
void	backpropagation				(t_papa *x) ;
void	initialisation				(t_papa *x) ;

void	find_oscar					(t_papa *x) ;
void	build_graf					(t_papa *x) ;
void	free_graf					(t_papa *x) ;

long	iterate_build_graf			(t_papa *x, t_object *ptr_b) ;
long	iterate_find_oscar			(t_papa *x, t_object *ptr_b) ;
long	vrac_getindexbyptr_outlet	(t_papa *x, t_object *ptr_o, long n) ;
long	vrac_getindexbyptr_inlet	(t_papa *x, t_object *ptr_o, long n) ;
void	graf_box_color				(t_papa *x, t_object *ptr_b, long n) ;
long	put_fifo					(t_papa *x, long n) ;
long	get_fifo					(t_papa *x) ;

double	myrandom_gaussian			(void) ;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

static t_class *papa_class ;

int main (void)
	{	
		t_class *c = NULL ;
		
		common_symbols_init () ;
		
		c = class_new ("papa", (method)papa_new, (method)papa_free, (long)sizeof(t_papa), 0L, A_GIMME, 0) ;
		
		class_addmethod	(c, (method)papa_appendtodictionary,	"appendtodictionary", A_CANT, 0) ;
		class_addmethod (c, (method)papa_assist,				"assist", A_CANT, 0) ;
		class_addmethod (c, (method)papa_dblclick,				"dblclick", A_CANT, 0) ;
		class_addmethod (c, (method)papa_clear,					"clear", 0) ;
		class_addmethod (c, (method)papa_anything,				"anything", A_GIMME, 0) ;
		class_addmethod (c, (method)papa_dump,					"dump_max", 0) ;
		class_addmethod (c, (method)papa_list,					"list", A_GIMME, 0) ;
		class_addmethod (c, (method)papa_learn,					"learn", A_GIMME, 0) ;
		class_addmethod (c, (method)papa_target,				"target", A_GIMME, 0) ;
				
		class_register (CLASS_BOX, c) ; 
		
		CLASS_ATTR_LONG					(c, "embed",	ATTR_FLAGS_NONE, t_papa, sdwp) ;
		CLASS_ATTR_STYLE_LABEL			(c, "embed",	ATTR_FLAGS_NONE, "onoff", "Save Data With Patcher") ;
		CLASS_ATTR_CATEGORY				(c, "embed",	ATTR_FLAGS_NONE, "Hint") ;
		CLASS_ATTR_SAVE					(c, "embed",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "synapse",	ATTR_FLAGS_NONE, t_papa, ligne_synapse) ;
		CLASS_ATTR_STYLE_LABEL			(c, "synapse",	ATTR_FLAGS_NONE, "rgba", "Line Synapse") ;
		CLASS_ATTR_CATEGORY				(c, "synapse",	ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "synapse",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "feedback", ATTR_FLAGS_NONE, t_papa, ligne_feedback) ;
		CLASS_ATTR_STYLE_LABEL			(c, "feedback", ATTR_FLAGS_NONE, "rgba", "Line Feedback") ;
		CLASS_ATTR_CATEGORY				(c, "feedback",	ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "feedback",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "wrong",	ATTR_FLAGS_NONE, t_papa, ligne_wrong) ;
		CLASS_ATTR_STYLE_LABEL			(c, "wrong",	ATTR_FLAGS_NONE, "rgba", "Line Wrong") ;
		CLASS_ATTR_CATEGORY				(c, "wrong",	ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "wrong",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "lineaire",	ATTR_FLAGS_NONE, t_papa, box_b_lineaire) ;
		CLASS_ATTR_STYLE_LABEL			(c, "lineaire",	ATTR_FLAGS_NONE, "rgba", "Box Lineaire") ;
		CLASS_ATTR_CATEGORY				(c, "lineaire",	ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "lineaire",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "sigmoide", ATTR_FLAGS_NONE, t_papa, box_u_sigmoide) ;
		CLASS_ATTR_STYLE_LABEL			(c, "sigmoide", ATTR_FLAGS_NONE, "rgba", "Box Sigmoide") ;
		CLASS_ATTR_CATEGORY				(c, "sigmoide",	ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "sigmoide",	ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_RGBA					(c, "tanh",		ATTR_FLAGS_NONE, t_papa, box_b_tanh) ;
		CLASS_ATTR_STYLE_LABEL			(c, "tanh",		ATTR_FLAGS_NONE, "rgba", "Box Tanh") ;
		CLASS_ATTR_CATEGORY				(c, "tanh",		ATTR_FLAGS_NONE, "Color") ;
		CLASS_ATTR_SAVE					(c, "tanh",		ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_DOUBLE				(c, "biais",	ATTR_FLAGS_NONE, t_papa, biais) ;
		CLASS_ATTR_SAVE					(c, "biais",	ATTR_FLAGS_NONE) ;
		CLASS_ATTR_LABEL				(c, "biais",	ATTR_FLAGS_NONE, "Biais") ;
		CLASS_ATTR_FILTER_CLIP			(c, "biais",	-5., 5.) ;
		
		CLASS_ATTR_DOUBLE				(c, "threshold",		ATTR_FLAGS_NONE, t_papa, threshold) ;
		CLASS_ATTR_SAVE					(c, "threshold",		ATTR_FLAGS_NONE) ;
		CLASS_ATTR_LABEL				(c, "threshold",		ATTR_FLAGS_NONE, "Seuil d'Apprentissage") ;
		CLASS_ATTR_FILTER_CLIP			(c, "threshold",		0., DBL_MAX) ;
		
		CLASS_ATTR_DOUBLE				(c, "apprentissage",	ATTR_FLAGS_NONE, t_papa, apprentissage) ;
		CLASS_ATTR_SAVE					(c, "apprentissage",	ATTR_FLAGS_NONE) ;
		CLASS_ATTR_LABEL				(c, "apprentissage",	ATTR_FLAGS_NONE, "Apprentissage") ;
		CLASS_ATTR_FILTER_CLIP			(c, "apprentissage",	0., DBL_MAX) ;
		
		CLASS_ATTR_LONG					(c, "papa_transfert",		ATTR_FLAGS_NONE, t_papa, papa_transfert) ;
		CLASS_ATTR_ENUMINDEX			(c, "papa_transfert",		ATTR_FLAGS_NONE, "Lineaire Sigmoide Tanh") ;
		CLASS_ATTR_LABEL				(c, "papa_transfert",		ATTR_FLAGS_NONE, "Fonction Transfert Papa") ;
		CLASS_ATTR_SAVE					(c, "papa_transfert",		ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_LONG					(c, "oscar_transfert",		ATTR_FLAGS_NONE, t_papa, oscar_transfert) ;
		CLASS_ATTR_ENUMINDEX			(c, "oscar_transfert",		ATTR_FLAGS_NONE, "Lineaire Sigmoide Tanh") ;
		CLASS_ATTR_LABEL				(c, "oscar_transfert",		ATTR_FLAGS_NONE, "Fonction Transfert Oscar") ;
		CLASS_ATTR_SAVE					(c, "oscar_transfert",		ATTR_FLAGS_NONE) ;
		
		CLASS_ATTR_ORDER				(c, "biais",				ATTR_FLAGS_NONE, "1") ;
		CLASS_ATTR_ORDER				(c, "apprentissage",		ATTR_FLAGS_NONE, "2") ;
		CLASS_ATTR_ORDER				(c, "threshold",			ATTR_FLAGS_NONE, "3") ;
		CLASS_ATTR_ORDER				(c, "oscar_transfert",		ATTR_FLAGS_NONE, "4") ;
		CLASS_ATTR_ORDER				(c, "papa_transfert",		ATTR_FLAGS_NONE, "5") ;
		
		papa_class = c ;
		
		return MAX_ERR_NONE ;
	}

void *papa_new (t_symbol *s, long argc, t_atom *argv)
	{
		t_papa *x = NULL ;
		
		if (x = (t_papa *)object_alloc (papa_class)) 
			{
				long			i ;
				t_dictionary	*d = NULL ; 
				
				srand (time(NULL)) ;
				
				x->layer_taille		= 0 ;
				x->in_taille		= 0 ;
				x->head_fifo		= 0 ;
				x->queue_fifo		= 0 ;
				x->val_fifo			= 0 ;
				x->distance_max		= 0 ;
				x->vrac_taille		= 0 ;
				x->erreur_totale	= 0. ;
				x->lock_dump		= 0 ;
				x->sdwp				= DEF_SDWP ;
				x->papa_transfert	= B_TANH ;
				x->oscar_transfert	= B_LINEAIRE ;
				x->biais			= DEF_BIAIS ;
				x->threshold		= DEF_THRESHOLD ;
				x->apprentissage	= DEF_APPRENTISSAGE ;
				x->out_taille		= DEF_OUT_TAILLE ;
				x->me				= NULL ;
				x->oscar			= NULL ;
				x->me_box			= NULL ;
				x->oscar_box		= NULL ;
				x->vrac				= NULL ;
				x->graf				= NULL ;
				x->graf_topo		= NULL ;
				x->head_data		= NULL ;
				x->graf_data		= NULL ;
				x->synapses_data	= NULL ;
				x->in_vecteur		= NULL ;
				x->out_vecteur		= NULL ;
								
				jrgba_set (&x->ligne_synapse, DEF_SYNAPSE_RED, DEF_SYNAPSE_GREEN, DEF_SYNAPSE_BLUE, DEF_SYNAPSE_ALPHA) ;
				jrgba_set (&x->ligne_feedback, DEF_FEEDBACK_RED, DEF_FEEDBACK_GREEN, DEF_FEEDBACK_BLUE, DEF_FEEDBACK_ALPHA) ;
				jrgba_set (&x->ligne_wrong, DEF_WRONG_RED, DEF_WRONG_GREEN, DEF_WRONG_BLUE, DEF_WRONG_ALPHA) ;

				jrgba_set (&x->box_b_lineaire, DEF_BOX_B_LINEAIRE_RED, DEF_BOX_B_LINEAIRE_GREEN, DEF_BOX_B_LINEAIRE_BLUE, DEF_BOX_B_LINEAIRE_ALPHA) ;
				jrgba_set (&x->box_u_sigmoide, DEF_BOX_U_SIGMOIDE_RED, DEF_BOX_U_SIGMOIDE_GREEN, DEF_BOX_U_SIGMOIDE_BLUE, DEF_BOX_U_SIGMOIDE_ALPHA) ;
				jrgba_set (&x->box_b_tanh, DEF_BOX_B_TANH_RED, DEF_BOX_B_TANH_GREEN, DEF_BOX_B_TANH_BLUE, DEF_BOX_B_TANH_ALPHA) ;
				jrgba_set (&x->box_b_error, DEF_BOX_B_ERROR_RED, DEF_BOX_B_ERROR_GREEN, DEF_BOX_B_ERROR_BLUE, DEF_BOX_B_ERROR_ALPHA) ;

				
				x->fifo	= (long *)sysmem_newptrclear (sizeof(long) * FIFO_TAILLE) ;
				
				if (argc)
					{
						if (atom_gettype (argv) == A_LONG)
							{
								long k = atom_getlong (argv) ;
								
								if (k > 0 && k <= MAX_OUT_TAILLE)
									{
										x->out_taille = k ;
									}
							}
					}
												
				attr_args_process (x, argc, argv) ;
		
				for (i = 0 ; i < (x->out_taille - 1) ; i++)
					{
						inlet_new (x, NULL) ; 
					}
				
				for (i = 0 ; i < x->out_taille + 1 ; i++)
					{
						x->m_out[i] = outlet_new ((t_object *)x, NULL) ;
					}
				
				systhread_mutex_new (&x->m_mutex, SYSTHREAD_MUTEX_NORMAL) ;
				
				x->m_clock	= clock_new ((t_object *)x, (method)papa_task) ;
				
				if (d = (t_dictionary *)gensym ("#D")->s_thing)
					{
						long	argc1, argc2, argc3 ;
						t_atom	*ptr1 = NULL ;
						t_atom	*ptr2 = NULL ;
						t_atom	*ptr3 = NULL ;
						
						dictionary_getatoms (d, gensym ("head_papa_data"),		&argc1, &ptr1) ;
						dictionary_getatoms (d, gensym ("graf_papa_data"),		&argc2, &ptr2) ;
						dictionary_getatoms (d, gensym ("synapses_papa_data"),	&argc3, &ptr3) ;
						
						if (ptr1 && argc1)
							{
								if (x->head_data = atomarray_new (0, NULL))
									{
										atomarray_setatoms (x->head_data, argc1, ptr1) ;
									}
							}
						
						
						if (ptr2 && argc2)
							{
								if (x->graf_data = atomarray_new (0, NULL))
									{
										atomarray_setatoms (x->graf_data, argc2, ptr2) ;
									}
							}
						
						if (ptr3 && argc3)
							{
								if (x->synapses_data = atomarray_new (0, NULL))
									{
										atomarray_setatoms (x->synapses_data, argc3, ptr3) ;
									}
							}
					}
				
				defer_low (x, (method)rebuild_from_data, NULL, 0, NULL) ;			
			}
				
		return x ;
	}

void papa_appendtodictionary (t_papa *x, t_dictionary *bd)
	{
		if (x->vrac && x->graf && x->graf_topo)
			{	
				long	m = 0 ;
				long	n = 0 ;
				t_atom	*head = NULL ;
				t_atom	*graf = NULL ;
				t_atom	*synapses = NULL ;
				
				if (head = (t_atom *)sysmem_newptrclear (sizeof(t_atom) * (x->distance_max + 2 + 2)))
					{
						long i ;
						
						atom_setlong (head, x->vrac_taille) ;
						atom_setlong (head + 1, x->distance_max + 2) ;
						
						for (i = 0 ; i < (x->distance_max + 2) ; i++)
							{
								atom_setlong ((head + i + 2), x->graf_topo[i]) ;
								m += x->graf_topo[i] ;
							}
							
						dictionary_appendatoms (bd, gensym ("head_papa_data"), (x->distance_max + 2 + 2), head) ;
						
						sysmem_freeptr (head) ;
					}	
				
				if (graf = (t_atom *)sysmem_newptrclear (sizeof(t_atom) * (m * 3)))
					{
						long i ;
						long k = 0 ;
						
						for (i = 0 ; i < (x->distance_max + 2) ; i++)
							{
								long j ;
														
								for (j = 0 ; j < x->graf_topo[i] ; j ++)
									{
										long p ;
										
										p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;
										
										n += x->vrac[p].index ;
										
										atom_setlong (graf + k,		p) ;
										atom_setlong (graf + k + 1, x->vrac[p].flag) ;
										atom_setlong (graf + k + 2, x->vrac[p].transfert) ;
										
										k += 3 ;
									}
							}
							
						dictionary_appendatoms (bd, gensym ("graf_papa_data"), (m * 3), graf) ;
						
						sysmem_freeptr (graf) ;
					}
				
				if (synapses = (t_atom *)sysmem_newptrclear (sizeof(t_atom) * (n * 4)))
					{
						long i ;
						long k = 0 ;
						
						for (i = 0 ; i < (x->distance_max + 2) ; i++)
							{
								long j ;
														
								for (j = 0 ; j < x->graf_topo[i] ; j ++)
									{
										long p ;
										
										p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;
										
										if (x->vrac[p].index)
											{
												long t ;
												
												for (t = 0 ; t < x->vrac[p].index ; t++) 
													{
														atom_setlong	(synapses + k,		p) ;
														atom_setlong	(synapses + k + 1,	x->vrac[p].dest[t]) ;
														atom_setlong	(synapses + k + 2,	x->vrac[p].type[t]) ;
														atom_setfloat	(synapses + k + 3,	x->vrac[p].poids[t]) ;
										
														k += 4 ;
													}
											}
									}
							}
							
						dictionary_appendatoms (bd, gensym ("synapses_papa_data"), (n * 4), synapses) ;
						
						sysmem_freeptr (synapses) ;
					}
			}
	}

void rebuild_from_data (t_papa *x)
	{	
		if (!systhread_mutex_trylock (x->m_mutex))
			{
				free_graf (x) ;
				find_oscar (x) ;
				
				if (x->head_data && x->graf_data)
					{
						long	argc1, argc2 ;
						t_atom	*hptr = NULL ;
						t_atom	*gptr = NULL ;
						
						if (!(atomarray_getatoms (x->head_data, &argc1, &hptr)) && !(atomarray_getatoms (x->graf_data, &argc2, &gptr)))
							{
								x->vrac_taille		= atom_getlong (hptr) ;
								x->distance_max		= atom_getlong (hptr + 1) - 2 ;
								x->in_taille		= atom_getlong (hptr + 2) ;
								
								x->graf_topo		= (long *)sysmem_newptrclear (sizeof(long) * (x->distance_max + 2)) ;
								x->graf				= (long *)sysmem_newptrclear (sizeof(long) * ((x->distance_max + 2) * MAX_NOEUDS_COUCHE)) ;
								x->vrac				= (t_noeud *)sysmem_newptrclear (sizeof(t_noeud) * x->vrac_taille) ;
								
								x->in_vecteur		= (double *)sysmem_newptrclear (sizeof(double) * x->in_taille) ;
								x->out_vecteur		= (double *)sysmem_newptrclear (sizeof(double) * x->out_taille) ;
								x->target_vecteur	= (double *)sysmem_newptrclear (sizeof(double) * x->out_taille) ;
								
								if (x->graf && x->graf_topo && x->vrac)
									{
										long i ;
										long k = 0 ;
															
										for (i = 0 ; i < (x->distance_max + 2) ; i++)
											{
												long j ;
												
												x->graf_topo[i] = atom_getlong (hptr + 2 + i) ;
												
												for (j = 0 ; j < x->graf_topo[i] ; j++)
													{
														long p ;
														
														p = atom_getlong (gptr + k) ;
														
														x->graf[(i * MAX_NOEUDS_COUCHE) + j] = p ;
														
														x->vrac[p].flag			= atom_getlong (gptr + k + 1) ;
														x->vrac[p].transfert	= atom_getlong (gptr + k + 2) ;
														x->vrac[p].index		= 0 ;
														
														k += 3 ;
													}
											}
									}
							}	
					}
				
				if (x->synapses_data)
					{
						if (x->graf && x->graf_topo && x->vrac)
							{
								long	argc ;
								t_atom	*ptr = NULL ;
						
								if (!(atomarray_getatoms (x->synapses_data, &argc, &ptr)))
									{
										long i ;
										long t = argc / 4 ;
										long k = 0 ;
										
										for (i = 0 ; i < t ; i++)
											{	
												long p, a ;
												
												p = atom_getlong (ptr + k) ;
												a = x->vrac[p].index ;
												
												x->vrac[p].ptr_l[a]	= NULL ;
												x->vrac[p].type[a]	= atom_getlong	(ptr + k + 2) ;
												x->vrac[p].dest[a]	= atom_getlong	(ptr + k + 1) ;
												
												if (x->sdwp)
													{
														x->vrac[p].poids[a] = atom_getfloat (ptr + k + 3) ;
													}
												else
													{	
														switch (atom_getlong (ptr + k + 2)) {
															case SYNAPSE_WRONG		:	x->vrac[p].poids[a] = POIDS_WRONG ;
																						break ;
															case SYNAPSE			:	x->vrac[p].poids[a] = myrandom_gaussian () ;
																						break ;
															case SYNAPSE_FEEDBACK	:	x->vrac[p].poids[a] = POIDS_FEEDBACK ;
																						break ;
															}
													}
												
												x->vrac[p].index ++ ;
												
												k += 4 ;
											}
									}
							}
					}
					
				systhread_mutex_unlock (x->m_mutex) ;
			}
	}

void papa_free (t_papa *x)
	{ 
		if (x->fifo)
			{
				sysmem_freeptr (x->fifo) ;
			}
		
		free_graf (x) ;
		
		if (x->head_data)
			{
				object_free (x->head_data) ;
			}
			
		if (x->graf_data)
			{
				object_free (x->graf_data) ;
			}
			
		if (x->synapses_data)
			{
				object_free (x->synapses_data) ;
			}
			
		clock_unset (x->m_clock) ;
		object_free (x->m_clock) ;
		
		systhread_mutex_free (x->m_mutex) ;
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void papa_assist (t_papa *x, void *b, long m, long a, char *s)
	{
		if (m == ASSIST_INLET) 
			{ 
				sprintf (s, "(nothing)") ;
			} 
		else 
			{	
				if (!a)
					{
						sprintf (s, "(list)(bang)") ;
					}
				else
					{
						sprintf (s, "(nothing)") ;
					}
			}
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void papa_dblclick (t_papa *x)
	{
		if (!systhread_mutex_trylock (x->m_mutex))
			{
				build_graf (x) ;
				
				systhread_mutex_unlock (x->m_mutex) ;
			}
	}

void papa_clear (t_papa *x) 
	{
		systhread_mutex_lock (x->m_mutex) ;
		
		if (x->graf && x->graf_topo && x->vrac)
			{   
				long i ;
				
				for (i = 0 ; i < (x->distance_max + 2) ; i++)
					{
						long j ;
												
						for (j = 0 ; j < x->graf_topo[i] ; j ++)
							{
								long p ;
								
								p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;
								
								x->vrac[p].potentiel	= 0. ;
								x->vrac[p].signal		= 0. ;
								x->vrac[p].retard_A		= 0. ;
								x->vrac[p].retard_B		= 0. ;
								x->vrac[p].dump_p		= 0. ;
								x->vrac[p].dump_s		= 0. ;
								
								if (x->vrac[p].index)
									{
										long t ;
										
										for (t = 0 ; t < x->vrac[p].index ; t++)
											{
												switch (x->vrac[p].type[t]) 
													{
														case SYNAPSE			:	x->vrac[p].poids[t] = myrandom_gaussian () ;
																					break ;
														case SYNAPSE_FEEDBACK	:	x->vrac[p].poids[t] = POIDS_FEEDBACK ;
																					break ;
														case SYNAPSE_WRONG		:	x->vrac[p].poids[t] = POIDS_WRONG ;
																					break ;
													}
											}
									}
							}
					}
			}
		
		systhread_mutex_unlock (x->m_mutex) ;
	}

void papa_dump (t_papa *x)
	{  
		if (x->graf && x->graf_topo && x->vrac && !x->lock_dump)
			{
				long i ;
				
				x->lock_dump = 1 ;
				
				for (i = 0 ; i < (x->distance_max + 2) ; i++)
					{
						long j ;
						
						post ("// %ld", i) ;
												
						for (j = 0 ; j < x->graf_topo[i] ; j ++)
							{
								long p ;
								
								p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;
								
								switch (x->vrac[p].transfert) 
									{
										case B_LINEAIRE			:	post ("Noeud %ld : Lineaire", p) ;
																	break ;
										case U_SIGMOIDE			:	post ("Noeud %ld : Sigmoide", p) ;
																	break ;
										case B_TANH				:	post ("Noeud %ld : Tanh", p) ;
																	break ;
									}		
								
								post ("    potentiel : %.2lf", x->vrac[p].dump_p) ;
								post ("    signal : %.2lf", x->vrac[p].dump_s) ;
								post ("    retard : %.2lf", x->vrac[p].retard_A) ;
								post ("    erreur : %f", x->vrac[p].erreur) ;

								if (x->vrac[p].index)
									{
										long t ;
										
										for (t = 0 ; t < x->vrac[p].index ; t++)
											{
												post ("    -- dest : %ld / val : %.2lf", x->vrac[p].dest[t], x->vrac[p].poids[t]) ;
											}
									}
							}
					}
				
				clock_fdelay (x->m_clock, 1000.) ;
			}
	}

void papa_task (t_papa *x)
	{
		  x->lock_dump = 0 ;
	}
	
void papa_anything (t_papa *x, t_symbol *s, long argc, t_atom *argv) 
	{
		;
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void papa_list (t_papa *x, t_symbol *s, long argc, t_atom *argv) 
	{	
		systhread_mutex_lock (x->m_mutex) ;
		
		if (argc && argv && x->in_vecteur && x->out_vecteur && x->vrac && x->graf && x->graf_topo)
			{
				long		i ;
				long		k = 0 ;
				t_atom		result[MAX_OUT_TAILLE] ;

				for (i = 0 ; i < x->in_taille ; i++)
					{
						if (i < argc && atom_gettype (argv + i) == A_FLOAT)
							{	
								x->in_vecteur[i] = atom_getfloat (argv + i) ;
							}
						else if (i < argc && atom_gettype (argv + i) == A_LONG)
							{	
								if (x->oscar_transfert == B_LINEAIRE || x->oscar_transfert == B_TANH)
									{
										x->in_vecteur[i] = (double)(((CLIP (atom_getlong (argv + i), 0, 127) * 2.) / 127.) - 1.) ;
									}
								else
									{
										x->in_vecteur[i] = (double)(CLIP (atom_getlong (argv + i), 0, 127) / 127.) ;
									}
								
								k = 1 ;
							}
						else
							{
								x->in_vecteur[i] = 0. ;
							}
					}
				
				propagation (x) ;
				initialisation (x) ;
				
				if (k)
					{
						long j ;
						
						for (j = 0 ; j < x->out_taille ; j++)
							{
								long n ;
								
								if (x->papa_transfert == B_LINEAIRE || x->papa_transfert == B_TANH)
									{
										n = (long)(((x->out_vecteur[j] + 1.) / 2.) * 127.) ;
										atom_setlong (result + j, CLIP (n, 0, 127)) ;
									}
								else
									{
										n = (long)(x->out_vecteur[j] * 127.) ;
										atom_setlong (result + j, CLIP (n, 0, 127)) ;
									}
							}
					}
				else
					{
						long j ;
						
						for (j = 0 ; j < x->out_taille ; j++)
							{
								atom_setfloat (result + j, x->out_vecteur[j]) ;
							}
					}
				
				systhread_mutex_unlock (x->m_mutex) ;
				
				outlet_anything ((void *)x->m_out[x->out_taille], _sym_list, (short)x->out_taille, result) ;
			}
		else
			{
				systhread_mutex_unlock (x->m_mutex) ;
			}
	}
	
void papa_learn	(t_papa *x, t_symbol *s, long argc, t_atom *argv) 
	{
		long flag = 0 ;
		
		systhread_mutex_lock (x->m_mutex) ;
		
		if (argc && argv && x->in_vecteur && x->out_vecteur && x->vrac && x->graf && x->graf_topo)
			{
				long	i ;
				double	k ;
				
				for (i = 0 ; i < x->in_taille ; i++)
					{
						if (i < argc && atom_gettype (argv + i) == A_FLOAT)
							{	
								x->in_vecteur[i] = atom_getfloat (argv + i) ;
							}
						else if (i < argc && atom_gettype (argv + i) == A_LONG)
							{	
								if (x->oscar_transfert == B_LINEAIRE || x->oscar_transfert == B_TANH)
									{
										x->in_vecteur[i] = (double)(((CLIP (atom_getlong (argv + i), 0, 127) * 2.) / 127.) - 1.) ;
									}
								else
									{
										x->in_vecteur[i] = (double)(CLIP (atom_getlong (argv + i), 0, 127) / 127.) ;
									}
							}
						else
							{
								x->in_vecteur[i] = 0. ;
							}
					}
				
				propagation (x) ;
				
				k = calcul_erreurs (x) ;
				
				if (k > x->threshold) 
					{
						backpropagation (x) ;
					}
				else
					{
						flag = 1 ;
					}
				
				initialisation (x) ;
			}
					
		systhread_mutex_unlock (x->m_mutex) ;	
			
		if (flag)
			{
				outlet_anything ((void *)x->m_out[x->out_taille], _sym_bang, 0, NULL) ;
			}
	}

void papa_target (t_papa *x, t_symbol *s, long argc, t_atom *argv) 
	{
		systhread_mutex_lock (x->m_mutex) ;
					
		if (argc && argv && x->target_vecteur)
			{
				long i ;
				
				for (i = 0 ; i < x->out_taille ; i++)
					{
						if (i < argc && atom_gettype (argv + i) == A_FLOAT)
							{	
								x->target_vecteur[i] = atom_getfloat (argv + i) ;
							}
						else if (i < argc && atom_gettype (argv + i) == A_LONG)
							{	
								if (x->papa_transfert == B_LINEAIRE || x->papa_transfert == B_TANH)
									{
										x->target_vecteur[i] = (double)(((CLIP (atom_getlong (argv + i), 0, 127) * 2.) / 127.) - 1.) ;
									}
								else
									{
										x->target_vecteur[i] = (double)(CLIP (atom_getlong (argv + i), 0, 127) / 127.) ;
									}
							}
						else
							{
								x->target_vecteur[i] = 0. ;
							}
					}
			}
		
		systhread_mutex_unlock (x->m_mutex) ;
	}
	
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void propagation (t_papa *x) 
	{  
		long i ;
		
		for (i = 0 ; i < x->in_taille ; i++)
			{
				x->vrac[i].potentiel = x->in_vecteur[i] ;
			}
		
		for (i = 0 ; i < (x->distance_max + 2) ; i++)
			{
				long j ;
										
				for (j = 0 ; j < x->graf_topo[i] ; j ++)
					{
						long	p ;
						double	f ;
						
						p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;
						
						f = x->vrac[p].potentiel + x->vrac[p].retard_A + x->biais ;
						
						switch (x->vrac[p].transfert) 
							{
								case B_LINEAIRE		:	x->vrac[p].signal = f ;
														break ;
								case U_SIGMOIDE		:	x->vrac[p].signal = 1. / (1. + exp (-f)) ;
														break ;
								case B_TANH			:	x->vrac[p].signal = (exp (f) - exp (-f)) / (exp (f) + exp (-f)) ;
														break ;
							}
						
						if (x->vrac[p].index)
							{
								long t ;
																
								for (t = 0 ; t < x->vrac[p].index ; t++)
									{
										if (x->vrac[p].type[t] == SYNAPSE) 
											{
												x->vrac[x->vrac[p].dest[t]].potentiel += x->vrac[p].signal * x->vrac[p].poids[t] ;
											}
										else if (x->vrac[p].type[t] == SYNAPSE_FEEDBACK)
											{
												if (x->vrac[x->vrac[p].dest[t]].flag == NORMAL)
													{
														x->vrac[x->vrac[p].dest[t]].retard_B += x->vrac[p].signal * POIDS_FEEDBACK ;
													}
												else if (x->vrac[x->vrac[p].dest[t]].flag == NOBACKWARD)
													{
														x->vrac[x->vrac[p].dest[t]].potentiel += x->vrac[p].signal * POIDS_FEEDBACK ;
													}
											}	
									}
							}
					}
			}
		
		for (i = 0 ; i < x->out_taille ; i++)
			{
				x->out_vecteur[i] = x->vrac[x->in_taille + i].signal ;
			}
	}

double calcul_erreurs (t_papa *x)
	{
		long	i ;
		double	k = 0. ;
		
		for (i = 0 ; i < x->out_taille ; i++)
			{
				double f, s ;
				double g = 0. ;
				
				f = x->target_vecteur[i] - x->out_vecteur[i] ;
				s = x->vrac[x->in_taille + i].potentiel ;
				
				switch (x->vrac[x->in_taille + i].transfert) 
					{
						case B_LINEAIRE		:	g = 1. ;
												break ;
						case U_SIGMOIDE		:	g = (1. / (1. + exp (-s))) * (1. - (1. / (1. + exp (-s)))) ;
												break ;
						case B_TANH			:	g = 4. / (pow ((exp (s) + exp (-s)), 2)) ;
												break ;
					}
									
				x->vrac[x->in_taille + i].erreur = f * g ;
					
				k += pow (f, 2) ;
			}
		
		x->erreur_totale = k * 0.5 ;
		
		return x->erreur_totale ;
	}

void backpropagation (t_papa *x) 
	{
		long i ;
		
		for (i = x->distance_max ; i >= 0 ; i--)
			{
				long j ;
										
				for (j = 0 ; j < x->graf_topo[i] ; j ++)
					{
						long	p ;
						double	s ;
						double	g = 0. ;
						double	k = 0. ;
						
						p = x->graf[(i * MAX_NOEUDS_COUCHE) + j] ;

						if (x->vrac[p].index)
							{
								long t ;
								
								for (t = 0 ; t < x->vrac[p].index ; t++)
									{
										if (x->vrac[p].type[t] == SYNAPSE)
											{
												k += (x->vrac[x->vrac[p].dest[t]].erreur * x->vrac[p].poids[t]) ;
											}
									}
							}
						
						s = x->vrac[p].potentiel ;
						
						switch (x->vrac[p].transfert) 
							{
								case B_LINEAIRE		:	g = 1. ;
														break ;
								case U_SIGMOIDE		:	g = (1. / (1. + exp (-s))) * (1. - (1. / (1. + exp (-s)))) ;
														break ;
								case B_TANH			:	g = 4. / (pow ((exp (s) + exp (-s)), 2)) ;
														break ;
							}
							
						x->vrac[p].erreur = g * k ;
						
						if (x->vrac[p].index)
							{
								long t ;
								
								for (t = 0 ; t < x->vrac[p].index ; t++) 
									{
										if (x->vrac[p].type[t] == SYNAPSE)
											{
												x->vrac[p].poids[t] += x->apprentissage * x->vrac[x->vrac[p].dest[t]].erreur * x->vrac[p].signal ;
											}
									}
							}
					}
			}
	}

void initialisation (t_papa *x)
	{
		long i ;
		
		for (i = 0 ; i < x->vrac_taille ; i++)
			{
				x->vrac[i].retard_A		= x->vrac[i].retard_B ;
				x->vrac[i].dump_p		= x->vrac[i].potentiel ;
				x->vrac[i].dump_s		= x->vrac[i].signal ;
				x->vrac[i].retard_B		= 0. ;
				x->vrac[i].potentiel	= 0. ;
				x->vrac[i].signal		= 0. ;
			}
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void find_oscar (t_papa *x)
	{
		t_object *ptr_p = NULL ;
				
		if (!(object_obex_lookup (x, gensym ("#P"), &ptr_p)))
			{
				long		result = 0 ;
				t_object	*mybox	= NULL ;
				
				if (!(object_obex_lookup (x, gensym ("#B"), &mybox))) 
					{
						x->me		= jbox_get_object (mybox) ;
						x->me_box	= mybox ;
			
						object_method (ptr_p, gensym ("iterate"), (method)iterate_find_oscar, x, PI_WANTBOX, &result) ;
					}
			}
		
		if (x->oscar)
			{
				object_method (x->oscar, gensym ("set_papa"), x->me) ;
			}
	}

void build_graf (t_papa *x)
	{
		t_object *ptr_p = NULL ;
						
		free_graf (x) ;
		
		if (!(object_obex_lookup (x, gensym ("#P"), &ptr_p)))
			{
				long		result	= 0 ;
				t_object	*mybox	= NULL ;
				
				if (!(object_obex_lookup (x, gensym ("#B"), &mybox))) 
					{
						object_method (ptr_p, gensym ("iterate"), (method)iterate_build_graf, x, PI_WANTBOX, &result) ;
						
						if (x->oscar)   
							{
								x->in_vecteur		= (double *)sysmem_newptrclear (sizeof(double) * x->in_taille) ;
								x->out_vecteur		= (double *)sysmem_newptrclear (sizeof(double) * x->out_taille) ;
								x->target_vecteur	= (double *)sysmem_newptrclear (sizeof(double) * x->out_taille) ;
						
								object_method (x->oscar, gensym ("set_papa"), x->me) ;
								
								if (x->layer_taille <= NOEUDS_TOTAL_MAX)
									{
										t_object	*ptr_b = NULL ;
										t_object	*ptr_l = NULL ;
										long		position = 0 ;
										long		synapses_total = 0 ;
										
										x->vrac_taille = x->layer_taille + x->in_taille + x->out_taille ;
																		
										if (x->vrac = (t_noeud *)sysmem_newptrclear (sizeof(t_noeud) * x->vrac_taille))
											{
												long i ;
												long k = 0 ;
												
												for (i = 0 ; i < x->in_taille ; i ++)
													{
														x->vrac[position].ptr_o		= x->oscar ;
														x->vrac[position].ptr_b		= x->oscar_box ;
														x->vrac[position].flag		= NORMAL ;
														x->vrac[position].statut	= GRIS ;
														x->vrac[position].distance	= 0 ;
														x->vrac[position].transfert	= x->oscar_transfert ;
														x->vrac[position].index		= 0  ;
														
														position ++ ;
													}
																									
												for (i = 0 ; i < x->out_taille ; i ++)
													{
														x->vrac[position].ptr_o		= x->me ;
														x->vrac[position].ptr_b		= x->me_box ;
														x->vrac[position].flag		= NORMAL ;
														x->vrac[position].statut	= NOIR ;
														x->vrac[position].distance	= COUCHE_SORTIE ;
														x->vrac[position].transfert	= x->papa_transfert ;
														x->vrac[position].index		= 0  ;
														
														position ++ ;
													}
												
												ptr_b = jpatcher_get_firstobject (ptr_p) ; 

												while (ptr_b) 
													{
														t_symbol *sym_b = jpatcher_get_maxclass (ptr_b) ;
														
														if (sym_b != gensym ("oscar") && sym_b != gensym ("papa"))
															{
																x->vrac[position].ptr_o		= jbox_get_object (ptr_b) ;
																x->vrac[position].ptr_b		= ptr_b ;
																x->vrac[position].flag		= NORMAL ;	
																x->vrac[position].statut	= BLANC ;
																x->vrac[position].distance	= SOLITAIRE ;
																x->vrac[position].transfert	= B_TANH ;
																x->vrac[position].index		= 0  ;
																																
																if (sym_b == gensym ("+"))
																	{
																		x->vrac[position].flag		= NOBACKWARD ;
																		x->vrac[position].transfert	= B_LINEAIRE ;
																	}
																else if (sym_b == gensym ("-"))
																	{
																		x->vrac[position].flag		= NORMAL ;
																		x->vrac[position].transfert	= B_LINEAIRE ;
																	}
																else if (sym_b == gensym ("pack"))
																	{
																		x->vrac[position].transfert	= U_SIGMOIDE ;
																	}
																
																position ++ ;	
															}
																	
														ptr_b = jbox_get_nextobject (ptr_b) ; 
													}
												
												ptr_l = jpatcher_get_firstline (ptr_p) ;
												
												while (ptr_l) 
													{
														long		m, n ;
														t_object	*ptr_b1 = jpatchline_get_box1 (ptr_l) ;
														t_object	*ptr_b2 = jpatchline_get_box2 (ptr_l) ;
														t_object	*ptr_o1 = jbox_get_object (ptr_b1) ;
														t_object	*ptr_o2 = jbox_get_object (ptr_b2) ;
														long		a = jpatchline_get_outletnum (ptr_l) ;
														long		b = jpatchline_get_inletnum (ptr_l) ;
														
														jpatchline_set_color (ptr_l, &x->ligne_wrong) ;
														
														m = vrac_getindexbyptr_outlet (x, ptr_o1, a) ;
														n = vrac_getindexbyptr_inlet (x, ptr_o2, b) ;
														
														if (!(m == -1 || n == -1) && synapses_total < SYNAPSES_TOTAL_MAX)
															{
																x->vrac[m].ptr_l[x->vrac[m].index]	= ptr_l ;
																x->vrac[m].type[x->vrac[m].index]	= SYNAPSE_WRONG ;
																x->vrac[m].dest[x->vrac[m].index]	= n ;
																x->vrac[m].poids[x->vrac[m].index]	= myrandom_gaussian () ;
																															
																synapses_total ++ ;
																x->vrac[m].index ++ ;
															}
																												
														ptr_l = jpatchline_get_nextline (ptr_l) ;
													}
												
												for (i = 0 ; i < x->in_taille ; i++)
													{
														k += put_fifo (x, i) ;
													}
												
												graf_box_color (x, x->oscar_box, x->oscar_transfert) ;
												graf_box_color (x, x->me_box, x->papa_transfert) ;
												
												if (!k)
													{
														while (!get_fifo(x))
															{
																if (x->val_fifo >= (x->in_taille + x->out_taille))
																	{
																		graf_box_color (x, x->vrac[x->val_fifo].ptr_b, x->vrac[x->val_fifo].transfert) ;
																	}
																	
																if (x->vrac[x->val_fifo].index)
																	{
																		long j ;
																		
																		for (j = 0 ; j < x->vrac[x->val_fifo].index ; j++)
																			{
																				x->vrac[x->val_fifo].type[j] = SYNAPSE ;
																				
																				jpatchline_set_color (x->vrac[x->val_fifo].ptr_l[j], &x->ligne_synapse) ;

																				if (x->vrac[x->vrac[x->val_fifo].dest[j]].distance != COUCHE_SORTIE && !x->vrac[x->vrac[x->val_fifo].dest[j]].statut)
																					{
																						x->vrac[x->vrac[x->val_fifo].dest[j]].statut = GRIS ;
																						x->vrac[x->vrac[x->val_fifo].dest[j]].distance = x->vrac[x->val_fifo].distance + 1 ;
																						
																						if (x->vrac[x->vrac[x->val_fifo].dest[j]].distance > x->distance_max)
																							{
																								x->distance_max = x->vrac[x->vrac[x->val_fifo].dest[j]].distance ;
																							}
																						
																						put_fifo (x, x->vrac[x->val_fifo].dest[j]) ;
																					}
																			}
																	}
																
																x->vrac[x->val_fifo].statut = NOIR ;
															}
													}
												
												for (i = x->in_taille ; i < (x->in_taille + x->out_taille) ; i++)
													{
														if (x->vrac[i].index)
															{
																long j ;
																
																for (j = 0 ; j < x->vrac[i].index ; j++)
																	{
																		if (x->vrac[x->vrac[i].dest[j]].flag == NOBACKWARD)
																			{
																				x->vrac[i].type[j]	= SYNAPSE_WRONG ;
																				x->vrac[i].poids[j]	= POIDS_WRONG ;
																						
																				jpatchline_set_color (x->vrac[i].ptr_l[j], &x->ligne_wrong) ;
																			}
																		else
																			{
																				x->vrac[i].type[j]	= SYNAPSE_FEEDBACK ;
																				x->vrac[i].poids[j]	= POIDS_FEEDBACK ;
																				
																				jpatchline_set_color (x->vrac[i].ptr_l[j], &x->ligne_feedback) ;
																			}
																	}
															} 
													}
													
												x->graf_topo	= (long *)sysmem_newptrclear (sizeof(long) * (x->distance_max + 2)) ;
												x->graf			= (long *)sysmem_newptrclear (sizeof(long) * ((x->distance_max + 2) * MAX_NOEUDS_COUCHE)) ;
												
												if (x->graf && x->graf_topo)
													{
														long j ;
														
														for (j = 0 ; j < x->vrac_taille ; j ++)
															{
																if (x->vrac[j].distance == COUCHE_SORTIE && x->graf_topo[x->distance_max + 1] < MAX_NOEUDS_COUCHE)
																	{
																		x->graf[((x->distance_max + 1) * MAX_NOEUDS_COUCHE) + x->graf_topo[x->distance_max + 1]] = j ;
																		x->graf_topo[x->distance_max + 1] ++ ;
																	}
																else if (x->vrac[j].distance >= 0 && x->graf_topo[x->vrac[j].distance] < MAX_NOEUDS_COUCHE)
																	{
																		x->graf[((x->vrac[j].distance) * MAX_NOEUDS_COUCHE) + x->graf_topo[x->vrac[j].distance]] = j ;
																		x->graf_topo[x->vrac[j].distance] ++ ;
																	}	
																else if (x->vrac[j].distance != SOLITAIRE)
																	{
																		long t ;
																		
																		x->vrac[j].statut = SANS_ISSUE ;
																		 
																		graf_box_color (x, x->vrac[j].ptr_b, NUMBER_ERROR) ;
																		
																		for (t = 0 ; t < x->vrac[j].index ; t++)
																			{
																				x->vrac[j].type[t]		= SYNAPSE_WRONG ;
																				x->vrac[j].poids[t]		= POIDS_WRONG ;
																				
																				jpatchline_set_color (x->vrac[j].ptr_l[t], &x->ligne_wrong) ;
																			}
																	}
															}
														
														for (j = x->distance_max ; j >= 0 ; j--)
															{
																long w ;
																
																for (w = 0 ; w < x->graf_topo[j] ; w++)
																	{
																		long	p ;
																		long	z = 0 ;
																		
																		p = x->graf[(j * MAX_NOEUDS_COUCHE) + w] ;
																		
																		if (x->vrac[p].index)
																			{
																				long t ;
																				
																				for (t = 0 ; t < x->vrac[p].index ; t++)
																					{
																						if (x->vrac[p].flag == NOBACKWARD)
																							{
																								x->vrac[p].type[t]	= SYNAPSE_FEEDBACK ;
																								x->vrac[p].poids[t]	= POIDS_FEEDBACK ;
																										
																								jpatchline_set_color (x->vrac[p].ptr_l[t], &x->ligne_feedback) ;
																							}
																						else if (x->vrac[x->vrac[p].dest[t]].statut == SANS_ISSUE)
																							{
																								if (x->vrac[x->vrac[p].dest[t]].flag || (x->vrac[p].distance < x->vrac[x->vrac[p].dest[t]].distance))
																									{
																										x->vrac[p].type[t]		= SYNAPSE_FEEDBACK ;
																										x->vrac[p].poids[t]		= POIDS_FEEDBACK ;
																										
																										jpatchline_set_color (x->vrac[p].ptr_l[t], &x->ligne_feedback) ;
																									}
																								else
																									{
																										x->vrac[p].type[t]		= SYNAPSE_WRONG ;
																										x->vrac[p].poids[t]		= POIDS_WRONG ;
																								
																										jpatchline_set_color (x->vrac[p].ptr_l[t], &x->ligne_wrong) ;
																									}
																							}
																						else if ((x->vrac[p].distance >= x->vrac[x->vrac[p].dest[t]].distance) && x->vrac[x->vrac[p].dest[t]].distance != COUCHE_SORTIE)
																							{
																								if (x->vrac[x->vrac[p].dest[t]].flag)
																									{
																										x->vrac[p].type[t]	 = SYNAPSE_FEEDBACK ;
																										x->vrac[p].poids[t]	 = POIDS_FEEDBACK ;
																								
																										jpatchline_set_color (x->vrac[p].ptr_l[t], &x->ligne_feedback) ;
																									}
																								else
																									{
																										x->vrac[p].type[t]	= SYNAPSE_WRONG ;
																										x->vrac[p].poids[t]	= POIDS_WRONG ;
																								
																										jpatchline_set_color (x->vrac[p].ptr_l[t], &x->ligne_wrong) ;
																									}
																							}
																						else
																							{
																								z = 1 ;
																							}
																					}
																			}
																		
																		if (!z)
																			{
																				x->vrac[p].statut = SANS_ISSUE ;
																			}
																	}
															}
													}
											}
									}
							}
					}
			}
	}	
	
void free_graf (t_papa *x)
	{
		if (x->oscar)   
			{
				object_method (x->oscar, gensym ("set_papa"), NULL) ;
				x->oscar = NULL ;
			}
			
		if (x->vrac)
			{
				sysmem_freeptr (x->vrac) ;
			}
		
		if (x->graf)
			{
				sysmem_freeptr (x->graf) ;
			}
			
		if (x->graf_topo)
			{
				sysmem_freeptr (x->graf_topo) ;
			}
			
		if (x->in_vecteur)
			{
				sysmem_freeptr (x->in_vecteur) ;
			}
		
		if (x->out_vecteur)
			{
				sysmem_freeptr (x->out_vecteur) ;
			}
		
		if (x->target_vecteur)
			{
				sysmem_freeptr (x->target_vecteur) ;
			}
		
		x->in_taille		= 0 ;
		x->layer_taille		= 0 ;
		x->vrac_taille		= 0 ;
		x->distance_max		= 0 ;
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

long iterate_find_oscar (t_papa *x, t_object *ptr_b)
	{
		t_symbol *sym_b = jpatcher_get_maxclass (ptr_b) ; 
		
		if (sym_b == gensym ("oscar"))
			{
				if (!x->oscar)
					{
						x->oscar		= jbox_get_object (ptr_b) ;
						x->oscar_box	= ptr_b ;
					}
			}
			
		return 0 ;
	}
	
long iterate_build_graf (t_papa *x, t_object *ptr_b)
	{
		t_symbol *sym_b = jpatcher_get_maxclass (ptr_b) ; 
		
		if (sym_b == gensym ("oscar"))
			{
				if (!x->oscar)
					{
						x->oscar		= jbox_get_object (ptr_b) ;
						x->oscar_box	= ptr_b ;
						x->in_taille = object_attr_getlong (ptr_b, gensym ("numoutlets")) ;
					}
			}
		else if (sym_b != gensym ("papa"))
			{
				x->layer_taille ++ ;
			}
			
		return 0 ;
	}

long vrac_getindexbyptr_outlet (t_papa *x, t_object *ptr_o, long n) 
	{
		long k = -1 ;
		
		if (ptr_o == x->oscar && x->vrac[n].index < MAX_SYNAPSES_NOEUD)
			{
				k = n ;
			}
		else if (ptr_o == x->me && n)
			{
				if (x->vrac[(n - 1) + x->in_taille].index < MAX_SYNAPSES_NOEUD)
					{
						k = (n - 1) + x->in_taille ;
					}
			}
		else 
			{
				long i ;
				
				for (i = (x->in_taille + x->out_taille) ; i < x->vrac_taille ; i ++)
					{
						if (ptr_o == x->vrac[i].ptr_o)
							{
								if (x->vrac[i].index < MAX_SYNAPSES_NOEUD)
									{
										k = i ;
									}
								break ;
							}
					}
			}
		
		return k ;
	}

long vrac_getindexbyptr_inlet (t_papa *x, t_object *ptr_o, long n) 
	{
		long k = -1 ;
		
		if (ptr_o == x->me)
			{
				k = n + x->in_taille ;
			}
		else if (ptr_o == x->oscar)
			{
				if (n)
					{
						k = n - 1 ;
					}
			}
		else
			{
				long i ;
				
				for (i = (x->in_taille + x->out_taille) ; i < x->vrac_taille ; i ++)
					{
						if (ptr_o == x->vrac[i].ptr_o)
							{
								k = i ;
								break ;
							}
					}
			}
		
		return k ;
	}

void graf_box_color (t_papa *x, t_object *ptr_b, long n)
	{
		if (ptr_b)
			{
				switch (n) {
					case B_LINEAIRE		:	jbox_set_color (ptr_b, &x->box_b_lineaire) ;
											break ;
					case U_SIGMOIDE		:	jbox_set_color (ptr_b, &x->box_u_sigmoide) ;
											break ;
					case B_TANH			:	jbox_set_color (ptr_b, &x->box_b_tanh) ;
											break ;
					case NUMBER_ERROR	:	jbox_set_color (ptr_b, &x->box_b_error) ;
											break ;
				}
			}
	}
	
long put_fifo (t_papa *x, long n) 
	{
		long k = -1 ;
		
		if (x->fifo && ((x->queue_fifo + 1) != x->head_fifo) && !((x->queue_fifo == (FIFO_TAILLE - 1)) && (x->head_fifo == 0)))
			{
				k = 0 ;
				
				x->fifo[x->queue_fifo] = n ;
				
				if (x->queue_fifo == (FIFO_TAILLE - 1))
					{
						x->queue_fifo = 0 ;
					}
				else
					{
						x->queue_fifo ++ ;
					}
			}
		
		return k ;
	}
	
long get_fifo (t_papa *x)
	{
		long k = -1 ;
		
		if (x->fifo && (x->head_fifo != x->queue_fifo))
			{
				k = 0 ;
				
				x->val_fifo = x->fifo[x->head_fifo] ;
				
				if (x->head_fifo == (FIFO_TAILLE - 1))
					{
						x->head_fifo = 0 ;
					}
				else
					{
						x->head_fifo ++ ;
					}
			}
		
		return k ;
	}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

double myrandom_gaussian (void)
	{
		double x1, x2, w, y ;
 
		do {
				x1	= 2. * ((double)rand () / (double)RAND_MAX) - 1. ;
				x2	= 2. * ((double)rand () / (double)RAND_MAX) - 1. ;
				w	= x1 * x1 + x2 * x2 ;
								
			} while (w >= 1. || w == 0.) ; 

         w	= sqrt ((-2. * log(w)) / w) ;
         y  = x1 * w ;
		 
		 return y * 0.5 ;
	}
		 
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------		
// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x