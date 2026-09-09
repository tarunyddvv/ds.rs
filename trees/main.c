// INFO: algo
// 1. create a root node
// 2. insert the pointer of that node inside queue
// 3. take out that address and point a pointer p to that address
// 4. ask if we have a left node if yes create a new node using a temp pointer
// and add
//      the address of that new node inside queue and point p->left to this new
//      node.
// 5. as if we have a right node if yes create a new node using the same temp
// pointer and add
//      the address of that new node inside queue and point p->right to this new
//      node
// 6. next remove the next pointer from queue and point p to that address and
// repeat this process.
// 7. if queue is empty we are done with insertion

#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

struct Tree {
  struct TNode *root;
};

void insert(struct Queue *q, struct Tree *tree, int elem) {
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

    printf("do we have a left node?");
    scanf("%d", &x);
    if (x != -1) {
      temp = (struct TNode *)malloc(sizeof(struct TNode));
      temp->data = x;
      temp->left = NULL;
      temp->right = NULL;
      ptr->left = temp;
      enqueue(q, temp);
    }

    printf("do we have a right node?");
    scanf("%d", &x);
    if (x == -1) {
      continue;
    }
    temp = (struct TNode *)malloc(sizeof(struct TNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    ptr->right = temp;
    enqueue(q, temp);
  }
}

void preorder(struct TNode *tree) {
    if (tree) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct TNode *tree) {
    if (tree) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void postorder(struct TNode *tree) {
    if (tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

void freeTree(struct TNode *node) {
  if (node == NULL) {
    return;
  }
  freeTree(node->left);
  freeTree(node->right);
  free(node);
}

int main() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->head = NULL;
  q->tail = NULL;
  q->len = 0;

  struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
  insert(q, tree, 5);

  preorder(tree->root);
  printf("\n");

  inorder(tree->root);
  printf("\n");

  postorder(tree->root);
  printf("\n");


  freeTree(tree->root);
  free(tree);
  free(q);

  return 0;
}
