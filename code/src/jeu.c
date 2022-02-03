#include "jeu.h"

int compte_voisins_vivants_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v; 
}

int compte_voisins_vivants_non_cyclique(int i,int j,grille g){
	int v = 0;

	if((i-1 >= 0) && (j-1 >= 0)){
		v += est_vivante(i-1,j-1,g);
	}
	if(i-1 >= 0){
		v += est_vivante(i-1,j,g);
	}
	if((i-1 >= 0) && (j+1 < g.nbc)){
		v += est_vivante(i-1,j+1,g);
	}
	if(j-1 >= 0){
		v += est_vivante(i,j-1,g);
	}
	if(j+1 < g.nbc){
		v += est_vivante(i,j+1,g);
	}
	if((i+1 < g.nbl) && (j-1 >= 0)){
		v += est_vivante(i+1,j-1,g);
	}
	if(i+1 < g.nbl){
		v += est_vivante(i+1,j,g);
	}
	if((i+1 < g.nbl) && (j+1 < g.nbc)){
		v += est_vivante(i+1,j+1,g);
	}

	return v;
}

void v_actif (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
			v = compte_voisins_vivants (i, j, *gc);
			if ((est_vivante(i,j,*g))) 
			{ // evolution d'une cellule vivante
				if ( ((v!=2) && (v!= 3)) || (g->cellules[i][j] >= 8))
					set_morte(i,j,*g);
				else g->cellules[i][j]++;
			}
			else 
			{ // evolution d'une cellule morte
				if ((v==3) && (!est_non_viable(i,j,*g))) set_vivante(i,j,*g);
			}
		}
	}
	g->age++; //incrémentation du temps d'évolution
	return;
}

void v_inactif(grille *g,grille *gc){
	copie_grille(*g,*gc); //copie temporaire de la grille
	int i;
	int j;
	int l = g->nbl;
	int c = g->nbc;
	int v;

	for(i = 0;i < l;i++){
		for(j = 0;j < c;++j){
			v = compte_voisins_vivants(i,j,*gc);
			if((est_vivante(i,j,*g))){ //evolution d'une cellule vivante
				if((v!=2) && (v!=3)) set_morte(i,j,*g);
			}
			else
			{ //evolution d'une cellule morte
				if ((v==3) && (!est_non_viable(i,j,*g))) set_vivante(i,j,*g);
			}
		}
	}
	g->age++; //incrémentation du temps d'évolution
	return;
}

bool vivante_grille (grille g){
	int i;
	int j;

	for(i = 0;i < g.nbl;i++)
		for(j = 0 ;j < g.nbc;j++)
			if(est_vivante(i, j, g)) return true;
	return false;
}

bool comparaison_grille (grille g, grille gc){

	if(vivante_grille(gc)){
		int i;
		int j;
		for(i = 0;i < g.nbl;i++){
			for(j = 0;j < g.nbc;j++){
				if(g.cellules[i][j] != gc.cellules[i][j]) return false;
			}
		}
		return true;
	}
	return false;
}


int periode_grille (grille g, int limite)
{
	grille gc;
	grille gcc;
	grille tmp;

	alloue_grille(g.nbl, g.nbc, &gc);
	alloue_grille(g.nbl, g.nbc, &gcc);
	alloue_grille(g.nbl, g.nbc, &tmp);

	copie_grille(g, gc);
	copie_grille(g, gcc);
	copie_grille(g, tmp);

	int i = 0;
	int j = 0;
	int periode = 0;

	while((i < limite) && (periode == 0)){
		while((j < (limite - i)) && (periode == 0)){
			evolue(&gcc, &tmp);
			j++;
			if(comparaison_grille(gc, gcc))periode = j;
		}

		i++;
		j = 0;
		evolue(&gc, &gcc);
		copie_grille(gc, gcc);
	}
	
	libere_grille(&gc);
	libere_grille(&gcc);
	libere_grille(&tmp);

	return periode;
}