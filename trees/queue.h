#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef Queue_h
#define Queue_h

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

void enqueue(struct Queue *q, struct TNode* elem);

struct TNode* dequeue(struct Queue *q);

bool isEmpty(struct Queue *q);

#endif
