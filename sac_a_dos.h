#ifndef SAC_A_DOS_H
#define SAC_A_DOS_H
# include "remplir_conteneur.h"

int CalculMeilleurChargement (int n, int pmax, int*p, int*V);

int PrintSol (int n, int*p, int pmax);

void Sac_A_Dos(int e,int **Occ_largeur,int H,int *p,int *V);

#endif
