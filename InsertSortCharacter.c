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

// Copier la chaine
void copierchaine(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; //dernier élément
}

//Comparer deux chaines:
int comparerchaines(const char* str1, const char* str2) {
    cptcomparaisons++; 
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1; // str1 est plus petite
        } else if (str1[i] > str2[i]) {
            return 1; 
        }
        i++;
    }
    // la chaine la  plus courte
    if (str1[i] == '\0' && str2[i] != '\0') {
        return -1; // str1 est plus petite
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        return 1; // str1 est plus grande
    }
    return 0; // Les deux chaines sont égales 
}

void insertion_sort_matrix_row(char matrice[ROWS][COLS][50], int row) {
    for (int i = 1; i < COLS; i++) {
        char key[50];
        copierchaine(key, matrice[row][i]); 
        int j = i - 1;

        // Déplacer les elements plus grands vers la droite
        while (j >= 0 && comparerchaines(matrice[row][j], key) > 0) {
            copierchaine(matrice[row][j + 1], matrice[row][j]);
            cptpermutations++; 
            j--;
        }
        copierchaine(matrice[row][j + 1], key);
        cptpermutations++;
    }

    // Affichage de chaque ligne de la matrice 
    printf("Matrice après le tri de la ligne %d :\n", row + 1);
    afficherMatrice(ROWS, COLS, matrice);
}

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

    printf("\nMatrice triée :\n");
    afficherMatrice(ROWS, COLS, matrice);

    // Afficher les compteurs
    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}
