#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_WORD_LENGTH 100
#define ROWS 10
#define COLS 10 

// Prototypes de fonctions pour le tri des vecteurs
void tri_bulle(int *Tab, int n);
void tri_insertion(int *Tab, int n);
void tri_fusion(int *a, int debut, int fin);
void tri_rapide(int *tab, int n);
void tri_selection(int *Tab, int n);
void tri_peigne(int* tableau, int taille);
void fusion(int *a, int debut, int milieu, int fin);

// Prototypes de fonctions pour le tri des matrices
void triInsertionMatrice(char matrice[ROWS][COLS][50], int lignes);
void tri_fusion_matrice(char matrice[ROWS][COLS][50], int debut, int fin);

// Prototypes de fonctions pour le tri des listes chaînées
typedef struct NoeudMot {
    char mot[MAX_WORD_LENGTH];
    struct NoeudMot* suivant;
} NoeudMot;

void tri_bulle_liste(NoeudMot** tete);
void tri_insertion_liste(NoeudMot** tete);

// Fonctions utilitaires
void echanger(int *a, int *b);
void echangerChaines(char* str1, char* str2);
void afficherVecteur(int n, int vecteur[n]);
void afficherMatrice(char matrice[ROWS][COLS][50], int lignes);
void afficherListe(NoeudMot* tete);

int main() {
    int choix, choixAlgo, arr[MAX], n;
    char matrice[ROWS][COLS][50];
    NoeudMot* listeMots = NULL;

    printf("Choisissez une option :\n");
    printf("1. Tri d'un vecteur\n");
    printf("2. Tri d'une matrice\n");
    printf("3. Tri d'une liste chaînée\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) { // Tri d'un vecteur
        printf("Entrez la taille du vecteur :\n");
        scanf("%d", &n);
        printf("Remplissez le vecteur :\n");
        for (int i = 0; i < n; i++) {
            printf("Entrez l'élément %d : ", i + 1);
            scanf("%d", &arr[i]);
        }

        printf("Menu de tri pour le vecteur :\n");
        printf("1. Tri par bulle\n");
        printf("2. Tri par insertion\n");
        printf("3. Tri par fusion\n");
        printf("4. Tri rapide\n");
        printf("5. Tri par sélection\n");
        printf("6. Tri par peigne\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choixAlgo);

        switch (choixAlgo) {
            case 1:
                tri_bulle(arr, n);
                break;
            case 2:
                tri_insertion(arr, n);
                break;
            case 3:
                tri_fusion(arr, 0, n - 1);
                break;
            case 4:
                tri_rapide(arr, n);
                break;
            case 5:
                tri_selection(arr, n);
                break;
            case 6:
                tri_peigne(arr, n);
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }

        printf("Vecteur trié : ");
        afficherVecteur(n, arr);
    }
    else if (choix == 2) { // Tri d'une matrice
        int lignes;
        printf("Entrez le nombre de mots dans la matrice : ");
        scanf("%d", &lignes);
        printf("Entrez les mots :\n");
        for (int i = 0; i < lignes; i++) {
            scanf("%s", matrice[i][0]);
        }

        printf("Menu de tri pour la matrice :\n");
        printf("1. Tri par insertion\n");
        printf("2. Tri par fusion\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choixAlgo);

        switch (choixAlgo) {
            case 1:
                triInsertionMatrice(matrice, lignes);
                break;
            case 2:
                tri_fusion_matrice(matrice, 0, lignes - 1);
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }

        printf("Matrice triée :\n");
        afficherMatrice(matrice, lignes);
    }
    else if (choix == 3) { // Tri d'une liste chainée
        int nbMots;
        printf("Entrez le nombre de mots dans la liste : ");
        scanf("%d", &nbMots);

        for (int i = 0; i < nbMots; i++) {
            NoeudMot* nouveauNoeud = (NoeudMot*)malloc(sizeof(NoeudMot));
            printf("Entrez le mot %d : ", i + 1);
            scanf("%s", nouveauNoeud->mot);
            nouveauNoeud->suivant = listeMots;
            listeMots = nouveauNoeud;
        }

        printf("Menu de tri pour la liste chainée :\n");
        printf("1. Tri par bulle\n");
        printf("2. Tri par insertion\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choixAlgo);

        switch (choixAlgo) {
            case 1:
                tri_bulle_liste(&listeMots);
                break;
            case 2:
                tri_insertion_liste(&listeMots);
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }

        printf("Liste triée :\n");
        afficherListe(listeMots);
    }
    return 0;
}



