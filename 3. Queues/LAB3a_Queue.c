#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element
void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Function to delete an element
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
