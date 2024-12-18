#include <stdio.h>

#define ROWS 3
#define COLS 4

// Fonction pour échanger deux éléments
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour appliquer le Comb Sort à une ligne
void comb_sort(int arr[], int n) {
    int gap = n; // Ecart initial
    float shrink = 1.3; // Facteur de réduction
    int sorted = 0;

    while (gap > 1 || !sorted) {
        // Réduire l'écart
        gap = (gap > 1) ? (int)(gap / shrink) : 1;
        sorted = 1;

        // Comparer et échanger les éléments séparés par l'écart
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                sorted = 0; // Si un échange a eu lieu, ce n'est pas encore trié
            }
        }
    }
}

// Fonction pour afficher l'état actuel de la matrice
void print_matrix(int mat[ROWS][COLS]) {
    printf("Current Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour trier une ligne de la matrice avec Comb Sort
void comb_sort_matrix_row(int mat[ROWS][COLS], int row) {
    comb_sort(mat[row], COLS); // Appliquer Comb Sort sur une ligne
}

// Fonction pour trier chaque ligne de la matrice
void comb_sort_matrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        comb_sort_matrix_row(mat, i); // Trier chaque ligne
        print_matrix(mat); // Afficher l'état après chaque tri de ligne
    }
}