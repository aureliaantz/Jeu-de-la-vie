#include "io_cairo.h"

int voisinage_cyclique = 1; // cyclique actvié par défaut
int vieillissement = 0; // vieillissement désactivé par défaut
int limite_usr = -1, oscillation = -1;

void affiche_temps_evolution_cairo(cairo_t *cr, grille g)
{
	char age[40];
	sprintf(age, "Temps d'évolution:  %d", g.age);
	cairo_move_to (cr, 80, 450);
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_show_text (cr, age);
}

void affiche_voisinage_cyclique_cairo(cairo_t *cr)
{
	cairo_move_to (cr, 80, 480);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_show_text (cr, "Voisinage cyclique: ");


	cairo_move_to (cr, 280, 480);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

	if(voisinage_cyclique)
	{
		cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
		cairo_show_text (cr, "Actif");
	}
	else
	{
		cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
		cairo_show_text (cr, "Inactif");
	}
}

void affiche_vieillissement_cairo(cairo_t *cr)
{
	cairo_move_to (cr, 80, 510);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_show_text (cr, "Vieillissement: ");


	cairo_move_to (cr, 230, 510);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

	if(vieillissement)
	{
		cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
		cairo_show_text (cr, "Actif");
	}
	else
	{
		cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
		cairo_show_text (cr, "Inactif");
	}
}

void affiche_oscillation_cairo(cairo_t *cr, grille g)
{
	char nb_osc[4];
	cairo_move_to (cr, 80, 540);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_show_text (cr, "Oscillation: ");


	cairo_move_to (cr, 195, 540);
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_set_font_size (cr, 20);
	cairo_select_font_face(cr, "fantasy", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	
	if(limite_usr >= 0){
		oscillation = periode_grille(g, limite_usr);
		sprintf(nb_osc, "%d", periode_grille(g, limite_usr));
		cairo_show_text(cr, nb_osc);
		limite_usr = -1;
	}
	
	else if(limite_usr == -1 && oscillation >= 0){
		sprintf(nb_osc, "%d", oscillation);
		cairo_show_text(cr, nb_osc);
	}
}

void affiche_grille_cairo(cairo_t *cr, grille g)
{
	int i;
	int j;
	int l = g.nbl;
	int c = g.nbc;
	double x = (SIZEY-200)/c;
	double y = (SIZEX)/l; // longueur et largeur d'une case
	char age[4];

	for(i = 0;i < l;i++){
		for(j = 0;j < c;j++){

			//Affichage des cellules vivantes
			if(g.cellules[i][j] >= 1){
				cairo_rectangle(cr,x*j,y*i,x,y);
				cairo_set_source_rgb (cr, 1.0-(g.cellules[i][j]/10.), 1.0-(g.cellules[i][j]/10.), 1.0-(g.cellules[i][j]/10.));
				cairo_fill(cr);

				cairo_move_to (cr, x*j + x*(2/7.), y*i+ (3/4.)*y);
				sprintf(age, "%d", g.cellules[i][j]);

				cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
				cairo_set_font_size (cr, x - x/5);
				cairo_show_text (cr, age);
			}

			//Affichage des cellules non viables
			else if(g.cellules[i][j] == -1){
				cairo_rectangle(cr,x*j,y*i,x,y);
				cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
				cairo_fill(cr);

				cairo_move_to (cr, x*j + x*(2/7.), y*i+ (3/4.)*y);
				cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
				cairo_set_font_size (cr, x - x/5);
				cairo_show_text (cr, "X");
			}
		}
	}

	//Lignes de la grille
	for(i = 0;i <= l;i++){
		cairo_move_to (cr, 0.0, y*i);
		cairo_line_to (cr, x*c, y*i);
	}

	//Colonnes de la grille
	for(j = 0;j <= c;j++){
		cairo_move_to (cr, x*j, 0.0);
		cairo_line_to (cr, x*j, y*l);
	}
	cairo_set_source_rgb (cr, 0.2, 0.2, 0.2);
	cairo_set_line_width (cr, 1);
	cairo_stroke (cr);
}

void paint(cairo_surface_t *surface, grille g)
{
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 0.5, 0.5, 0.5);
	cairo_paint(cr);

	affiche_temps_evolution_cairo(cr, g);
	affiche_voisinage_cyclique_cairo(cr);
	affiche_vieillissement_cairo(cr);
	affiche_oscillation_cairo(cr, g);
	affiche_grille_cairo (cr, g);

	cairo_destroy(cr); // destroy cairo mask
}

void debut_jeu(grille *g, grille *gc){

	compte_voisins_vivants = compte_voisins_vivants_cyclique;
	evolue = v_inactif;

	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;

	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0,
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "Jeu de la vie");
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask);
	XMapWindow(dpy, win);

	// create cairo surface
	cairo_surface_t *cs;
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);

	// run the event loop
	while(1){
		XNextEvent(dpy, &e);
		if(e.type==Expose && e.xexpose.count<1) paint(cs, *g);

		else if(e.type==ButtonPress){
			if(e.xbutton.button == Button1){
				evolue(g, gc);
				paint(cs, *g);
			}
			else if(e.xbutton.button == Button3) break;
		}

		else if(e.type==KeyPress){

			if(e.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym("n"))){

				char* nouv_grille = (char*) malloc(30 * sizeof(char));
				scanf("%s", nouv_grille);

				libere_grille(g);
				libere_grille(gc);

				init_grille_from_file(nouv_grille, g);
				free(nouv_grille);

				paint(cs, *g);
			}

			else if(e.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym("c"))){
				
				if(compte_voisins_vivants == compte_voisins_vivants_cyclique){
					compte_voisins_vivants = compte_voisins_vivants_non_cyclique;
					voisinage_cyclique--;
				}
				
				else{
					compte_voisins_vivants = compte_voisins_vivants_cyclique;
					voisinage_cyclique++;
				}
				paint(cs, *g);
			}

			else if(e.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym("v"))){
				if(evolue == v_inactif)
				{
					evolue = v_actif;
					vieillissement++;
				}
				else
				{
					evolue = v_inactif;
					vieillissement--;
				}
				paint(cs, *g);
			}

			else if(e.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym("o"))){
				printf("Limite du nombre de période : ");
				scanf("%d", &limite_usr);
				paint(cs, *g);
			}
		}

	}
	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
}
