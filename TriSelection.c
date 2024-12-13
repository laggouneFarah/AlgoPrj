/*PROCEDURE tri_Selection ( Tableau a[1:n])
    POUR i VARIANT DE 1 A n - 1 FAIRE
        TROUVER [j] LE PLUS PETIT ELEMENT DE [i + 1:n];
        ECHANGER [j] ET [i];
FIN PROCEDURE;
*/
#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur(int taille, int vecteur[taille]) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}


void tri_selection(int *Tab, int n)
{
 int i;
 int j;
 int min;
 int imin;
 int swap;

  for (i = 0; i < n-1; i++)
  {  
    min = Tab[i];
    imin = i;
       for (j = i+1; j < n-1; j++)
       {
        if (Tab[j] < min)
        {
         min = Tab[j];
         imin = j;
        }
       }
    swap = Tab[i];
    Tab[i] = Tab[min];
    Tab[min]= swap;
    afficherVecteur(n, Tab);
  }
}

