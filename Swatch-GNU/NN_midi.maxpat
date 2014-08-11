{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 522.0, 215.0, 416.0, 385.0 ],
		"bglocked" : 0,
		"defrect" : [ 522.0, 215.0, 416.0, 385.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 14.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 20.0, 20.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "dump_max",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 300.0, 180.0, 80.0, 21.0 ],
					"id" : "obj-48",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "metro 250",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 200.0, 80.0, 74.0, 23.0 ],
					"id" : "obj-10",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 40.0, 40.0, 20.0, 20.0 ],
					"id" : "obj-24"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p DUKE",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 40.0, 80.0, 61.0, 23.0 ],
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 336.0, 89.0, 372.0, 603.0 ],
						"bglocked" : 0,
						"defrect" : [ 336.0, 89.0, 372.0, 603.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend learn",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 200.0, 480.0, 97.0, 23.0 ],
									"id" : "obj-5",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend target",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 480.0, 102.0, 23.0 ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl slice 2",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 20.0, 420.0, 64.0, 23.0 ],
									"id" : "obj-3",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl group 6",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 20.0, 360.0, 72.0, 23.0 ],
									"id" : "obj-7",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 20.0, 560.0, 25.0, 25.0 ],
									"id" : "obj-2",
									"comment" : "(symbol)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"comment" : "(bang)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "88 67 72 76 83 81 79 66 72 76 80 88 76 72 67 83 81 79 66 80 72 76 80 66 76 72 76 60 64 55 71 69 67 54 60 68 64 76 60 64 55 71 69 67 68 70 63 53 59 36 64 62 57 67 38 40 43 55 47 64 50 43 48 55 60 45 50 64 56 45 40 39 38 40 38 41 55 56 54 42 43 57 53 31 43 31 58 59 43 64 43 55 54 53 42 62 61 41 59 40 60 46 40 45 64 69 39 67 66 38 65 42 76 74 43 72 68 63 59 53 37 36 57 52 67 62 38 40 58 50 65 51 43 66 61 59 52 62 60 67 48 60 70 67 76 71 43 48 52 67 59 62 60 49 57 72 67 64 50 76 66 60 71 54 68 63 60 64 45 40 39 33 38 57 33 66 72 64 56 40 71 72 57 41 71 76 66 60 57 72 63 52 59 68 42 69 53 64 60 43 31 43 31 31 53 69 70 54 43 55 71 59 76 31 67 64 63 66 65 62 31 74 60 58 64 43 69 72 60 61 31 70 62 79 76 69 36 79 43 81 70 84 76 81 62 31 36 61 70 76 84 80 43 42 41 80",
									"linecount" : 16,
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 60.0, 324.0, 262.0 ],
									"id" : "obj-10",
									"fontname" : "Arial"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 1 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [ 209.5, 528.0, 29.5, 528.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 14.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 200.0, 120.0, 40.0, 23.0 ],
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 241.0, 108.0, 336.0, 326.0 ],
						"bglocked" : 0,
						"defrect" : [ 241.0, 108.0, 336.0, 326.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 127",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 220.0, 140.0, 85.0, 23.0 ],
									"id" : "obj-3",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 20.0, 280.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack 0 0 0",
									"numinlets" : 3,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 200.0, 219.0, 23.0 ],
									"id" : "obj-8",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b b b",
									"numinlets" : 1,
									"numoutlets" : 3,
									"fontsize" : 14.0,
									"outlettype" : [ "bang", "bang", "bang" ],
									"patching_rect" : [ 20.0, 80.0, 219.0, 23.0 ],
									"id" : "obj-6",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 127",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 120.0, 140.0, 85.0, 23.0 ],
									"id" : "obj-5",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 127",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 20.0, 140.0, 85.0, 23.0 ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"id" : "obj-18",
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 1 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 2 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-8", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-8", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 14.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 200.0, 40.0, 20.0, 20.0 ],
					"id" : "obj-14"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 120.0, 40.0, 20.0, 20.0 ],
					"id" : "obj-2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p SATIE",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 120.0, 80.0, 63.0, 23.0 ],
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 336.0, 89.0, 442.0, 527.0 ],
						"bglocked" : 0,
						"defrect" : [ 336.0, 89.0, 442.0, 527.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend learn",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 200.0, 400.0, 97.0, 23.0 ],
									"id" : "obj-5",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend target",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 400.0, 102.0, 23.0 ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl slice 2",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 20.0, 340.0, 64.0, 23.0 ],
									"id" : "obj-3",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl group 6",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 20.0, 300.0, 72.0, 23.0 ],
									"id" : "obj-7",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 20.0, 480.0, 25.0, 25.0 ],
									"id" : "obj-2",
									"comment" : "(symbol)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"comment" : "(bang)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "64 52 47 59 59 47 55 43 57 45 57 45 54 42 43 55 40 52 38 50 50 38 52 64 59 47 59 47 43 55 45 57 45 57 53 41 43 55 45 57 48 60 48 60 50 62 52 64 55 59 76 88 79 83 50 55 47 59 74 79 71 83 83 71 78 74 47 54 59 50 52 43 55 48 72 79 76 67 48 45 57 52 72 69 81 76 45 52 57 48 72 69 76 81 47 42 54 50 66 74 71 78 43 55 50 47 74 79 67 71 52 48 43 40 72 76 64 67 45 50 38 42 74 69 66 62 42 38 50 45 69 74 62 66 55 59 64 52 88 76 79 83 55 59 47 50 79 74 71 83 54 47 59 50 83 74 78 71 43 55 52 48 79 67 72 76 52 45 48 57 81 72 69 76 57 45 48 52 76 69 72 81 46 50 53 41 74 65 70 77 43 46 50 55 79 67 74 70 45 53 50 57 69 81 74 77 57 60 48 52 72 84 81 76 52 57 48 60 84 72 81 76 62 50 53 57 86 81 77 74",
									"linecount" : 12,
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 60.0, 399.0, 198.0 ],
									"id" : "obj-10",
									"fontname" : "Arial"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-3", 1 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [ 209.5, 448.0, 29.5, 448.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 14.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p MIDI",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 14.0,
					"patching_rect" : [ 140.0, 320.0, 52.0, 23.0 ],
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 764.0, 165.0, 232.0, 516.0 ],
						"bglocked" : 0,
						"defrect" : [ 764.0, 165.0, 232.0, 516.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 12",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 140.0, 300.0, 38.0, 23.0 ],
									"id" : "obj-3",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pipe 375",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 60.0, 160.0, 64.0, 23.0 ],
									"id" : "obj-2",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 380.0, 38.0, 23.0 ],
									"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"patcher" : 									{
										"fileversion" : 1,
										"rect" : [ 356.0, 63.0, 273.0, 330.0 ],
										"bglocked" : 0,
										"defrect" : [ 356.0, 63.0, 273.0, 330.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 14.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 20.0, 20.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "+ 60",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 14.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 60.0, 160.0, 38.0, 23.0 ],
													"id" : "obj-1",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 40",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 14.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 60.0, 120.0, 77.0, 23.0 ],
													"id" : "obj-3",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "+ 50",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 14.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 160.0, 160.0, 38.0, 23.0 ],
													"id" : "obj-10",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 450",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 14.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 160.0, 120.0, 85.0, 23.0 ],
													"id" : "obj-6",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pack 0 0 0",
													"numinlets" : 3,
													"numoutlets" : 1,
													"fontsize" : 14.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 20.0, 220.0, 99.0, 23.0 ],
													"id" : "obj-5",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b b",
													"numinlets" : 1,
													"numoutlets" : 3,
													"fontsize" : 14.0,
													"outlettype" : [ "int", "bang", "bang" ],
													"patching_rect" : [ 20.0, 60.0, 99.0, 23.0 ],
													"id" : "obj-2",
													"fontname" : "Arial"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
													"id" : "obj-14",
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 20.0, 280.0, 25.0, 25.0 ],
													"id" : "obj-15",
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 2 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-5", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-5", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-15", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-5", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 14.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"default_fontsize" : 14.0,
										"fontname" : "Arial"
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 12",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 20.0, 300.0, 35.0, 23.0 ],
									"id" : "obj-21",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "cycle 4",
									"numinlets" : 1,
									"numoutlets" : 4,
									"fontsize" : 14.0,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 20.0, 260.0, 138.5, 23.0 ],
									"id" : "obj-11",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "makenote 90 250 1",
									"numinlets" : 4,
									"numoutlets" : 3,
									"fontsize" : 14.0,
									"outlettype" : [ "float", "float", "float" ],
									"patching_rect" : [ 20.0, 420.0, 138.0, 23.0 ],
									"id" : "obj-8",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pipe 375",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 140.0, 160.0, 64.0, 23.0 ],
									"id" : "obj-13",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "unpack 0 0",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "int", "int" ],
									"patching_rect" : [ 20.0, 80.0, 91.0, 23.0 ],
									"id" : "obj-9",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "noteout",
									"numinlets" : 3,
									"numoutlets" : 0,
									"fontsize" : 14.0,
									"patching_rect" : [ 20.0, 460.0, 138.0, 23.0 ],
									"color" : [ 0.501961, 0.717647, 0.764706, 1.0 ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"comment" : "(list)"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-11", 1 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [ 69.333336, 351.0, 29.5, 351.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 2 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [ 109.166664, 351.0, 29.5, 351.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 1 ],
									"destination" : [ "obj-4", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 2 ],
									"destination" : [ "obj-4", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 3 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [ 149.5, 351.0, 29.5, 351.0 ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 14.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p NN",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.0, 260.0, 42.0, 23.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 219.0, 93.0, 890.0, 618.0 ],
						"bglocked" : 0,
						"defrect" : [ 219.0, 93.0, 890.0, 618.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "[-] is linear.",
									"numinlets" : 2,
									"presentation_rect" : [ 376.0, 139.0, 0.0, 0.0 ],
									"numoutlets" : 1,
									"fontsize" : 16.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 396.0, 228.0, 88.0, 23.0 ],
									"id" : "obj-12",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "-",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 366.0, 199.0, 32.5, 23.0 ],
									"color" : [ 0.92, 0.94, 0.67, 1.0 ],
									"id" : "obj-7",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "double click [papa] to rebuild the NN.",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 16.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 287.0, 491.0, 272.0, 23.0 ],
									"id" : "obj-3",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "[pack] is sigmoide.",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 16.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 168.0, 313.0, 143.0, 23.0 ],
									"id" : "obj-22",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "red line are t - 1 feedback (weight 1.).",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 16.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 562.0, 281.0, 277.0, 23.0 ],
									"id" : "obj-21",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "[+] is used to loop a node with himself.",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 16.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 451.0, 405.0, 282.0, 23.0 ],
									"id" : "obj-20",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 411.0, 343.0, 32.5, 23.0 ],
									"color" : [ 0.92, 0.94, 0.67, 1.0 ],
									"id" : "obj-16",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 358.0, 344.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-13",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 398.0, 304.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-9",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 119.0, 313.0, 40.0, 23.0 ],
									"color" : [ 0.68, 0.82, 0.82, 1.0 ],
									"id" : "obj-8",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "int",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 328.0, 304.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-10",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "int",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 208.0, 244.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-6",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 14.0,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 268.0, 244.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-5",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "int",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 14.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 312.0, 246.0, 32.5, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "papa 2",
									"numinlets" : 2,
									"numoutlets" : 3,
									"fontsize" : 14.0,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 253.0, 390.0, 53.0, 23.0 ],
									"color" : [ 0.83, 0.74, 0.84, 1.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"head_papa_data" : [ 22, 5, 4, 4, 3, 2, 2 ],
									"graf_papa_data" : [ 0, 1, 0, 1, 1, 0, 2, 1, 0, 3, 1, 0, 8, 1, 2, 9, 1, 2, 10, 1, 2, 20, 1, 0, 11, 1, 2, 12, 1, 1, 13, 1, 2, 14, 1, 2, 15, 0, 0, 4, 1, 2, 5, 1, 2 ],
									"synapses_papa_data" : [ 0, 9, 0, -0.023852, 0, 8, 0, -0.083949, 1, 9, 0, 0.654731, 1, 8, 0, -0.117514, 2, 10, 0, 0.483626, 3, 20, 0, 0.376566, 3, 10, 0, -0.174293, 8, 13, 0, -0.244013, 8, 11, 0, 0.387407, 8, 12, 0, 0.202509, 9, 12, 0, -0.079046, 9, 11, 0, -0.28038, 10, 12, 0, -0.118623, 20, 11, 0, -0.77595, 20, 8, 1, 1.0, 11, 4, 0, 0.643543, 11, 5, 0, -0.487816, 11, 14, 0, 0.184042, 12, 4, 0, 0.465315, 12, 5, 0, 0.80445, 12, 10, 1, 1.0, 13, 15, 1, 1.0, 13, 14, 0, 0.627334, 14, 5, 0, 0.678322, 15, 13, 1, 1.0, 5, 3, 1, 1.0 ],
									"saved_object_attributes" : 									{
										"threshold" : 0.0,
										"synapse" : [ 0.62, 0.55, 0.83, 1.0 ],
										"apprentissage" : 1.0,
										"oscar_transfert" : 0,
										"tanh" : [ 0.83, 0.74, 0.84, 1.0 ],
										"papa_transfert" : 2,
										"biais" : 1.0,
										"lineaire" : [ 0.92, 0.94, 0.67, 1.0 ],
										"feedback" : [ 1.0, 0.6, 0.6, 1.0 ],
										"sigmoide" : [ 0.68, 0.82, 0.82, 1.0 ],
										"wrong" : [ 0.85, 0.85, 0.85, 1.0 ],
										"embed" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "oscar",
									"numinlets" : 5,
									"numoutlets" : 4,
									"fontsize" : 14.0,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 248.0, 164.0, 94.5, 23.0 ],
									"color" : [ 0.92, 0.94, 0.67, 1.0 ],
									"id" : "obj-1",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 219.0, 22.0, 25.0, 25.0 ],
									"id" : "obj-11",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 200.0, 561.0, 25.0, 25.0 ],
									"id" : "obj-14",
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.6, 0.6, 1.0 ],
									"midpoints" : [ 436.0, 385.0, 482.0, 312.0, 423.0, 262.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.6, 0.6, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 3 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.6, 0.6, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 2 ],
									"destination" : [ "obj-1", 4 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.6, 0.6, 1.0 ],
									"midpoints" : [ 312.0, 475.0, 544.0, 323.0, 467.0, 133.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"color" : [ 0.85, 0.85, 0.85, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 1 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"color" : [ 0.85, 0.85, 0.85, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 1 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 3 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 2 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"color" : [ 0.62, 0.55, 0.83, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"color" : [ 1.0, 0.6, 0.6, 1.0 ],
									"midpoints" : [ 96.0, 378.0, 68.0, 199.0, 186.0, 184.0 ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 14.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clear",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 14.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 220.0, 160.0, 41.0, 21.0 ],
					"id" : "obj-9",
					"fontname" : "Arial"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
