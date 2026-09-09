#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TNode {
    struct TNode *left;
    int data;
    struct TNode *right;
};

struct Node {
    struct TNode* data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int len;
};

void enqueue(struct Queue *q, struct TNode* elem) {
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

struct TNode* dequeue(struct Queue *q) {
    if(q->len == 0) return NULL;

    struct Node *temp = q->head;
    struct TNode *elem = temp->data;
    q->head = temp->next;
    q->len--;

    free(temp);

    return elem;
}

bool isEmpty(struct Queue *q) {
    return q->len == 0;
}
