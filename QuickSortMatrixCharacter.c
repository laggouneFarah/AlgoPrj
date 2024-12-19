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

// Fonction pour échanger deux chaînes de caractères
void echanger_chaines(char* str1, char* str2) {
    char temp[50];
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        temp[i] = str1[i];
        str1[i] = str2[i];
        str2[i] = temp[i];
        i++;
    }
    temp[i] = '\0'; // Termine la chaîne
    str1[i] = '\0';
    str2[i] = '\0';
}

// Fonction de partition pour le tri rapide
int partition(char matrice[ROWS][COLS][50], int row, int low, int high) {
    char pivot[50];
    int i = 0;

    // Copie manuelle du pivot
    while (matrice[row][high][i] != '\0') {
        pivot[i] = matrice[row][high][i];
        i++;
    }
    pivot[i] = '\0';

    int left = low - 1;

    for (int right = low; right < high; right++) {
        if (strcmp(matrice[row][right], pivot) < 0) {
            left++;
            echanger_chaines(matrice[row][left], matrice[row][right]);
        }
    }
    echanger_chaines(matrice[row][left + 1], matrice[row][high]);

    return left + 1;
}

// Fonction pour appliquer le tri rapide sur une ligne de la matrice
void quick_sort_matrix_row(char matrice[ROWS][COLS][50], int row, int low, int high) {
    if (low < high) {
        int pi = partition(matrice, row, low, high);
        quick_sort_matrix_row(matrice, row, low, pi - 1);
        quick_sort_matrix_row(matrice, row, pi + 1, high);
    }
}

// Fonction pour trier la matrice entière
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
