
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createLinkedList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory Allocation Failed.\n");
            return;
        }

        printf("Enter data for Node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Linked List created successfully.\n");
}

void reversing() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;        
    }
    head = prev;

    printf("Linked list reversed successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    } else {
        printf("Linked list: ");
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createLinkedList(n);

    printf("Before reversing:\n");
    display();

    reversing();

    printf("After reversing:\n");
    display();

    return 0;
}
