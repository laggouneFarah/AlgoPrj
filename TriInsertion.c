#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur(int n, int vecteur[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}

void tri_insertion(int *Tab, int n)
{
 int i;
 int j;
 int tmp;
 int nbComp = 0;  // Compteur pour les comparaisons
 int nbPerm = 0;  // Compteur pour les permutations
 int iteration = 0;  // Compteur pour les itérations

 for (i = 1; i < n; i++)
 {
   tmp = Tab[i];
   j = i-1;
   iteration++;  // Incrémenter le numéro de l'itération
     while (j >= 0 && Tab[j] > tmp)
    {
       nbComp++;  // Incrémenter le compteur de comparaisons
      Tab[j+1] = Tab[j];
      j = j-1;
       nbComp++;  // Incrémenter le compteur de comparaisons
    }
    Tab[j+1] = tmp;
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