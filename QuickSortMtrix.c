#include <stdio.h>

#define ROWS 3
#define COLS 4

int cptcomparaisons = 0;
int cptpermutations = 0;

//swap deux éléments
void echanger(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cptpermutations++;
}
// partitionner le tableau pour le tri rapide
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choisir le pivot
    int i = (low - 1);
    // Parcourir le tableau et réorganiser les éléments
    for (int j = low; j < high; j++) {
        cptcomparaisons++;
        if (arr[j] < pivot) {
            i++;
            echanger(&arr[i], &arr[j]);
        }
    }
    echanger(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void trirapide(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Trouver l'indice du pivot
        trirapide(arr, low, pi - 1); // Trier avant le pivot
        trirapide(arr, pi + 1, high); // Trier après le pivot
    }
}
void trirapidelignematrice(int mat[ROWS][COLS], int row) {
    trirapide(mat[row], 0, COLS - 1); 
}

//trier chaque ligne de la matrice
void trirapidematrice(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        trirapidelignematrice(mat, i);  
        printf("État après le tri de la ligne %d :\n", i + 1); 
        afficherMatrice(ROWS, COLS, mat);
    }
}
void afficherMatrice(int lignes, int colonnes, int matrice[lignes][colonnes]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrice[ROWS][COLS] = {
        {9, 2, 96, 3},
        {25, 4, 10, 28},
        {7, 22, 6, 60}
    };
    printf("Matrice initiale :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("\nTri des lignes avec Quick Sort :\n");
    trirapidematrice(matrice);
    printf("\nMatrice triée :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}
