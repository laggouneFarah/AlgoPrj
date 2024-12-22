#include <stdio.h>

typedef int bool;
enum { false, true };

void tri_peigne(int* tableau, int taille) {
    int ecart = taille;
    bool permutation = true;
    int index;

    while (permutation || (ecart > 1)) {
        permutation = false;
        ecart = ecart / 1.3;
        if (ecart < 1) ecart = 1; 

        for (index = 0; index < taille - ecart; index++) {
            if (tableau[index] > tableau[index + ecart]) {
                permutation = true;
                // Échanger les deux éléments
                int temp = tableau[index];
                tableau[index] = tableau[index + ecart];
                tableau[index + ecart] = temp;
            }
        }
    }
}
int main() {
    int tableau[] = {9, 2, 7, 6, 5, 4, 3, 8, 1, 0};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }

    tri_peigne(tableau, taille);

    printf("\nTableau après le tri :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }

    return 0;
}
