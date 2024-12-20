#include <stdio.h>

// Fonction pour afficher un vecteur
void afficherVecteur(int n, int vecteur[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}

// Fonction pour effectuer un tri par sélection
void tri_selection(int *Tab, int n)
{
    int i, j, min, imin, swap;
    int nbComp = 0;  // Compteur pour les comparaisons
    int nbPerm = 0;  // Compteur pour les permutations
    int iteration = 0;  // Compteur pour les itérations

    for (i = 0; i < n - 1; i++)
    {
        min = Tab[i];
        imin = i;
        iteration++;  // Incrémenter le numéro de l'itération

        // Comparaison pour trouver le minimum
        for (j = i + 1; j < n; j++) {
            nbComp++;  // Incrémenter le compteur de comparaisons
            if (Tab[j] < min) {
                min = Tab[j];
                imin = j;
            }
        }

        // Échanger les éléments si nécessaire
        if (imin != i) {
            swap = Tab[i];
            Tab[i] = Tab[imin];
            Tab[imin] = swap;
            nbPerm++;  // Incrémenter le compteur de permutations
        }

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
