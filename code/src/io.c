#include "io.h"

int cyclique = 1; // par défaut le voisinage est cyclique
int viellessement = 0; // par défaut le vieillesement est inactif
int limite_user = -1;
int oscillation = -1;

void affiche_temps_evolution(grille g){
	printf("Temps d'évolution : %d",g.age);
}

void affiche_voisinage_cyclique(){
	if(cyclique){
		printf("\nVoisinage cyclique : Actif");
	}
	else{
		printf("\nVoisinage cyclique : Inactif");
	}
}

void affiche_vieillissemnt(){
	if(viellessement){
		printf("\nVieillissement : Actif");
	}
	else{
		printf("\nVieillissement : Inactif");
	}
}

void affiche_oscillation(grille g){

	if(limite_user == -1 && oscillation == -1)
		printf("\nOscillation  : ");

	else if(limite_user >= 0){
		oscillation = periode_grille(g, limite_user);
		printf("\nOscillation : %d", periode_grille(g, limite_user));
		limite_user = -1;
	}
	
	else if(limite_user == -1 && oscillation >= 0)
		printf("\nOscillation : %d", oscillation);
	
}

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne){
	int i;
	for (i=0; i<c; ++i) 
		if (ligne[i] == 0 ) printf ("|   ");
		else if(ligne[i] == -1) printf("| X "); 
		else printf ("| %d ",ligne[i]);
	printf("|\n");
	return;
}

void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc;
	affiche_temps_evolution(g);
	affiche_voisinage_cyclique();
	affiche_vieillissemnt();
	affiche_oscillation(g);
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}

void efface_grille (grille g){
	printf("\n\e[%dA\x1b[J",g.nbl*2 + 5 + 4); //on ajoute 4 pour supprimmer les affichages du vieillisement, du temps d'évolution, du cyclisme de la grille et de son oscillation
}

void debut_jeu(grille *g, grille *gc){
	char c = getchar();
	compte_voisins_vivants = compte_voisins_vivants_cyclique;
	evolue = v_inactif;
	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) {
			case '\n' : 
			{ // touche "entree" pour évoluer
				evolue(g,gc);
				efface_grille(*g);
				affiche_grille(*g);
				break;
			}

			case 'n': //charge une nouvelle grille
			{	//efface les grilles précédentes et libère la mémoire
				efface_grille(*g);
				libere_grille(g);
				libere_grille(gc);

				//choix de la nouvelle grille
				char* nouv_grille = malloc(30*sizeof(char));
				printf("Nom de la nouvelle grille : ");
				scanf("%s",nouv_grille);

				//chargement et affichage de la nouvelle grille
				init_grille_from_file(nouv_grille,g);
				free(nouv_grille);
				affiche_grille(*g);
				g->age = 0;
				break;
			}

			case 'c':
			{
				if (compte_voisins_vivants == compte_voisins_vivants_cyclique){
					compte_voisins_vivants = compte_voisins_vivants_non_cyclique;
					cyclique--;
				}
				else{
					compte_voisins_vivants = compte_voisins_vivants_cyclique;
					cyclique++;
				}
				break;
			}

			case 'v':
			{
				if(evolue == v_inactif){
					evolue = v_actif;
					viellessement++;
				}
				else{
					evolue = v_inactif;
					viellessement--;
				}
				break;
			}

			case 'o':
			{
				efface_grille(*g);
				printf("Limite du nombre de période : ");
				scanf("%d",&limite_user);
				affiche_grille(*g);
				break;
			}
			
			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}
