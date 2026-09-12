#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

struct Tree {
  struct TNode *root;
};

void insert(struct Tree *tree, int elem) {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->head = NULL;
  q->tail = NULL;
  q->len = 0;

  struct TNode *temp = NULL, *ptr = NULL;
  int x = 0;

  struct TNode *root = (struct TNode *)malloc(sizeof(struct TNode));
  root->left = NULL;
  root->data = elem;
  root->right = NULL;

  tree->root = root;
  enqueue(q, root);

  while (!isEmpty(q)) {
    ptr = dequeue(q);

    printf("enter left node for %d: ", ptr->data);
    fflush(stdout);
    if (scanf("%d", &x) != 1) {
      ptr->left = NULL;
      ptr->right = NULL;
      break;
    }
    if (x != -1) {
      temp = (struct TNode *)malloc(sizeof(struct TNode));
      temp->data = x;
      temp->left = NULL;
      temp->right = NULL;
      ptr->left = temp;
      enqueue(q, temp);
    } else {
      ptr->left = NULL;
    }

    printf("enter right node for %d: ", ptr->data);
    fflush(stdout);
    if (scanf("%d", &x) != 1) {
      ptr->right = NULL;
      break;
    }
    if (x == -1) {
      ptr->right = NULL;
      continue;
    }
    temp = (struct TNode *)malloc(sizeof(struct TNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    ptr->right = temp;
    enqueue(q, temp);
  }
  free(q);
}

int main()
{
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    insert(tree, 8);

    return 0;
}
