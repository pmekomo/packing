# include "remplir_conteneur.h"

void relacher_objets (void)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(num_Bande[j]==prof)
		{
			num_Bande[j]=0;
			coord[j]->x=-1;
			coord[j]->y=-1;
			NoFree[j]=0;
			rang[j]=0;
		}
	}
}

int max_dimension(void) /* cette fonction calcul la dimension maximale et d'affecter celle_ci à la variable LARG de structure.h*/
{
	int i,m=0;
	for(i=0;i<n;i++)
	{
		if(Objet[i]->l>m)
			m=Objet[i]->l;
		if(Objet[i]->h>m)
			m=Objet[i]->h;
	}
	return m;
}

int ** Sauvegarde(int *in,int *bande,int *Rg) /* qui permet de sauvegarder les meilleurs objets dans une pile */ 
{
	int **P,r,b,i,j;
	P=malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		P[i]=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			P[i][j]=-1;
	for(i=0;i<n;i++)
	{
		if(in[i]==1)
		{
			b=bande[i];
			r=Rg[i];
			P[b-1][r-1]=i;
		}
	}
	return P;
}
void affichageSolution(int **Pile,LISTE *contenu,int *in,int *bande,int *Rg,coordonnee *cd)  /* qui affiche la solution finale*/
{
	int i,j,x,y,maxx=0,N=0,objet,objet1;
	x=0;
	for(i=0;i<n;i++)
	{
		y=0;
		objet1=Pile[i][0];
		if(objet1!=-1)
		{
			for(j=0;j<n;j++)
			{
				objet=Pile[i][j];
				if(objet!=-1)
				{
					if(maxx<contenu[objet]->l)
						maxx=contenu[objet]->l;
					cd[objet]->x=x;
					cd[objet]->y=y;
					y+=contenu[objet]->h;
				}
			}
			x+=maxx;
			maxx=0;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			objet=Pile[i][j];
			if(objet!=-1)
			{
				printf("\nObjet%d largeur:%d hauteur:%d Bande:%d rang:%d",
				objet,contenu[objet]->l,contenu[objet]->h,
				bande[objet],Rg[objet]);
				N++;
			}
				
		}
	printf("\n");
	printf("\n%d %d\n\n%d",lc,hc,N);
	for(i=0;i<n;i++)
		if(in[i]==1)
		{
			printf("\n%s %d %d %d %d",
				contenu[i]->nom,contenu[i]->l,contenu[i]->h,
				cd[i]->x,cd[i]->y);
			
		}
		printf("\n");
}

int Est_Valide(LISTE O,int l,int i) /* teste si l'objet rentre dans la bande */
{
	if(NoFree[i]!=1)
	{
		if(O->l <= l)
			return 1;
		else
			Pivoter(O);
			if(O->l <= l)
				return 1;
	}
	return 0;
}

int recherche (int **Largeur,int l,int k) /*on vérifie qu'une largeur n'apparait pas plusieurs fois */
{
	int i;
	for(i=0;i<k;i++)
		if(Largeur[prof][i]==l)
			return 1;
	return 0;
}



int selectionner_k_largeurs_valides(int k,int L,int **Largeur,int **Occ_largeur) /* selectionne k largeurs valides et alloue le tableau d'occurence des largeurs */
{
	int i,j=0,x,l,rech;
	for(i=0;i<k;i++)
	{
		Occ_largeur[prof][i]=0;
		Largeur[prof][i]=0;
	}
	i=0;
	while(i<n && j<k)
	{
		if(Est_Valide(Objet[i],L,i))
		{
			l=Objet[i]->l;
			rech=recherche (Largeur,l,k);
			if(rech!=1)
			{
				Largeur[prof][j]=l;
				for(x=0;x<n;x++)
				{
					if(Objet[x]->l==l)
					{
						Occ_largeur[prof][j]+=1;
					}
				}
				j++;
			}
		}
		i++;
	}
	return j;
}

int Max(int **Occ_largeur,int k) /* selection la largeur qui a le plus d'occurences */
{
	int i,max=0,maxi=0;
	for(i=k-1;i>=0;i--)
	{
		if(Occ_largeur[prof][i]>max)
		{
			max=Occ_largeur[prof][i];
			maxi=i;
		}
	}
		
	return maxi;
}



void remplir_bande(int e,int **Occ_largeur,int H) /* permet de remplir les bandes */
{
	int i=0,h=0,rg=0;
		
		while(h<H && i<n)
		{
				/*if(Est_Valide(Objet[i],e,i))*/
				if (Objet[i]->l <=e && NoFree[i]!=1)
				{
					
					if((Objet[i]->h)+h<=H)
					{
						rg++;
						h=(Objet[i]->h)+h;
						NoFree[i]=1;
						num_Bande[i]=prof;
						rang[i]=rg;
						
					}
				}
				i++;
		}
}




LISTEC mettre_a_jour_meilleur_remplissage(int L,int H,int surface)/* permet de mettre à jour le meilleur remplissage */
{
	int i;
	if(Meilleur->surface < surface)
	{
		Meilleur->hc=H;
		Meilleur->lc=L;
		Meilleur->surface=surface;
		for(i=0;i<n;i++)
		{
			
			Meilleur->contenu[i]->h=Objet[i]->h;
			Meilleur->contenu[i]->l=Objet[i]->l;
			Meilleur->Free[i]=NoFree[i];
			Meilleur->coord[i]->x=coord[i]->x;
			Meilleur->coord[i]->y=coord[i]->y;
			Meilleur->num_Bande[i]=num_Bande[i];
			strcpy(Meilleur->contenu[i]->nom,Objet[i]->nom);
			Meilleur->rang[i]=rang[i];
		}
		
	}
	/*printf("\nmeilleur=%d surface_courante=%d",Meilleur->surface,surface);*/
	return Meilleur;
}

int surface_occupe_courante (void) /* calcule la surface courante */
{
	int i,surface=0;
	for(i=0;i<n;i++)
		if ( NoFree[i]==1)
			surface+=Objet[i]->surface;
	return surface;
}

int propriete_de_coupure(int L) /* permet de calculer les differentes proprietes de coupure et retourne un boolean quand l'une d'elle est vérifiée */
{
	int i=0,j=0,S;
	for(i=0;i<n;i++)
		if(NoFree[i]==1)
			j++;
	S=surface_occupe_courante();
	
	
	if((Meilleur->surface==hc*lc) || L<=0 || j==n || (S + (L*hc)) <= Meilleur->surface)
		return 1;
	else
		return 0;
}
	

void remplir_conteneur(int L,int H,int k,int **Largeur,int **Occ_largeur,int *p,int *V,int option)
{
	int i,Select,x,surface,e,coupure;
	if(prof<n)
	{
		Select=selectionner_k_largeurs_valides(k,L,Largeur,Occ_largeur);
	}
	else
		Select=0;

	if(Select==0)
	{
		surface=0;
		for(i=0;i<n;i++)
			if(NoFree[i]==1)
				surface+=Objet[i]->surface;
		mettre_a_jour_meilleur_remplissage(L,H,surface);
		return;
	}
	coupure=propriete_de_coupure(L);
	
	if(coupure!=1)
	{
		for(i=0;i<Select;i++)
		{
			printf ("prof=%d i=%d\n",prof ,i);
			x=Max(Occ_largeur,k);
			e=Largeur[prof][x];
			if(e>0)
			{
				prof++;
				if(option==0)
					Sac_A_Dos(e,Occ_largeur,H,p,V);
				else
					remplir_bande(e,Occ_largeur,H);
				Occ_largeur[prof-1][x]=0;
				Largeur[prof-1][x]=0;
				remplir_conteneur(L-e,H,k,Largeur,Occ_largeur,p,V,option);
				relacher_objets ();
				prof--;
			}
			
				
		}
	}
	
	
}


