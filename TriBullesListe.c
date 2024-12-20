#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Définition d'un nœud de la liste chaînée
typedef struct Element {
    char mot[100];          // Le mot stocké dans ce nœud
    struct Element* suivant;   // Pointeur vers le nœud suivant
} Element;

// Fonction pour afficher les mots de la liste chaînée
void afficherListe(Element* tete) {
    Element* P = tete;
    while (P != NULL) {
        printf("%s -> ", P->mot);
        P = P->suivant;
    }
    printf("NULL\n");
}

// Fonction pour effectuer un tri à bulles sur la liste chaînée
void tri_bulle_liste( Element* tete) {
    if (!tete) 
    printf("NULL\n");  ; // Si la liste est vide

    bool permutation = true; // Initialiser à vrai pour entrer dans la boucle
    Element* dernier = NULL;    // Utilisé pour réduire la zone de tri
    int nbComp = 0;          // Compteur pour les comparaisons
    int nbPerm = 0;          // Compteur pour les permutations
    int iteration = 0;       // Compteur pour les itérations

    while (permutation) {
        permutation = false;
        Element* P = tete;
        iteration++;

        while (P->suivant != dernier) {
           nbComp++; // Incrémenter le compteur de comparaisons
            if (strcmp(P->mot, P->suivant->mot) > 0) {
                // Échanger les mots si nécessaire
                char swap[100];
                strcpy(swap, P->mot);
                strcpy(P->mot, P->suivant->mot);
                strcpy(P->suivant->mot, swap);

                permutation = true;
                nbPerm++; // Incrémenter le compteur de permutations
            }
            P = P->suivant;
        }
        dernier = P; // Réduire la zone de tri

        
        printf("Iteration numéro %d :\n", iteration);
       // Afficher l'état de la liste après chaque passage
        printf("État actuel de la liste :\n");
        afficherListe(tete);
        printf("Nombre de comparaisons : %d, Nombre de permutations : %d\n\n", nbComp, nbPerm);
    }
    
     // Afficher les résultats finaux
    printf("Tri terminé après %d itérations.\n", iteration);
    printf("Nombre total de comparaisons : %d\n", nbComp);
    printf("Nombre total de permutations : %d\n", nbPerm);
}