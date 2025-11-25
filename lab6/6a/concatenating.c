
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *head2 = NULL;

void createLinkedList(struct Node **headRef, int n) {
    struct Node *newNode, *temp = NULL;
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

        if (*headRef == NULL) {
            *headRef = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Linked List created successfully.\n");
}

void concatenateLists(struct Node **list1, struct Node **list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
        *list2 = NULL;
        return;
    }

    struct Node *temp = *list1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = *list2;
    *list2 = NULL;
}

void displayList(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n1);
    createLinkedList(&head, n1);

    printf("\nEnter number of nodes for List 2: ");
    scanf("%d", &n2);
    createLinkedList(&head2, n2);

    printf("\nList 1 before concatenation:\n");
    displayList(head);
    printf("List 2 before concatenation:\n");
    displayList(head2);

    concatenateLists(&head, &head2);

    printf("\nAfter concatenation, List 1:\n");
    displayList(head);
    printf("List 2 (should be empty now):\n");
    displayList(head2);

    return 0;
}
