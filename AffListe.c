#include <stdio.h>
// Définition d'une structure pour une liste simplement chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour afficher une liste simplement chaînée
void afficherListe(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}