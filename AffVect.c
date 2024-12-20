#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur (int n, int vecteur[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}