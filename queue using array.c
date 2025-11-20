#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function to insert element into queue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", x);
    } else {
        if (front == -1) front = 0;  // First insertion
        rear++;
        queue[rear] = x;
        printf("%d enqueued into queue\n", x);
    }
}

// Function to delete element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to dequeue\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

// Function to return the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Function to display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
