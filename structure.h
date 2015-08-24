#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>

int n; /* nombre total d'objets lus */
int lc; /*largeur du conteneur */
int hc; /*hauteur du conteneur */
int prof; /* profondeur de remplissage */
int LARG; /* Dimension maximale des objets */

typedef struct OBJET * LISTE;
struct OBJET  /* structure objet */
{
  char *nom; /* nom de l'objet*/
  int l; /*largeur de l'objet */
  int h; /* hauteur de l'objet */
  int surface; /*surface de l'objet */
};

int * NoFree; /* tableau de boolean qui montre la disponibilité des objets 0 si disponible 1 sinon selon l'indice correspondant a l'objet*/
int *num_Bande; /* tableau contenant les numéro de bande pour chaque objet à la profondeur courante */
int *rang; /* tableau contenant les rangs d'entré dans les bande pour chaque objet à la profondeur courante */

LISTE *Objet;

void Pivoter(LISTE O); /* fonction qui permet de pivoter les objets */
LISTE CreerObjet(char *nom,int l,int h); /* cette fonction permet d'allouer les objets en fonction des données lues*/

typedef struct COORDONNEE * coordonnee; 

struct COORDONNEE /* cette structure est utile pour le calcul des coordonnées lors de la sauvegarde des objets*/
{
	int x,y;
};

coordonnee *coord;

typedef struct CONTENEUR * LISTEC ;

struct CONTENEUR /* structure qui permet de sauvegarder les objets */
{
	int lc;
	int hc;
	int surface;
	LISTE *contenu;
	int *Free;
	int *num_Bande;
	int *rang;
	coordonnee *coord;
};

LISTEC Meilleur;






#endif
