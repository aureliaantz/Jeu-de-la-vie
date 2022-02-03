/**
 * \file jeu.h
 * \brief Fonctions concernant le jeu
 * \author Antz Aurélia
 */

#ifndef __JEU_H
#define __JEU_H

#include <stdbool.h>

#include "grille.h"

/**
 * \fn static inline modulo(int i,int m)
 * \brief modulo modifié pour traiter correctement les i = 0 et j = 0 dans le calcul des bords cycliques
 * \param i : nombre dont on cherche le modulo
 * \param m : valeur du modulo
 * \return modulo du nombre i
 */
static inline int modulo(int i, int m) {return (i+m)%m;}

/**
 * \fn int compte_voisins_vivants_cyclique(int i,int j,grille g)
 * \brief compte le nombre de voisins vivants de la cellule (i,j), les bords sont cycliques
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par le calcul
 * \return nombre de voisins vivants
 */
int compte_voisins_vivants_cyclique (int i, int j, grille g);

/**
 * \fn int compte_voisins_vivants_non_cyclique(int i,int j,grille g)
 * \brief compte le nombre de voisins vivnats de la cellule (i,j), les bords ne sont pas cycliques
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimansion du tableau de la grille
 * \param g : grille concernée par le calcul
 * \return nombre de voisins vivants
 */
int compte_voisins_vivants_non_cyclique(int i,int j,grille g);

/**
 * \fn int(*compte_voisins_vivants)(int ,int ,grille )
 * \brief pointe vers le calcul du voisinage en cours
 */
int (*compte_voisins_vivants)(int,int,grille);

/**
 * \fn v_actif(grille *g,grille *gc)
 * \brief fait évoluer la grille g d'un pas de temps, vieillissement actif
 * \param g : grille concernée par l'évolution
 * \param gc : grille temporaire (copie de la grille g)
 */
void v_actif(grille *g,grille *gc);

/**
 * \fn v_inactif(grille *g,grille *gc)
 * \brief fait évoluer la grille g d'un pas de temps, vieillissement inactif
 * \param g : grille concernée par l'évolution
 * \param gc : grille temporaire (copie de la grille g)
 */
void v_inactif(grille *g,grille *gc);

/**
 * \fn void (*evolue)(grille *g,grille *gc)
 * \brief fait évoluer la grille g d'un pas de temps
 */
void (*evolue)(grille *g, grille *gc);

/**
 * \fn bool vivante_grille(grille g)
 * \brief renvoie true si au moins une cellule est vivante dans la grille g
 * \param g grille concernée par l'analyse
 */
bool vivante_grille(grille g);

/**
 * \fn bool comparaison_grille(grille g, grille gc)
 * \brief renvoie true si la grille g et gc sont identiques et false si elle ne le sont pas ou si il n'y a aucune cellules vivantes
 * \param g comparaison avec la grille g
 * \param gc comparaison avec la grille gc
 */
bool comparaison_grille(grille g, grille gc);

/**
 * \fn int periode_grille(grille g, int limite)
 * \brief La grille oscille à partir de sa configuration ou après un certian délai
 * \param g grille oscillant ou non
 * \param limite grille oscillant jusqu'à une valeur limite
 */
int periode_grille(grille g, int limite);

#endif
