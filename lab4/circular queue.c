#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enque() {
    int x;
    printf("Enter element to be added: ");
    scanf("%d", &x);

    if ((rear+1)%N ==front) {
        printf("Queue is full\n");
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else {
        rear=(rear+1)%N;
        queue[rear] = x;
    }
}

void deque() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } 
    else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = rear = -1;
    } 
    else {
        printf("Deleted element is %d\n", queue[front]);
        front=(front+1)%N;
    }
}



void display() {
    if (front == -1 && rear == -1) {
        printf("No elements in queue\n");
    } 
    else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear;) {
            printf("%d ", queue[i]);
            i=(i+1)%N;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Enque\n2. Deque\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enque(); break;
            case 2: deque(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
