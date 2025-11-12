#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue() {
    int x;
    printf("Enter element to be added: ");
    scanf("%d", &x);

    if (rear == N - 1) {
        printf("Queue is full\n");
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } 
    else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = rear = -1;
    } 
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } 
    else {
        printf("First element is %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("No elements in queue\n");
    } 
    else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
          default: printf("Invalid choice\n");
        }
    }
    return 0;
}
