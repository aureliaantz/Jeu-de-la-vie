/**
 * \file grille.h
 * \brief Fonctions concernant la grille
 * \author Antz Aurélia
 */

#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * \struct grille
 * \brief Structure de la grille : nombres de lignes, nombres de colonnes, tableau de tableau de cellules
 * \param nbl : nombre de lignes
 * \param nbc : nombre de colonnes
 * \param cellules : tableau de cellules à deux dimensions
 * \param age : temps d'évolution
 */ 
typedef struct {int nbl; int nbc; int** cellules; int age;} grille;
 
/**
 * \fn void alloue_grille(int l,int c,grille* g)
 * \brief alloue une grille de taille l*c et initialise toutes les cellules à mortes
 * \param l : nombre de lignes
 * \param c : nombre de colonnes
 * \param g : grille à allouer
 */ 
void alloue_grille (int l, int c, grille* g);

/**
 * \fn void libere_grille(grille* g)
 * \brief libère une grille
 * \param g : grille à libérer
 */
void libere_grille (grille* g);

/**
 * \fn void init_grille_from_file(char* filename,grille* g)
 * \brief alloue et initialise la grille g à partir d'un fichier
 * \param filename : chemin du fichier contenant la grille
 * \param g : grille à initialiser à partir de filename
 */
void init_grille_from_file (char * filename, grille* g);

/**
 * \fn static inline void set_non_viable(int i,int j,grille g)
 * \brief rend la vellule non viable
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par la modification
 */
static inline void set_non_viable(int i,int j,grille g){g.cellules[i][j] = -1;}

/**
 * \fn static inline void set_vivante(int i,int j,grille g)
 * \brief rend vivante la cellule (i,j) de la grille g
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par la modification
 */
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}

/**
 * \fn static inline void set_morte(int i,int j,grille g)
 * \brief rend morte la cellule (i,j) de la grille g
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par la modification
 */
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/**
 * \fn static inline est_vivante(int i,int j,grille g)
 * \brief teste si la cellule (i,j) de la grille g est vivante
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par le test
 * \return retourne 1 si la cellule est vivante
 */
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] >= 1;}

/**
 * \fn static inline int est_non_viable(int i,int j,grille g)
 * \brief test si la cellule est non viables
 * \param i : indice de la première dimension du tableau de la grille
 * \param j : indice de la seconde dimension du tableau de la grille
 * \param g : grille concernée par la modification
 */
static inline int est_non_viable(int i,int j,grille g){return g.cellules[i][j] == -1;}

/**
 * \fn void copie_grille(grille gs,grille gd)
 * \brief recopie la grille gs dans la grille gd (sans allocation)
 * \param gs : grille à copier
 * \param gd : grille copiée
 */
void copie_grille (grille gs, grille gd);

#endif
