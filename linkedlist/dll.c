#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *prev;
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
  ll->tail = head;
  ll->len += 1;

  struct Node *last = head;
  for (int i = 1; i < len; i++) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = arr[i];
    temp->next = NULL;
    temp->prev = last;
    ll->tail = temp;
    last->next = temp;
    last = last->next;

    ll->len += 1;
  }
}

void display(struct LinkedList *ll){
    struct Node *temp = ll->head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("| %d | <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void displayRev(struct LinkedList *ll){
    struct Node *temp = ll->tail;
    printf("NULL <-> ");
    while (temp != ll->head) {
        printf("| %d | <-> ", temp->data);
        temp = temp->prev;
    }
    printf("| %d | <-> NULL\n", temp->data);
}

void insert(struct LinkedList *ll, int elem, int index) {
    if (index > ll->len - 1 || index < 0)
      return;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)), *temp = ll->head;
    new_node->data = elem;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (index == 0) {
        new_node->next = ll->head;
        ll->head->prev = new_node;
        ll->head = new_node;
    } else if (index == ll->len - 1) {
        ll->tail->next = new_node;
        new_node->prev = ll->tail;
        ll->tail = new_node;
    } else {
        int count = 1;
        while(count < index) {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
    ll->len += 1;
}

void delete(struct LinkedList *ll, int elem) {
    struct Node *temp = ll->head, *prev = ll->head;

    if(elem == temp->data) {
        ll->head = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }

     while(temp) {
        if (temp->data == ll->tail->data) {
             ll->tail = prev;
             temp->prev = NULL;
             prev->next = NULL;
             free(temp);
        }
        if(temp->data == elem) {
            prev->next = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
        prev = temp;
        temp = temp->next;
     }
    ll->len -= 1;
}

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};

    struct LinkedList *ll = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    insertFromArray(arr, 5, ll);

    display(ll);
    displayRev(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    insert(ll, 15, 4);
    insert(ll, 1, 0);
    insert(ll, 9, 2);

    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    delete(ll, 1);
    delete(ll, 9);
    delete(ll, 15);

    display(ll);

    printf("head %d\n", ll->head->data);
    printf("tail %d\n", ll->tail->data);
    printf("length %d\n", ll->len);

    return 0;
}
