#include <stdio.h>
// Fonction pour afficher un vecteur
void afficherVecteur(int taille, int vecteur[taille]) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}