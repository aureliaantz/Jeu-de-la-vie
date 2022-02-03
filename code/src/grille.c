#include "grille.h"


void alloue_grille(int l,int c,grille* g){
	g->age = 0;
	g->nbl = l;
	g->nbc = c;
	int i;
	int j;
	g->cellules = (int**)malloc(l*sizeof(int*));
	for(i = 0;i < l;i++){
		g->cellules[i] = (int*)malloc(c*sizeof(int));
		for(j = 0;j < c;j++){
			g->cellules[i][j] = 0;
		}
	}
}

void libere_grille(grille* g){
	int i = 0;
	for(;i < g->nbl;i++){
		free(g->cellules[i]);
	}
	free(g->cellules);
}

void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);
	
	int i,j,n,k,l,c,vivantes = 0,viables = 0;
	
	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);
	
	alloue_grille(l,c,g);
	
	fscanf(pfile, "%d", & vivantes);
	for (n=0; n< vivantes; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}

	fscanf(pfile,"%d",&viables);
	for(k = 0;k < viables;++k){
		fscanf(pfile,"%d",&i);
		fscanf(pfile,"%d",&j);
		set_non_viable(i,j,*g);
	}
	
	fclose (pfile);
	return;
}


void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;	
}
