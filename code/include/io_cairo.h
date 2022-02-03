/**
 * \file io_cairo.h
 * \brief Fonctions concernant l'affichage pour cairo et X11
 * \author Antz Aurélia
 */

#ifndef __IO_CAIRO_H
#define __IO_CAIRO_H

#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>

#include "grille.h"
#include "jeu.h"

#define SIZEX 400
#define SIZEY 600


/**
 * \fn void affiche_temps_evolution_cairo(cairo_t *cr, grille g)
 * \brief Affiche le temps d'évolution de la grille g
 * \param cr mask
 * \param g le cycle de la grille à afficher
 */
void affiche_temps_evolution_cairo(cairo_t *cr, grille g);

/**
 * \fn void affiche_voisinage_cyclique_cairo(cairo_t *cr)
 * \brief Affiche si le voisinage cyclique est activé ou non
 * \param cr mask
 */
void affiche_voisinage_cyclique_cairo(cairo_t *cr);

/**
 * \fn void affiche_vieillissement_cairo(cairo_t *cr)
 * \brief Affiche si le vieillissement des cellules est activé ou non
 * \param cr mask
 */
void affiche_vieillissement_cairo(cairo_t *cr);

/**
 * \fn void affiche_vieillissement_cairo(cairo_t *cr)
 * \brief Affiche le nommbre d'oscillation d'une grille possible à partir de sa position ou d'un certain délai
 * \param cr mask
 * \param g grille concernée
 */
void affiche_oscillation_cairo(cairo_t *cr, grille g);

/**
 * \fn void affiche_grille_cairo(cairo_t *cr, grille g)
 * \brief Affichage d'une grille
 * \param cr mask
 * \param g grille à afficher
 */
void affiche_grille_cairo(cairo_t *cr, grille g);

/**
 * \fn void paint(cairo_surface_t *surface, grille g)
 * \brief Dessine l'ensemble des éléments dans la fenêtre X
 * \param surface surface
 * \param g grille à afficher
 */
void paint(cairo_surface_t *surface, grille g);

/**
 * \fn void debut_jeu(grille *g, grille *gc)
 * \brief Débute le jeu en utilisant le gestionnaire de fenêtres X
 * \param g grille du jeu
 * \param gc grille temporaire
 */
void debut_jeu(grille *g, grille *gc);

#endif