#include <stdio.h>

#define LIGNES 3
#define COLONNES 4

void echanger(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tri_peigne(int tableau[], int taille) {
    int ecart = taille;
    float reduction = 1.3;
    int trie = 0;

    while (ecart > 1 || !trie) {
        ecart = (ecart > 1) ? (int)(ecart / reduction) : 1;
        trie = 1;

        for (int i = 0; i + ecart < taille; i++) {
            if (tableau[i] > tableau[i + ecart]) {
                echanger(&tableau[i], &tableau[i + ecart]);
                trie = 0;
            }
        }
    }
}

void afficher_matrice(int matrice[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void tri_peigne_ligne_matrice(int matrice[LIGNES][COLONNES], int ligne) {
    tri_peigne(matrice[ligne], COLONNES);
}

void tri_peigne_matrice(int matrice[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        tri_peigne_ligne_matrice(matrice, i);
        afficher_matrice(matrice);
    }
}
int main() {
    int matrice[LIGNES][COLONNES] = {
        {9, 2, 8, 7},
        {5, 3, 1, 6},
        {4, 12, 10, 11}
    };

    printf("Matrice initiale :\n");
    afficher_matrice(matrice);

    printf("\nTri de chaque ligne avec le tri peigne :\n");
    tri_peigne_matrice(matrice);

    printf("\nMatrice finale après tri :\n");
    afficher_matrice(matrice);

    return 0;
}