#include <stdio.h>
#include <stdlib.h>

// -------------------------
// Node structure
// -------------------------
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// -------------------------
// STACK OPERATIONS
// -------------------------

// PUSH (Insert at beginning)
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    return newNode;
}

// POP (Delete from beginning)
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }

    struct Node* temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);

    return top;
}

// Display Stack
void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// -------------------------
// QUEUE OPERATIONS
// -------------------------

// ENQUEUE (Insert at end)
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = createNode(value);

    if (*rear == NULL) {     // empty queue
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

// DEQUEUE (Delete from beginning)
void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = *front;
    printf("Dequeued: %d\n", temp->data);

    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

// Display Queue
void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}


// -------------------------
// MAIN FUNCTION
// -------------------------
int main() {

    // STACK simulation
    struct Node* stackTop = NULL;

    printf("=== STACK OPERATIONS ===\n");
    stackTop = push(stackTop, 10);
    stackTop = push(stackTop, 20);
    stackTop = push(stackTop, 30);

    displayStack(stackTop);

    stackTop = pop(stackTop);
    displayStack(stackTop);


    // QUEUE simulation
    struct Node *front = NULL, *rear = NULL;

    printf("\n=== QUEUE OPERATIONS ===\n");
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 15);
    enqueue(&front, &rear, 25);

    displayQueue(front);

    dequeue(&front, &rear);
    displayQueue(front);

    return 0;
}
