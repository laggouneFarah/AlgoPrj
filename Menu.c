#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Taille maximale pour les structures de données

// Prototypes des fonctions
void displayMainMenu();
void vectorSortMenu();
void matrixSortMenu();
void linkedListSortMenu();

void bubbleSortVector(int *arr, int size);
void selectionSortVector(int *arr, int size);
void insertionSortVector(int *arr, int size);

void bubbleSortMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

void createAndSortLinkedList();

// Structure pour une liste chaînée
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    displayMainMenu();
    return 0;
}

// Fonction pour afficher le menu principal
void displayMainMenu() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Vector Sort\n");
        printf("2. Matrix Sort\n");
        printf("3. Linked List Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vectorSortMenu();
                break;
            case 2:
                matrixSortMenu();
                break;
            case 3:
                linkedListSortMenu();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Menu pour le tri de vecteurs
void vectorSortMenu() {
    int choice, size;
    int vector[MAX_SIZE];

    printf("\nEnter the size of the vector (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

    printf("\n--- Vector Sort Menu ---\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSortVector(vector, size);
            break;
        case 2:
            selectionSortVector(vector, size);
            break;
        case 3:
            insertionSortVector(vector, size);
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
    }
}

// Tri à bulles pour un vecteur
void bubbleSortVector(int *arr, int size) {
    int temp;
    printf("\nBubble Sort Progress:\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Iteration %d: ", i + 1);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Tri par sélection pour un vecteur
void selectionSortVector(int *arr, int size) {
    int minIndex, temp;
    printf("\nSelection Sort Progress:\n");
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        printf("Iteration %d: ", i + 1);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Tri par insertion pour un vecteur
void insertionSortVector(int *arr, int size) {
    int key, j;
    printf("\nInsertion Sort Progress:\n");
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("Iteration %d: ", i);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Menu pour le tri de matrices
void matrixSortMenu() {
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("\nEnter the number of rows and columns (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bubbleSortMatrix(matrix, rows, cols);
}

// Tri à bulles pour une matrice (tri ligne par ligne)
void bubbleSortMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nBubble Sort Progress (row by row):\n");
    for (int r = 0; r < rows; r++) {
        for (int i = 0; i < cols - 1; i++) {
            for (int j = 0; j < cols - i - 1; j++) {
                if (matrix[r][j] > matrix[r][j + 1]) {
                    int temp = matrix[r][j];
                    matrix[r][j] = matrix[r][j + 1];
                    matrix[r][j + 1] = temp;
                }
            }
        }

        printf("Row %d after sorting: ", r + 1);
        for (int k = 0; k < cols; k++) {
            printf("%d ", matrix[r][k]);
        }
        printf("\n");
    }
}

// Menu pour le tri des listes chaînées
void linkedListSortMenu() {
    createAndSortLinkedList();
}

// Création et tri d'une liste chaînée
void createAndSortLinkedList() {
    int n, value;
    Node *head = NULL, *temp, *newNode;

    printf("\nEnter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    // Tri de la liste chaînée avec Bubble Sort
    printf("\nBubble Sort Progress:\n");
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    // Affichage de la liste triée
    printf("\nSorted Linked List: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }