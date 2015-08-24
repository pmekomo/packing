#include "Lecture.h"
#include "remplir_conteneur.h"
#include "sac_a_dos.h"

int main(int argc,char *argv[])
{
	int k,L,H,i,**Pile,**Largeur,**Occ_largeur,*p,*V,opt;
	char a='%',option[3];
	if(argc<2)
	{
		fprintf(stderr,"\nUsage: ./main k [-s]\n");
		return 1;
	}
	else
	{
		
		scanf("%d %d %d",&lc,&hc,&n);
		lire(n);
		k=atoi(argv[1]);
		prof=0;
		Meilleur=malloc(sizeof(struct CONTENEUR));
		Meilleur->contenu=malloc(n*sizeof(LISTE));
		for(i=0;i<n;i++)
		{
			Meilleur->contenu[i]=malloc(sizeof(struct OBJET));
			Meilleur->contenu[i]->nom=malloc(100*sizeof(char));
		}
		Meilleur->Free=malloc(n*sizeof(int));
		Meilleur->num_Bande=malloc(n*sizeof(int));
		Meilleur->rang=malloc(n*sizeof(int));
		Meilleur->coord=malloc(n*sizeof(coordonnee));
		for(i=0;i<n;i++)
			Meilleur->coord[i]=malloc(sizeof(struct COORDONNEE));
		
		Meilleur->surface = 0;
		L=lc;
		H=hc;
		
		LARG=max_dimension();
		Occ_largeur=calloc(n,sizeof(int*));
		for(i=0;i<n;i++)
			Occ_largeur[i]=calloc(k,sizeof(int));
		Largeur=calloc(n,sizeof(int*));
		for(i=0;i<n;i++)
			Largeur[i]=calloc(k,sizeof(int));
		NoFree=calloc(n,sizeof(int));
		num_Bande=calloc(n,sizeof(int));
		rang=calloc(n,sizeof(int));
		
		coord=malloc(n*sizeof(coordonnee));
		for(i=0;i<n;i++)
			coord[i]=malloc(sizeof(struct COORDONNEE));
		
		/* tableaux pour le sac à dos */
		p=malloc( (n+2)*(sizeof(int)) );
		V=malloc( (n+2)*(sizeof(int)) );
		Matrice_Sac=malloc( (n+1)*(sizeof(int*)) ) ;
		for(i=0;i<n+1;i++)
			Matrice_Sac[i]=malloc( (hc+1)*(sizeof(int)) );
		if(argc==3)
		{
			strcpy (option, argv[2]);
			if(strcmp (option,"-s")==0)
			{
				opt=1;
			}
		}
		else opt=0;
		if(opt==1)
		{
			fprintf(stdout,"\n*****REMPLISSAGE PAR L'ALGORITHME DE SAC A DOS******\n");
			remplir_conteneur(L,H,k,Largeur,Occ_largeur,p,V,0);
		}
		else
		{
			fprintf(stdout,"\n*****REMPLISSAGE PAR LA METHODE GLOUTON******\n");
			remplir_conteneur(L,H,k,Largeur,Occ_largeur,p,V,1);
		}
			
		Pile=malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
			Pile[i]=malloc(sizeof(int));
		Pile=Sauvegarde(Meilleur->Free,Meilleur->num_Bande,Meilleur->rang);
		printf("\n");
		affichageSolution(Pile,Meilleur->contenu,Meilleur->Free,Meilleur->num_Bande,Meilleur->rang,Meilleur->coord);
		
		printf("\n remplissage à :%.2f%c\n",(double)100*Meilleur->surface/(hc*lc),a);
		
	}
	return 0;
}
