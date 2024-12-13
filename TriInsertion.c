#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur(int taille, int vecteur[taille]) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}


void tri_insertion(int *Tab, int n)
{
 int i;
 int j;
 int tmp;

 for (i = 1; i < n; i++)
 {
   tmp = Tab[i];
   j = i-1;
     while (j >= 0 && Tab[j] > tmp)
    {
      Tab[j+1] = Tab[j];
      j = j-1;
    }
    Tab[j+1] = tmp;
    afficherVecteur(n, Tab);
  }
}