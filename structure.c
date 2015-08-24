#include "structure.h"



void Pivoter(LISTE O) 
{
	int pivot;
	pivot=O->l;
	O->l=O->h;
	O->h=pivot;
}

LISTE CreerObjet(char *nom,int l,int h)
{
  LISTE O;
  O=malloc(sizeof(struct OBJET));
  assert(O!=NULL);
  O->nom=nom;
  O->l=l;
  O->h=h;
  O->surface=(O->l*O->h);
  return O;
}
