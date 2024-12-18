#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 5

// Fonction pour afficher la matrice
void afficherMatrice(int lignes, int colonnes, char matrice[lignes][colonnes][50]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%s ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Fonction de partition pour le tri rapide
int partition(char matrice[ROWS][COLS][50], int row, int low, int high) {
    char pivot[50];
    strcpy(pivot, matrice[row][high]);
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (strcmp(matrice[row][j], pivot) < 0) {
            i++;
            char temp[50];
            strcpy(temp, matrice[row][i]);
            strcpy(matrice[row][i], matrice[row][j]);
            strcpy(matrice[row][j], temp);
        }
    }
    char temp[50];
    strcpy(temp, matrice[row][i + 1]);
    strcpy(matrice[row][i + 1], matrice[row][high]);
    strcpy(matrice[row][high], temp);
    
    return i + 1;
}

// Fonction pour appliquer le tri rapide sur une ligne de la matrice
void quick_sort_matrix_row(char matrice[ROWS][COLS][50], int row, int low, int high) {
    if (low < high) {
        int pi = partition(matrice, row, low, high);
        quick_sort_matrix_row(matrice, row, low, pi - 1);
        quick_sort_matrix_row(matrice, row, pi + 1, high);
    }
}

void quick_sort_matrix(char matrice[ROWS][COLS][50]) {
    for (int i = 0; i < ROWS; i++) {
        quick_sort_matrix_row(matrice, i, 0, COLS - 1);
        // Afficher la matrice après le tri de chaque ligne
        printf("Matrice après le tri de la ligne %d :\n", i + 1); 
        afficherMatrice(ROWS, COLS, matrice);
    }
}

int main() {

    char matrice[ROWS][COLS][50] = {
        {"Farah", "Laggoune", "Ines", "Allag", "nana"},
        {"Kiwi", "Pomme", "Banane", "Ananas", "Cerise"},
        {"Soleil", "lune", "Fleure", "écrivain", "livre"}
    };
    printf("Matrice initiale :\n");
    afficherMatrice(ROWS, COLS, matrice);

    printf("\nTri de la matrice par Quick Sort :\n");
    quick_sort_matrix(matrice);

    return 0;
}
