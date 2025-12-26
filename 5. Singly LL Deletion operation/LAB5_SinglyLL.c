#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int n) {
    struct Node *newNode, *temp;
    int data, i;
    if (n <= 0) return;

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertAtPosition(int data, int pos) {
    int i;
    struct Node *newNode, *temp;
   newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;
   newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);
}
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted last element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
printf("Deleted last element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted element: %d\n", value);
        free(temp);
        return;
    }
struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Element %d not found.\n", value);
    } else {
        struct Node* del = temp->next;
        temp->next = del->next;
        printf("Deleted element: %d\n", value);
        free(del);
    }
}
int main() {
    int n, choice, data, pos, value;

    printf("Enter initial nodes : ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    create(n);

    printf("\nLINKED LIST MENU\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete First\n");
    printf("5. Delete Last\n");
    printf("6. Delete by Value\n");
    printf("7. Display\n");
    printf("8. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
         case 7:
                printf("Linked List: ");
                display();
                break;

            case 8:
                exit(0);
default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}