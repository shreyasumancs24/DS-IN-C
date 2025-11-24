#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sort linked list (Bubble Sort)
void sortList(struct Node* head) {
    if (!head) return;

    struct Node* current;
    struct Node* index;
    int temp;

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// Reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

// Concatenate two lists
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;

    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    return list1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    // Creating first list
    insertEnd(&list1, 5);
    insertEnd(&list1, 2);
    insertEnd(&list1, 9);

    // Creating second list
    insertEnd(&list2, 1);
    insertEnd(&list2, 7);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    // Sorting list1
    sortList(list1);
    printf("\nSorted List 1: ");
    display(list1);

    // Reversing list1
    list1 = reverseList(list1);
    printf("\nReversed List 1: ");
    display(list1);

    // Concatenating list1 + list2
    struct Node* merged = concatenate(list1, list2);
    printf("\nConcatenated List: ");
    display(merged);

    return 0;
}
