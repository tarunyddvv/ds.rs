#include <_time.h>
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
  head->next = head;
  ll->head = head;
  ll->tail = head;
  ll->len += 1;

  struct Node *ptr = head;
  for (int i = 1; i < len; i++) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = arr[i];
    temp->next = ll->tail->next;
    ll->tail = temp;
    ptr->next = temp;
    ptr = ptr->next;

    ll->len += 1;
  }
}

void display(struct LinkedList *ll) {
    struct Node *first = ll->head, *temp = ll->head;

    do {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");
}

int isLoop(struct LinkedList *ll) {
  struct Node *slow = ll->head, *fast = ll->head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return 1;
  }
  return 0;
}

void insert(struct LinkedList *ll, int elem, int index) {
    if (index > ll->len - 1 || index < 0)
      return;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)), *temp = ll->head;
    new_node->data = elem;
    new_node->next = NULL;
    ll->len += 1;

    if (index == 0) {
        ll->tail->next = new_node;
        new_node->next = ll->head;
        ll->head = new_node;
    } else if (index == ll->len - 1) {
        ll->tail->next = new_node;
        new_node->next = ll->head;
        ll->tail = new_node;
    } else {
        int count = 1;
        while(count < index) {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete(struct LinkedList *ll, int elem) {
    struct Node *temp = ll->head, *prev = ll->head;

    if(elem == temp->data) {
        ll->tail->next = temp->next;
        ll->head = temp->next;
        temp->next = NULL;
        free(temp);
    }

     do {
        if(temp->data == elem) {
            prev->next = temp->next;
            temp->next = NULL;
            free(temp);
        }
        if (temp->data == ll->tail->data) {
            ll->tail = prev;
        }
        prev = temp;
        temp = temp->next;
    } while(temp != ll->head && temp != NULL);
    ll->len -= 1;
}

int main()
{
    int arr1[4] = {2, 4, 6, 8};
    struct LinkedList *ll =
        (struct LinkedList *)malloc(sizeof(struct LinkedList));

    insertFromArray(arr1, 4, ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    display(ll);

    insert(ll, 1, 0);
    insert(ll, 3, 5);
    insert(ll, 10, 3);

    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    delete(ll, 3);
    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    delete(ll, 1);
    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    delete(ll, 10);
    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    return 0;
}
