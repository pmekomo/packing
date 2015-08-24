#ifndef REMPLIR_CONTENEUR_H
#define REMPLIR_CONTENEUR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Lecture.h"
#include "sac_a_dos.h"

extern int n;
extern int lc;
extern int hc;

void relacher_objets (void); /* relache les objets */

int max_dimension(void); /* cette fonction calcul la dimension maximale et d'affecter celle_ci à la variable LARG de structure.h*/

int ** Sauvegarde(int *in,int *bande,int *Rg); /* qui permet de sauvegarder les meilleurs objets dans une pile */ 

void affichageSolution(int **Pile,LISTE *contenu,int *in,int *bande,int *Rg,coordonnee *cd);  /* qui affiche la solution finale*/

int Est_Valide(LISTE O,int l,int i); /* teste si l'objet rentre dans la bande */
int selectionner_k_largeurs_valides(int k,int L,int **Largeur,int **Occ_largeur); /* selectionne k largeurs valides et alloue le tableau d'occurence des largeurs */
int Max(int **Occ_largeur,int k); /* selection la largeur qui a le plus d'occurences */

void remplir_bande(int e,int **Occ_largeur,int H); /* permet de remplir les bandes */

int propriete_de_coupure(int L); /* permet de calculer les differentes proprietes de coupure et retourne un boolean quand l'une d'elle est vérifiée */

LISTEC mettre_a_jour_meilleur_remplissage(int L,int H,int volume); /* permet de mettre à jour le meilleur remplissage */

void remplir_conteneur(int L,int H,int k,int **Largeur,int **Occ_largeur,int *p,int *V,int option); /* permet de remplir le conteneur */

int surface_occupe_courante (void); /* calcule la surface courante */

int recherche (int **Largeur,int l,int k); /*pour vérifier qu'une largeur n'apparait pas plusieurs fois*/

/* Données pour le sac à dos */

int **Matrice_Sac; /*Matrice utilisée pour calculer le meilleur remplissage par sac à dos*/

#endif
