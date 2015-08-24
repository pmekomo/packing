#ifndef _DESSINER_SOLUTION_
#define _DESSINER_SOLUTION_

typedef struct obj OBJET;
struct obj {
	char nom[80];
	int x,y;
	int l, h;
};

OBJET **Obj_Solution;
int nb_obj, largeur_conteneur, hauteur_conteneur;

void Read ();
OBJET** AllouerOBJET ();
void win1_redessiner (Window win);
void win1_event (Ez_event *ev) ;


#endif  /* _DESSINER_SOLUTION_ */
