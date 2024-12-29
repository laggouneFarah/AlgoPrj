#include <stdio.h>

void afficherVecteur(int n, int vecteur[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}

void tri_insertion(int *Tab, int n) {
    int i, j, tmp, nbComp = 0, nbPerm = 0, iteration = 0;

    for (i = 1; i < n; i++) {
        tmp = Tab[i];
        j = i - 1;
        iteration++;
        while (j >= 0 && Tab[j] > tmp) {
            nbComp++;
            Tab[j + 1] = Tab[j];
            j = j - 1;
            nbComp++;
        }
        Tab[j + 1] = tmp;
        printf("Iteration numéro %d :\n", iteration);
        afficherVecteur(n, Tab);
        printf("Nombre de comparaisons : %d, Nombre de permutations : %d\n\n", nbComp, nbPerm);
    }

    printf("Tri terminé après %d itérations.\n", iteration);
    printf("Nombre total de comparaisons : %d\n", nbComp);
    printf("Nombre total de permutations : %d\n", nbPerm);
}

int main() {
    int n;
    printf("Entrez le nombre d'éléments du tableau : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("La taille du tableau doit être positive.\n");
        return 1;
    }

    int tableau[n];
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tableau[i]);
    }

    printf("\nTableau avant le tri :\n");
    afficherVecteur(n, tableau);

    tri_insertion(tableau, n);

    printf("\nTableau après le tri :\n");
    afficherVecteur(n, tableau);

    return 0;
}
