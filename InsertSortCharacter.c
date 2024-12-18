#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 5
void insertion_sort_matrix_row(char matrice[ROWS][COLS][50], int row) {
    for (int i = 1; i < COLS; i++) {
        char key[50];
        strcpy(key, matrice[row][i]);
        int j = i - 1;
        // Déplacement des éléments plus grands que key vers la droite
        while (j >= 0 && strcmp(matrice[row][j], key) > 0) {
            strcpy(matrice[row][j + 1], matrice[row][j]);
            j--;
        }
        strcpy(matrice[row][j + 1], key);
    }
    // Afficher la matrice après chaque itération de tri de la ligne
    printf("Matrice après le tri de la ligne %d :\n", row + 1); 
    afficherMatrice(ROWS, COLS, matrice);
}

// Fonction pour trier chaque ligne de la matrice
void insertion_sort_matrix(char matrice[ROWS][COLS][50]) {
    for (int i = 0; i < ROWS; i++) {
        insertion_sort_matrix_row(matrice, i);
    }
}

int main() {
    char matrice[ROWS][COLS][50] = {
        {"Farah", "Laggoune", "Ines", "Allag", "Naila"},
        {"Kiwi", "Pomme", "Banane", "Ananas", "Cerise"},
        {"soleil", "lune", "Fleure", "écrivain", "livre"}
    };
    printf("Matrice initiale :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("\nTri de la matrice par insertion :\n");
    insertion_sort_matrix(matrice);

    return 0;
}
