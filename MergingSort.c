#include <stdio.h>
#include <stdlib.h>

int cptcomparaisons = 0;
int cptpermutations = 0;

void afficherVecteur(int n, int *a) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void fusion(int *a, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1; 
    int n2 = fin - milieu;     

    int *gauche = malloc(n1 * sizeof(int));  // Tableau temporaire pour la gauche
    int *droite = malloc(n2 * sizeof(int));  // Tableau temporaire pour la droite

    // Remplir les tableaux gauche et droite
    for (int i = 0; i < n1; i++) {
        gauche[i] = a[debut + i];
    }
    for (int i = 0; i < n2; i++) {
        droite[i] = a[milieu + 1 + i];
    }

    // Fusionner les deux tableaux
    int i = 0, j = 0, k = debut;
    while (i < n1 && j < n2) {
        cptcomparaisons++;
        if (gauche[i] <= droite[j]) {
            a[k++] = gauche[i++];
        } else {
            a[k++] = droite[j++];
        }
        cptpermutations++;
    }

    // Copier les éléments restants du tableau gauche (si y en a)
    while (i < n1) {
        a[k++] = gauche[i++];
        cptpermutations++;
    }

    // Copier les éléments restants du tableau droit (si  y en a)
    while (j < n2) {
        a[k++] = droite[j++];
        cptpermutations++;
    }

    // Libérer la mémoire allouée 
    free(gauche);
    free(droite);
}

// Fonction principale de tri par fusion
void tri_fusion(int *a, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        // Appels récursifs pour trier les deux moitiés
        tri_fusion(a, debut, milieu);             // Trie la 1ere moitié
        tri_fusion(a, milieu + 1, fin);           // Trie la 2nd moitié

    
        fusion(a, debut, milieu, fin);
    }
}

int main() {
    int tableau[] = {38, 27, 43, 3, 9, 82, 10};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau initial :\n");
    afficherVecteur(taille, tableau);

    printf("\nÉtapes du tri par fusion :\n");
    tri_fusion(tableau, 0, taille - 1);

    printf("\nTableau trié :\n");
    afficherVecteur(taille, tableau);

    printf("\nNombre total de comparaisons : %d\n", cptcomparaisons);
    printf("Nombre total de permutations : %d\n", cptpermutations);

    return 0;
}
