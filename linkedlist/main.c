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
    printf("| %d | -> ", temp->data);
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
  ll->len += 1;
}

void insertLast(struct LinkedList *ll, int elem) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = elem;
  new_node->next = NULL;

  ll->tail->next = new_node;
  ll->tail = new_node;
  ll->len += 1;
}

void insert(struct LinkedList *ll, int index, int elem) {
  if (index > ll->len-1 || index < 0)
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
    ll->len += 1;
  }
}

void insertSorted(struct LinkedList *ll, int elem) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)), *prev = ll->head, *next = ll->head;
    new_node->data = elem;
    new_node->next = NULL;

    if(ll->head == NULL) {
        ll->head = new_node;
        return;
    }
    while(next->data < elem && next != NULL) {
        prev = next;
        next = next->next;
    }
    new_node->next = prev->next;
    prev->next = new_node;
}

void delete(struct LinkedList *ll, int elem) {
    struct Node *curr = ll->head, *prev = ll->head;

    while(curr != NULL && curr->data != elem) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;

    ll->len--;
    free(curr);
}

int main() {
  int arr[5] = {3, 7, 9, 15, 20};
  struct LinkedList *ll =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));

  insertFromArray(arr, 5, ll);
  display(ll);

  // printf("%d\n", ll->len);
  // printf("%p\n", ll->head);
  // printf("%p\n", ll->tail);
  // printf("%d\n", sum(ll));

  // if (search(ll, 6)) {
  //   printf("6 is present\n");
  // } else {
  //   printf("6 is absent\n");
  // }

  // printf("length before inserting 2 at 0: %d\n", ll->len);
  // insert(ll, 0, 2);
  // insertFirst(ll, 1);
  // display(ll);

  // printf("length before inserting 100 at 6: %d\n", ll->len);
  // insertLast(ll, 200);
  // insert(ll, 5, 900);

  // display(ll);

  // printf("length before inserting 32 at 2: %d\n", ll->len);
  // insert(ll, 2, 32);

  // insertLast(ll, 500);
  // display(ll);
  // printf("length: %d\n", ll->len);

  insertSorted(ll, 8);
  display(ll);

  delete(ll, 8);

  display(ll);

  return 0;
}
