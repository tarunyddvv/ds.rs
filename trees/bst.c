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

int search(struct TNode *root, int elem) {
    struct TNode *temp = root;

    while(temp != NULL) {
        if (temp->data == elem) return 1;
        if (temp->data > elem)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return 0;
}

void insertAt(struct TNode *root, int elem) {
    struct TNode *node = (struct TNode *)malloc(sizeof(struct TNode));
    node->left = NULL;
    node->data = elem;
    node->right = NULL;

    struct TNode *temp = root, *tail = NULL;
    while (temp) {
        if (temp->data == elem) {
            printf("element is already present in the tree");
            free(node);
            return;
        }
        if (temp->data > elem) {
            tail = temp;
            temp = temp->left;
        } else {
            tail = temp;
            temp = temp->right;
        }
    }
    if (elem > tail->data) {
        tail->right = node;
    } else {
        tail->left = node;
    }
}

void levelOrder(struct TNode *root) {
  struct TNode *temp = root;
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->head = NULL;
  q->tail = NULL;
  q->len = 0;

  printf("%d ", root->data);
  enqueue(q, root);

  while (!isEmpty(q)) {
    temp = dequeue(q);
    if (temp->left != NULL) {
      printf("%d ", temp->left->data);
      enqueue(q, temp->left);
    }
    if (temp->right != NULL) {
      printf("%d ", temp->right->data);
      enqueue(q, temp->right);
    }
  }
  printf("\n");
  free(q);
}

void freeTree(struct TNode *node) {
  if (node == NULL) {
    return;
  }
  freeTree(node->left);
  freeTree(node->right);
  free(node);
}

int main()
{
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    insert(tree, 30);

    if (search(tree->root, 12)) {
        printf("12 is present in the tree\n");
    } else {
        printf("12 is not present in the tree\n");
    }

    insertAt(tree->root, 38);
    levelOrder(tree->root);

    freeTree(tree->root);
    free(tree);

    return 0;
}
