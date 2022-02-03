/**
 * \file io.h
 * \brief Fonctions concernant l'affichage
 * \author Antz Aurélia
 */
#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"


/**
 * \fn void affiche_temps_evolution(grille g)
 * \brief affichage du temps d'évolution de la grille
 * \param g : grille concernée par l'évolution
 */
void affiche_temps_evolution(grille g);

/**
 * \fn void affiche_voisinage_cyclique()
 * \brief affiche si le voisinage est cyclique
 */
void affiche_voisinage_cyclique();

/**
 * \fn void affiche_vieillissement()
 * \brief affiche si le vieillissement des cellules est actif
 */
void affiche_vieillissement();

/**
 * \fn void affiche_oscillation(grille g);
 * \brief Affiche le nommbre d'oscillation d'une grille possible à partir de sa position ou d'un certain délai
 * \param g nombre d'oscillation de la grille à afficher
 */
void affiche_oscillation(grille g);

/**
 * \fn void affiche_trait(int c)
 * \brief affichage d'un trait horizontal
 * \param c : nombre de colonne de la grille
 */
void affiche_trait (int c);

/**
 * \fn void affiche_ligne(int c,int* ligne)
 * \brief affichage d'une ligne de la grille
 * \param c : nombre de colonnes de la grille
 * \param l : nombre de lignes de la grille
 */
void affiche_ligne (int c, int* ligne);


/**
 * \fn void affiche_grille(grille g)
 * \brief affichage d'une grille
 * \param g : grille à afficher
 */
void affiche_grille (grille g);

/**
 * \fn void efface_grille(grille g)
 * \brief effacement d'une grille
 * \param g : grille à effacer
 */
void efface_grille (grille g);

/**
 * \fn void debut_jeu(grille *g,grille *gc)
 * \brief debute le jeu
 * \param g : grille initiale
 * \param gc : grille temporaire
 */
void debut_jeu(grille *g, grille *gc);

#endif
