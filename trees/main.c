// INFO: algo
// 1. create a root node
// 2. insert the pointer of that node inside queue
// 3. take out that address and point a pointer p to that address
// 4. ask if we have a left node if yes create a new node using a temp pointer and add
//      the address of that new node inside queue and point p->left to this new node.
// 5. as if we have a right node if yes create a new node using the same temp pointer and add
//      the address of that new node inside queue and point p->right to this new node
// 6. next remove the next pointer from queue and point p to that address and repeat this process.
// 7. if queue is empty we are done with insertion

#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

struct TNode {
    struct BNode *left;
    int data;
    struct BNode *right;
};

struct Tree {
    struct TNode *root;
};

void insert() {

}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 70);

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}
