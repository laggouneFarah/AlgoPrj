#include <stdio.h>

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