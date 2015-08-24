#include "Lecture.h"

/* cette fonction permet de lire les objets generes et d'appeler la fonction qui les alloue */

void lire(int n)
{
	int l,h,i; /* l: largeur_objet h: hauteur_objet */
	char *nom;
	Objet=malloc(n*sizeof(LISTE));
	assert(Objet!=NULL);
	for(i=0;i<n;i++)
	{
		Objet[i]=malloc(sizeof(struct OBJET));
		assert(Objet[i]!=NULL);
	}
	for(i=0;i<n;i++)
	{
		nom=malloc(100*sizeof(char));
		scanf("%s %d %d",nom,&l,&h);
		Objet[i]=CreerObjet(nom,l,h); /* cette fonction permet d'allouer les objets en fonction des données lues*/
	}

  
}
