#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

struct Node* createNode(int value) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}


void createList() {
    int x;
    printf("Enter values (-1 to stop): ");
    scanf("%d", &x);

    while (x != -1) {
        struct Node* new = createNode(x);

        if (head == NULL) {
            head = tail = new;
        } else {
            tail->next = new;
            new->prev = tail;
            tail = new;
        }

        scanf("%d", &x);
    }
}

void insertLeft(int target, int value) {
    struct Node* t = head;

    while (t && t->data != target)
        t = t->next;
    if (!t) return;

    struct Node* new = createNode(value);
    new->next = t;
    new->prev = t->prev;

    if (t->prev)
        t->prev->next = new;
    else
        head = new;  
    t->prev = new;
}


void deleteNode(int value) {
    struct Node* t = head;

    while (t && t->data != value)
        t = t->next;
    if (!t) return;

    if (t->prev)
        t->prev->next = t->next;
    else
        head = t->next; 

    if (t->next)
        t->next->prev = t->prev;
    else
        tail = t->prev;    

    free(t);
}

void display() {
    struct Node* t = head;
    printf("List: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}


int main() {
    int ch, x, y;

    while (1) {
        printf("\n1.Create  2.Insert Left  3.Delete  4.Display  5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createList(); break;
            case 2:
                printf("Enter target & new value: ");
                scanf("%d %d", &x, &y);
                insertLeft(x, y);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                deleteNode(x);
                break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
