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
    for(int i=1;i<len;i++){
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
    while(temp != NULL) {
        printf("| %d |->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int sum(struct LinkedList *ll) {
    struct Node *temp = ll->head;
    int sum = 0;
    while(temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int max(struct LinkedList *ll) {
    struct Node *temp = ll->head;
    int max = temp->data;
    while(temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

int min(struct LinkedList *ll) {
    struct Node *temp = ll->head;
    int min = temp->data;
    while(temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}

int main()
{
    int arr[5] = {8, 3 , 7, 12, 9};
    struct LinkedList *ll = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    insertFromArray(arr, 5, ll);
    display(ll);

    printf("%d\n", ll->len);
    printf("%p\n", ll->head);
    printf("%p\n", ll->tail);
    printf("%d\n", sum(ll));



    return 0;
}
