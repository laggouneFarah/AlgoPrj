#include <stdio.h>
// Fonction pour afficher une matrice
void afficherMatrice(int lignes, int colonnes, int matrice[lignes][colonnes]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}