#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int len;
};

void enqueue(struct Queue *q, int elem) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = elem;
    new_node->next = NULL;

    if(q->head == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->len++;
}

int dequeue(struct Queue *q) {
    if(q->len == 0) return -1;

    struct Node *temp = q->head;
    int elem = temp->data;
    q->head = temp->next;
    q->len--;

    free(temp);

    return elem;
}

void display(struct Queue *q) {
    struct Node *temp = q->head;
    while(temp) {
        printf("| %d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;

    enqueue(q, 50);
    enqueue(q, 40);
    enqueue(q, 30);
    enqueue(q, 20);
    enqueue(q, 10);

    display(q);

    printf("head: %d\n", q->head->data);
    printf("tail: %d\n", q->tail->data);
    printf("len: %d\n", q->len);

    printf("removed elem: %d\n", dequeue(q));
    printf("removed elem: %d\n", dequeue(q));
    printf("removed elem: %d\n", dequeue(q));
    printf("removed elem: %d\n", dequeue(q));

    enqueue(q, 5);

    display(q);

    struct Node *curr = q->head;
    while (curr) {
        struct Node *next = curr->next;  // save next before freeing
        free(curr);
        curr = next;
    }
    free(q);

    return 0;
}
