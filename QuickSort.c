#include <stdio.h>
#include<stdlib.h>

int cptcomparaisons = 0;
int cptpermutations = 0;

void tri_rapide(int *tab, int n) {
    int pivot, i, j, temp;

    // Condition necessaire pour effectuer le tri
    if (n < 2) return;

    // On prend comme pivot l'élément le plus à droite
    pivot = tab[n - 1];
    i = 0; // partitionner le tableau

    for (j = 0; j < n - 1; j++) {
        cptcomparaisons++;
        if (tab[j] <= pivot) {
            // Permuter tab[i] et tab[j] 
            if (i != j) {
                temp = tab[j];
                tab[j] = tab[i];
                tab[i] = temp;
                cptpermutations++;
            }
            i++;
        }
    }
    // Placer le pivot à sa position correcte
    if (i != n - 1) {
        temp = tab[i];
        tab[i] = tab[n - 1];
        tab[n - 1] = temp;
        cptpermutations++; 
    }
    // Appels récursifs sur les tableaux a gauche et a droite du pivot
    tri_rapide(tab, i);          // Tri de la partie gauche
    tri_rapide(tab + i + 1, n - i - 1); // Tri de la partie droite
}
void afficher(int n, int *tab) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
int main() {
    int tableau[] = {29, 10, 14, 37, 13};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau initial : ");
    afficher(taille, tableau);
    tri_rapide(tableau, taille);
    printf("Tableau trié : ");
    afficher(taille, tableau);
    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}



