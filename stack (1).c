#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    int item;
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        item = stack[top];
        top--;
        printf("The removed element is %d\n", item);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch;
    while (1) {
        printf("Enter choice: 1. Push 2. Pop 3. Peek 4. Display ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
