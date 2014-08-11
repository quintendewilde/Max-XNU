/*		
	Papa/Oscar !

	variation autour d'un rŽseau de neurones ;
	d'aprs "RŽseaux neuronaux" de Jean-philippe Rennard.

	Version / 1 Aožt 2010.
*/

// -------------------------------------------------------------------------------------------------------------

#include "ext.h"							
#include "ext_obex.h"

// -------------------------------------------------------------------------------------------------------------

#define	DEF_IN_TAILLE 4
#define MAX_IN_TAILLE 128

// -------------------------------------------------------------------------------------------------------------

typedef struct _oscar {
	t_object	ob ;
	t_object	*papa ;
	long		in_taille ;
	void		*m_out[MAX_IN_TAILLE] ;
	} t_oscar ;
	
// -------------------------------------------------------------------------------------------------------------	
	
void	*oscar_new				(t_symbol *s, long argc, t_atom *argv) ;
void	oscar_free				(t_oscar *x) ;
void	oscar_assist			(t_oscar *x, void *b, long m, long a, char *s) ;

void	oscar_list				(t_oscar *x, t_symbol *s, long argc, t_atom *argv) ;
void	oscar_learn				(t_oscar *x, t_symbol *s, long argc, t_atom *argv) ;
void	oscar_target			(t_oscar *x, t_symbol *s, long argc, t_atom *argv) ;
void	oscar_dump				(t_oscar *x) ;
void	oscar_clear				(t_oscar *x) ;

void	oscar_biais				(t_oscar *x, double f) ;
void	oscar_threshold			(t_oscar *x, double f) ;
void	oscar_apprentissage		(t_oscar *x, double f) ;
void	oscar_papa_transfert	(t_oscar *x, long n) ;
void	oscar_oscar_transfert	(t_oscar *x, long n) ;

void	oscar_set_papa	(t_oscar *x, t_object *ptr) ;

// -------------------------------------------------------------------------------------------------------------

static t_class *oscar_class ;

int main (void)
	{	
		t_class *c = NULL ;
		
		c = class_new ("oscar", (method)oscar_new, (method)oscar_free, (long)sizeof(t_oscar), 0L, A_GIMME, 0) ;
		
		class_addmethod (c, (method)oscar_assist,			"assist", A_CANT, 0) ;
		class_addmethod (c, (method)oscar_list,				"list", A_GIMME, 0) ;
		class_addmethod (c, (method)oscar_learn,			"learn", A_GIMME, 0) ;
		class_addmethod (c, (method)oscar_target,			"target", A_GIMME, 0) ;
		class_addmethod (c, (method)oscar_dump,				"dump_max", 0) ;
		class_addmethod (c, (method)oscar_clear,			"clear", 0) ;
		class_addmethod (c, (method)oscar_set_papa,			"set_papa", A_CANT, 0) ;
		class_addmethod (c, (method)oscar_biais,			"biais", A_FLOAT, 0) ;
		class_addmethod (c, (method)oscar_threshold,		"threshold", A_FLOAT, 0) ;
		class_addmethod (c, (method)oscar_apprentissage,	"apprentissage", A_FLOAT, 0) ;
		class_addmethod (c, (method)oscar_papa_transfert,	"papa_transfert", A_LONG, 0) ;
		class_addmethod (c, (method)oscar_oscar_transfert,	"oscar_transfert", A_LONG, 0) ;
		
		class_register (CLASS_BOX, c) ; 
		
		oscar_class = c ;
		
		return 0 ;
	}

void *oscar_new (t_symbol *s, long argc, t_atom *argv)
	{
		t_oscar *x = NULL;
		
		if (x = (t_oscar *)object_alloc (oscar_class)) 
			{	
				long i ;
				 
				x->papa			= NULL ;
				x->in_taille	= DEF_IN_TAILLE ;
				
				if (argc)
					{
						if (atom_gettype (argv) == A_LONG)
							{
								long k = atom_getlong (argv) ;
								
								if (k > 0 && k <= MAX_IN_TAILLE)
									{
										x->in_taille = k ;
									}
							}
					}
												
				attr_args_process (x, argc, argv) ;
		
				for (i = 0 ; i < x->in_taille ; i++)
					{
						x->m_out[i] = outlet_new ((t_object *)x, NULL) ;
					}
				
				for (i = 0 ; i < x->in_taille ; i++)
					{
						inlet_new (x, NULL) ; 
					}
			}
				
		return x ;
	}

void oscar_free (t_oscar *x)
	{ 
		;
	}

void oscar_assist (t_oscar *x, void *b, long m, long a, char *s)
	{
		if (m == ASSIST_INLET) 
			{ 
				if (!a)
					{
						sprintf (s, "(list) clear dump_max learn target") ;
					}
				else
					{
						sprintf (s, "(nothing)") ;
					}
			} 
		else
			{ 
				sprintf (s, "(nothing)") ;
			}
	}

// -------------------------------------------------------------------------------------------------------------
		
void oscar_list (t_oscar *x, t_symbol *s, long argc, t_atom *argv)
	{	
		if (x->papa)
			{
				object_method_typed (x->papa, gensym ("list"), argc, argv, NULL) ;
			}
	}

void oscar_learn (t_oscar *x, t_symbol *s, long argc, t_atom *argv)
	{	
		if (x->papa)
			{
				object_method_typed (x->papa, gensym ("learn"), argc, argv, NULL) ;
			}
	}

void oscar_target (t_oscar *x, t_symbol *s, long argc, t_atom *argv)
	{	
		if (x->papa)
			{
				object_method_typed (x->papa, gensym ("target"), argc, argv, NULL) ;
			}
	}
	
void oscar_dump (t_oscar *x)
	{	
		if (x->papa)
			{
				object_method (x->papa, gensym ("dump_max")) ;
			}
	}

void oscar_clear (t_oscar *x)
	{	
		if (x->papa)
			{
				object_method (x->papa, gensym ("clear")) ;
			}
	}

// -------------------------------------------------------------------------------------------------------------

void oscar_biais (t_oscar *x, double f)
	{
		if (x->papa)
			{
				object_attr_setfloat (x->papa, gensym ("biais"), f) ;
			}
	}

void oscar_threshold (t_oscar *x, double f)
	{
		if (x->papa)
			{
				object_attr_setfloat (x->papa, gensym ("threshold"), f) ;
			}
	}

void oscar_apprentissage (t_oscar *x, double f)
	{
		if (x->papa)
			{
				object_attr_setfloat (x->papa, gensym ("apprentissage"), f) ;
			}
	}

void oscar_papa_transfert (t_oscar *x, long n)
	{
		if (x->papa)
			{
				object_attr_setlong (x->papa, gensym ("papa_transfert"), n) ;
			}
	}

void oscar_oscar_transfert (t_oscar *x, long n)
	{
		if (x->papa)
			{
				object_attr_setlong (x->papa, gensym ("oscar_transfert"), n) ;
			}
	}

// -------------------------------------------------------------------------------------------------------------

void oscar_set_papa (t_oscar *x, t_object *ptr)
	{
		x->papa = ptr ;
	}
	
// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x