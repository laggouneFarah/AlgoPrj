#include <stdio.h>

#define ROWS 3
#define COLS 5

int cptcomparaisons = 0;
int cptpermutations = 0;
void afficherMatrice(int lignes, int colonnes, char matrice[lignes][colonnes][50]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%s ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Copier une chaine
void copierchaine(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; //dernier élément 
}

//Comparer deux chaines
int comparerchaines(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1; // str1 est plus petite
        } else if (str1[i] > str2[i]) {
            return 1; // str1 est plus grande
        }
        i++;
    }
    //la chaine la plus courte
    if (str1[i] == '\0' && str2[i] != '\0') {
        return -1; // str1 est plus petite
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        return 1; // str1 est plus grande
    }
    return 0; // Les deux chaines sont égales
}

// échanger deux chaines de caractères
void echangerchaines(char* str1, char* str2) {
    char temp[50];
    copierchaine(temp, str1);
    copierchaine(str1, str2);
    copierchaine(str2, temp);
    cptpermutations++; 
}
//partition pour le tri rapide
int partition(char matrice[ROWS][COLS][50], int row, int low, int high) {
    char pivot[50];
    copierchaine(pivot, matrice[row][high]); // Copier le pivot
    int left = low - 1;

    for (int right = low; right < high; right++) {
        cptcomparaisons++; 
        if (comparerchaines(matrice[row][right], pivot) < 0) {
            left++;
            echangerchaines(matrice[row][left], matrice[row][right]);
        }
    }
    echangerchaines(matrice[row][left + 1], matrice[row][high]);
    return left + 1;
}

void quick_sort_matrix_row(char matrice[ROWS][COLS][50], int row, int low, int high) {
    if (low < high) {
        int pi = partition(matrice, row, low, high);
        quick_sort_matrix_row(matrice, row, low, pi - 1);
        quick_sort_matrix_row(matrice, row, pi + 1, high);
    }
}

void quicksortmatrix(char matrice[ROWS][COLS][50]) {
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
    quicksortmatrix(matrice);
    printf("\nMatrice triée :\n");
    afficherMatrice(ROWS, COLS, matrice);
    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}

