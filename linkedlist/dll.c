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
    while (temp != NULL) {
        printf("| %d | <-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayRev(struct LinkedList *ll){
    struct Node *temp = ll->tail;
    while (temp != ll->head) {
        printf("| %d | <-> ", temp->data);
        temp = temp->prev;
    }
    printf("| %d | <-> \n", temp->data);
}

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};

    struct LinkedList *ll = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    insertFromArray(arr, 5, ll);

    display(ll);
    displayRev(ll);

    return 0;
}
