/* INF24 PROJET PACKING
 *
 * Dessiner avec ez-draw la solution donnée par le programme packing
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ez-draw.h"
#include "dessiner_solution.h"

int main () {
    Window win1;
    
    Read();
    
    if (ez_init() < 0) 
		exit(1);
    
    win1 = ez_window_create (1000, 600, "Packing : dessin du meilleur remplissage", win1_event);

    ez_main_loop ();
    
    return EXIT_SUCCESS;
}

/** 
   Dessiner graphiqument les solutions du meilleur remplissage
*/
void win1_redessiner (Window win) {
	int i;

	/* Affichage des caractéristiques des solutions */
	ez_set_nfont (2);
	ez_draw_text (win, EZ_TL, 0, 0, "Largeur du conteneur : %d\nHauteur du conteneur : %d\nNombre d'objets : %d",largeur_conteneur, hauteur_conteneur, nb_obj);
	for(i = 0; i < nb_obj; i++)
		ez_draw_text (win, EZ_TL, 0, 70 + 20*i, "%s %d %d %d %d\n", Obj_Solution[i]->nom, Obj_Solution[i]->l, Obj_Solution[i]->h, Obj_Solution[i]->x, Obj_Solution[i]->y);
	
	
	/* Dessin du conteneur */
	ez_set_color (ez_black);
	ez_set_thick (5);
	ez_draw_rectangle (win, 300, 10, 300 + 4*largeur_conteneur, 10 +  4*hauteur_conteneur);
	
	/* Dessin des objets */
	for(i = 0; i < nb_obj; i++) {
		ez_set_color (ez_get_RGB (ez_random(256), ez_random(256) , ez_random(256)));
		ez_fill_rectangle (win,  300 + 4*Obj_Solution[i]->x, 10 + 4*Obj_Solution[i]->y, 300 + 4*Obj_Solution[i]->l + 4*Obj_Solution[i]->x ,10 + 4*Obj_Solution[i]->h + 4*Obj_Solution[i]->y);
		ez_set_color(ez_black);
		ez_set_thick (2);
		ez_draw_rectangle (win, 300 + 4*Obj_Solution[i]->x, 10 + 4*Obj_Solution[i]->y, 300 + 4*Obj_Solution[i]->l + 4*Obj_Solution[i]->x , 10 + 4*Obj_Solution[i]->h + 4*Obj_Solution[i]->y);
		ez_set_nfont (0);
		ez_draw_text (win, EZ_TL, 302 + 4*Obj_Solution[i]->x, 10 + 4*Obj_Solution[i]->y, "%s", Obj_Solution[i]->nom);
	}
}

void win1_event (Ez_event *ev)        /* Appelée à chaque evenement sur win1 */
{
    switch (ev->type) {
    
        case Expose :                              /* Il faut tout redessiner */
            win1_redessiner (ev->win);
            break;
   
        case KeyPress :                           /* Une touche a ete pressee */
            switch (ev->key_sym) {
            case XK_q : ez_quit (); break;
            }
            break;
    }
}

/**
   Lire les solutions, les stocker.
*/
void Read ()
{
	int i;
	printf("----L%d In Read() :\n", __LINE__);
	/* Lit les solutions, en vérifiant que la lecture n'échoue pas. */
	if(scanf("%d %d", &largeur_conteneur, &hauteur_conteneur) != 2) { printf("----L%d In Read() :\n", __LINE__);
		fprintf(stderr, "Read : erreur lors de la lecture des objets mis dans le conteneur. Abandon\n");		/* mettre argv[0] partout où il faut. */
		exit(EXIT_FAILURE);
	}
	
	/* Lit le nombre d'objets du remplissage. */	
	if(scanf("%d", &nb_obj) != 1) {		printf("----L%d In Read() :\n", __LINE__);			
		fprintf(stderr, "Read : erreur lors de la lecture des objets mis dans le conteneur. Abandon\n");
		exit(EXIT_FAILURE);
	}
	printf("\tDans Read : nb_obj = %d objets mis dans le conteneur stocké par Read\n", nb_obj);
	/* Allocation de Obj_Solution, qui est un tableau de structures OBJET, et qui contiendra tous les objets du remplissage */
	Obj_Solution = AllouerOBJET();
	
	/* Lit les noms et tailles des objets, et les stocke dans les champs correspondant de Obj_Solution. */
	for(i = 0; i < nb_obj; i++) {
		if(scanf("%s %d %d %d %d", Obj_Solution[i]->nom, &Obj_Solution[i]->l, &Obj_Solution[i]->h,
		                                                 &Obj_Solution[i]->x, &Obj_Solution[i]->y) != 5) {printf("----L%d In Read() :\n", __LINE__);
			fprintf(stderr, "Read : erreur lors de la lecture des objets mis dans le conteneur. Abandon\n");
			exit(EXIT_FAILURE);
		}
	}
		
	/* Vérification des données stockées : */
	printf("Largeur du conteneur: %d, Hauteur du conteneur : %d\nNombre d'objets mis dans le conteneur: %d\nListe des objets :\n", largeur_conteneur, hauteur_conteneur, nb_obj);
	for(i = 0; i < nb_obj; i++)
		printf("  %s %d %d %d %d\n", Obj_Solution[i]->nom, Obj_Solution[i]->l, Obj_Solution[i]->h, Obj_Solution[i]->x, Obj_Solution[i]->y);
		
	printf("\tRead exécutée sans problèmes\n");
}

OBJET** AllouerOBJET () {
	OBJET **Bison = NULL;
	int i;

	/* Allocation dynamique de Bison (liste vers <nb_obj> structures OBJET). */
	Bison = malloc(nb_obj * sizeof(OBJET*));
	assert(Bison != NULL);
	for(i = 0; i < nb_obj; i++)
		Bison[i] = NULL;
		
	for(i = 0; i < nb_obj; i++) {	
		Bison[i] = malloc(sizeof(OBJET));
		assert(Bison[i] != NULL);
	}

	return Bison;
}
