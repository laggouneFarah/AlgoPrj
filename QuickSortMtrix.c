#include <stdio.h>

#define ROWS 3
#define COLS 4

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour partitionner le tableau pour le tri rapide
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choisir le pivot
    int i = (low - 1); // Indice du plus petit élément

    // Parcourir le tableau et réorganiser les éléments
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fonction pour appliquer le tri rapide sur un tableau
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Trouver l'indice du pivot
        quick_sort(arr, low, pi - 1); // Trier avant le pivot
        quick_sort(arr, pi + 1, high); // Trier après le pivot
    }
}

void quick_sort_matrix_row(int mat[ROWS][COLS], int row) {
    quick_sort(mat[row], 0, COLS - 1); // Tri rapide de la ligne
}

// Fonction pour trier chaque ligne de la matrice
void quick_sort_matrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        quick_sort_matrix_row(mat, i);  
        printf("État après le tri de la ligne %d :\n", i + 1); 
        afficherMatrice(ROWS, COLS, mat);  //affichage de la matrice 
    }
}

// Fonction pour afficher une matrice
void afficherMatrice(int lignes, int colonnes, int matrice[lignes][colonnes]);

int main() {
    int matrice[ROWS][COLS] = {
        {38, 27, 43, 3},
        {9, 82, 10, 28},
        {7, 15, 25, 60}
    };

    printf("Matrice initiale :\n");
    afficherMatrice(ROWS, COLS, matrice);

    printf("\nTri des lignes avec Quick Sort :\n");
    quick_sort_matrix(matrice);

    printf("\nMatrice triée :\n");
    afficherMatrice(ROWS, COLS, matrice);

    return 0;
}
