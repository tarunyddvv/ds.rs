#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

struct Tree {
  struct TNode *root;
};

struct TNode* search(struct TNode *root, int elem) {
    struct TNode *temp = root;

    while(temp != NULL) {
        if (temp->data == elem) return temp;
        if (temp->data > elem)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

void insert(struct TNode **root, int elem) {
    struct TNode *node = (struct TNode *)malloc(sizeof(struct TNode));
    node->data = elem;
    node->left = node->right = NULL;

    if (*root == NULL) {
        *root = node;
        return;
    }
    struct TNode *temp = *root, *tail = NULL;
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

struct TNode *RInsert(struct TNode *root, int key) {
    if (root == NULL) {
        struct TNode *t = (struct TNode *)malloc(sizeof(struct TNode));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if (key < root->data)
        root->left = RInsert(root->left, key);
    else if (key > root->data)
        root->right = RInsert(root->right, key);

    return root;
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
    tree->root = NULL;

    insert(&tree->root, 30);
    insert(&tree->root, 20);
    insert(&tree->root, 40);
    insert(&tree->root, 10);
    insert(&tree->root, 25);
    insert(&tree->root, 35);
    insert(&tree->root, 50);
    RInsert(tree->root, 38);

    levelOrder(tree->root);

    struct TNode *result = search(tree->root, 40);
    if (result == NULL) {
        printf("40 not found\n");
    } else {
        printf("elem: %d\n", result->data);
        if (result->left)
            printf("elem left data: %d\n", result->left->data);
        else
            printf("elem has no left child\n");
        if (result->right)
            printf("elem right data: %d\n", result->right->data);
        else
            printf("elem has no right child\n");
    }

    freeTree(tree->root);
    free(tree);

    return 0;
}
