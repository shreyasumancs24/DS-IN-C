#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node to the LEFT of a node with a specific value
void insertLeft(int value, int targetValue) {
    struct Node* newNode = createNode(value);

    // Case: List empty
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    struct Node* current = head;

    // Search for targetValue
    while (current != NULL && current->data != targetValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target value not found\n");
        free(newNode);
        return;
    }

    // Case: Insert before head
    if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Insert in the middle
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;

    // Find the node
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found\n");
        return;
    }

    // Case: Only node in list
    if (head == tail) {
        head = tail = NULL;
        free(current);
        return;
    }

    // Case: Delete head
    if (current == head) {
        head = head->next;
        head->prev = NULL;
        free(current);
        return;
    }

    // Case: Delete tail
    if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
        free(current);
        return;
    }

    // Case: Delete in middle
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

// Display list
void display() {
    struct Node* current = head;

    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main program to test the operations
int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert Left of Node\n");
        printf("2. Delete Node by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter target value to insert LEFT of: ");
                scanf("%d", &target);
                insertLeft(value, target);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
