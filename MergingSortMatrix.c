#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 5
int cptcomparaisons = 0;
int cptpermutations = 0;

void afficherMatrice(int lignes, int colonnes, int matrice[lignes][colonnes]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fusion(int *ligne, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1;
    int n2 = fin - milieu;
    int *gauche = malloc(n1 * sizeof(int)); //tableau gauche
    int *droite = malloc(n2 * sizeof(int)); // tableau droit

    for (int i = 0; i < n1; i++) {
        gauche[i] = ligne[debut + i];
    }
    for (int i = 0; i < n2; i++) {
        droite[i] = ligne[milieu + 1 + i];
    }

    int i = 0, j = 0, k = debut;

    // Fusionner les tableaux dans un tableau principal
    while (i < n1 && j < n2) {
        cptcomparaisons++;
        if (gauche[i] <= droite[j]) {
            ligne[k++] = gauche[i++];
        } else {
            ligne[k++] = droite[j++];
        }
        cptpermutations++;
    }

    //les éléments restants de gauche
    while (i < n1) {
        ligne[k++] = gauche[i++];
        cptpermutations++;
    }

    //les éléments restants de droite
    while (j < n2) {
        ligne[k++] = droite[j++];
        cptpermutations++;
    }
    free(gauche);
    free(droite);
}
void tri_fusion_ligne(int *ligne, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        // Trier les deux moitiés récursivement
        tri_fusion_ligne(ligne, debut, milieu);
        tri_fusion_ligne(ligne, milieu + 1, fin);

        // Fusionner les deux moitiés
        fusion(ligne, debut, milieu, fin);
    }
}
void tri_fusion_matrice(int lignes, int colonnes, int matrice[lignes][colonnes]) {
    for (int i = 0; i < lignes; i++) {
        printf("Tri de la ligne %d :\n", i + 1);
        tri_fusion_ligne(matrice[i], 0, colonnes - 1);
        afficherMatrice(lignes, colonnes, matrice);
    }
}
int main() {
    int matrice[ROWS][COLS] = {
        {38, 27, 43, 3, 9},
        {82, 10, 15, 30, 20},
        {50, 60, 40, 70, 80}
    };
    printf("Matrice initiale :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("Tri par fusion appliqué à chaque ligne :\n");
    tri_fusion_matrice(ROWS, COLS, matrice);
    printf("\nMatrice triée :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}
