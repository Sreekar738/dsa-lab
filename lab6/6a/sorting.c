
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

void sortList() {
    struct Node *i, *j;
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked list sorted successfully.\n");
}

void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createLinkedList(n);

    printf("\nBefore Sorting:\n");
    displayList();

    sortList();

    printf("\nAfter Sorting:\n");
    displayList();

    return 0;
}
