#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--------Ici les objets sont generes de maniere aleatoire ------*/


int main(int argc, char **argv)
{
	int lc,hc,n,i,lo,ho; /* lc : largeur du conteneur hc : hauteur du conteneur lo : largeur objet ho : hauteur objet n : nombre d'objets */ 
	if(argc!=6)
	{
		fprintf(stderr,"\n%s [largeur_conteneur] [hauteur_conteneur] [nbre_objets] [largeur_Objets] [hauteur_Objets]\n",argv[0]);
		return 1;
	}	
	lc=atoi(argv[1]);
	hc=atoi(argv[2]);
	n=atoi(argv[3]);
	lo=atoi(argv[4]);
	ho=atoi(argv[5]);
	printf("%d %d\n\n",lc, hc);
	printf("%d\n",n);
	srand(time(0));
	
	for(i=0;i<n;i++)
	{
		printf("OBJET%d %d %d\n",i,rand()%lo+1,rand()%ho+1);
	}	
	
	return 0;
}	
