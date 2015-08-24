#include "sac_a_dos.h"

int CalculMeilleurChargement (int nomb, int pmax, int*p, int*V) /*Calcul le meilleur chargement*/
{
	int i,j;

	for(j=0;j<=pmax;j++)
		if(p[0]>j)
			Matrice_Sac[0][j]=0;
		else
			Matrice_Sac[0][j]=V[0];
	
	for(i=0;i<nomb;i++)
		for(j=1;j<=pmax;j++)
		{
			Matrice_Sac[i+1][j]=Matrice_Sac[i][j];
			if((p[i+1]<=j) && (Matrice_Sac[i][j-p[i+1]]+V[i+1]>Matrice_Sac[i][j]))
			{
				Matrice_Sac[i+1][j]=Matrice_Sac[i][j-p[i+1]]+V[i+1];
			}
			
		}
		return 0;

}

int PrintSol (int nomb, int*p, int pmax){ /* Sauvegarde le meilleur remplissage */
	int i=nomb, j=pmax, m=0,rg=0;
	while(Matrice_Sac[i][j]!=0 && i!=0){
		if(Matrice_Sac[i-1][j]!=Matrice_Sac[i][j] && j>0){
			rg++;
			NoFree[i]=1;
			num_Bande[i]=prof;
			rang[i]=rg;
			j-=p[i];
		}
		
		i--;
	}
	if ((i==0) && Matrice_Sac[i][j]!=0)
	{
		if(Matrice_Sac[i][j] !=Matrice_Sac[i+1][j] && j>0)
		{
			rg++;
			NoFree[i]=1;
			num_Bande[i]=prof;
			rang[i]=rg;
			j-=p[i];
		}
	}
	return m;

}

void Sac_A_Dos(int e,int **Occ_largeur,int H,int *p,int *V)
{
	int i,j,pmax=H;
	
	
	for(i=0;i<n;i++)
	{
		p[i]=0;
		V[i]=0;
	}
	j=0;
	for(i=0;i<n;i++){
		if(Est_Valide(Objet[i],e,i))
		{
			p[i]=Objet[i]->h;
			V[i]=Objet[i]->surface;
			j++;
			/*printf("objet %d selectionne\n",i);*/
		}
		
	}
	/*printf("\n");*/
	
	CalculMeilleurChargement (j,pmax,p,V);
	PrintSol (j,p,pmax);

}
