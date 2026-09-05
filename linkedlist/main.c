#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int len;
};

void insertFromArray(int arr[], int len, struct LinkedList *ll) {
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head->data = arr[0];
  head->next = NULL;
  ll->head = head;
  ll->len += 1;

  struct Node *ptr = head;
  for (int i = 1; i < len; i++) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = arr[i];
    temp->next = NULL;
    ll->tail = temp;
    ptr->next = temp;
    ptr = ptr->next;

    ll->len += 1;
  }
}

void display(struct LinkedList *ll) {
  struct Node *temp = ll->head;
  while (temp != NULL) {
    printf("| %d |->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int sum(struct LinkedList *ll) {
  struct Node *temp = ll->head;
  int sum = 0;
  while (temp != NULL) {
    sum += temp->data;
    temp = temp->next;
  }
  return sum;
}

int max(struct LinkedList *ll) {
  struct Node *temp = ll->head;
  int max = temp->data;
  while (temp != NULL) {
    if (temp->data > max)
      max = temp->data;
    temp = temp->next;
  }
  return max;
}

int min(struct LinkedList *ll) {
  struct Node *temp = ll->head;
  int min = temp->data;
  while (temp != NULL) {
    if (temp->data < min)
      min = temp->data;
    temp = temp->next;
  }
  return min;
}

int search(struct LinkedList *ll, int elem) {
  struct Node *temp = ll->head;
  while (temp != NULL) {
    if (temp->data == elem)
      return 1;
    temp = temp->next;
  }
  return 0;
}

void insertFirst(struct LinkedList *ll, int elem) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = elem;
  new_node->next = NULL;

  new_node->next = ll->head;
  ll->head = new_node;
}

void insertLast(struct LinkedList *ll, int elem) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)),
              *temp = ll->head;
  new_node->data = elem;
  new_node->next = NULL;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

void insert(struct LinkedList *ll, int index, int elem) {
  if (index > ll->len || index < 0)
    return;
  if (index == 0) {
    insertFirst(ll, elem);
  } else if (index == ll->len - 1) {
    insertLast(ll, elem);
  } else {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)),
                *temp = ll->head;
    new_node->data = elem;
    new_node->next = NULL;

    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
  ll->len += 1;
}

int main() {
  int arr[5] = {8, 3, 7, 12, 9};
  struct LinkedList *ll =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));

  insertFromArray(arr, 5, ll);
  display(ll);

  printf("%d\n", ll->len);
  printf("%p\n", ll->head);
  printf("%p\n", ll->tail);
  printf("%d\n", sum(ll));

  if (search(ll, 6)) {
    printf("6 is present\n");
  } else {
    printf("6 is absent\n");
  }

  insert(ll, 0, 2);
  insert(ll, 6, 100);

  display(ll);

  insert(ll, 2, 32);

  display(ll);
  return 0;
}
