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

int main()
{
    int arr1[4] = {2, 4, 6, 8};
    struct LinkedList *ll =
        (struct LinkedList *)malloc(sizeof(struct LinkedList));

    insertFromArray(arr1, 4, ll);

    printf("is loop %d\n", isLoop(ll));

    display(ll);
    return 0;
}
