#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur (int n, int vecteur[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}

#include <stdbool.h>
void tri_bulle(int *Tab, int n)   
/*  Paramètres :
Tab : un pointeur vers le tableau à trier.
n : le nombre d'éléments dans le tableau.*/
{
 bool permutation;
 int i;
 int swap;
 int nbComp = 0;  // Compteur pour les comparaisons
 int nbPerm = 0;  // Compteur pour les permutations
 int iteration = 0;  // Compteur pour les itérations
 
 permutation = true;
 while (permutation)
 {
  permutation = false;
   iteration++;  // Incrémenter le numéro de l'itération
  for (i = 0; i<n-1; i++)
  {
     nbComp++;  // Incrémenter le compteur de comparaisons
    if (Tab[i]>Tab[i+1])
    {
     swap = Tab[i];
     Tab[i] = Tab[i+1];
     Tab[i+1]= swap;
     permutation = true;
     nbPerm++;  // Incrémenter le compteur de permutations
    }
    
  }
    n = n-1; 
   // Afficher l'état du tableau et les compteurs à chaque itération
    printf("Iteration numéro %d :\n", iteration);
    afficherVecteur(n, Tab);
    printf("Nombre de comparaisons : %d, Nombre de permutations : %d\n\n", nbComp, nbPerm);
 }
 // Afficher les résultats finaux
    printf("Tri terminé après %d itérations.\n", iteration);
    printf("Nombre total de comparaisons : %d\n", nbComp);
    printf("Nombre total de permutations : %d\n", nbPerm);
}