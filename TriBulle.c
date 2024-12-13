/*
PROCEDURE tri_bulle ( TABLEAU a[1:n])
passage ← 0
REPETER
    permut ← FAUX
    POUR i VARIANT DE 1 A n - 1 - passage FAIRE
        SI a[i] > a[i+1] ALORS
            echanger a[i] ET a[i+1]
            permut ← VRAI
        FIN SI
    FIN POUR
    passage ← passage + 1
TANT QUE permut = VRAI
*/
#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur(int taille, int vecteur[taille]) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}

#include <stdbool.h>
void tri_bulle(int *Tab, int n)
{
 bool permutation;
 int i;
 int swap;

 permutation = true;
 while (permutation)
 {
  permutation = false;
  for (i = 0; i<n-1; i++)
  {
    if (Tab[i]>Tab[i+1])
    {
     swap = Tab[i];
     Tab[i] = Tab[i+1];
     Tab[i+1]= swap;
     permutation = true;
    }
    n = n-1;
    afficherVecteur(n, Tab);
  }
 }
}

