#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int size;
  int top;
  int *arr;
};

int isFull(struct Stack *st) {
  if (st->top == st->size - 1)
    return 1;
  return 0;
}

int isEmpty(struct Stack *st) {
  if (st->top == -1)
    return 1;
  return 0;
}

void push(struct Stack *st, int elem) {
  if (isFull(st)) {
    printf("stack is full\n");
    return;
  }
  st->top++;
  st->arr[st->top] = elem;
}

int pop(struct Stack *st) {
    if(st->top == -1) {
        printf("stack is empty");
        free(st);
    }

    int elem = st->arr[st->top];
    st->arr[st->top] = 0;
    st->top--;

    return elem;
}

int top(struct Stack *st) {
  if (isEmpty(st)) {
    printf("stack is empty");
    return -1;
  }

  return st->arr[st->top];
}

void display(struct Stack *st) {
  for (int i = 0; i <= st->top; i++) {
    printf("| %d | ", st->arr[i]);
  }
  printf("\n");
}

int main() {
  struct Stack *st = (struct Stack *)malloc(5 * sizeof(int));

  int *arr = (int *)malloc(5 * sizeof(int));
  st->size = 5;
  st->top = -1;
  st->arr = arr;

  push(st, 1);
  push(st, 2);
  push(st, 3);
  push(st, 4);
  push(st, 5);
  push(st, 6);

  display(st);

  printf("%d\n", top(st));

  printf("removed elem: %d\n", pop(st));

  printf("removed elem: %d\n", pop(st));

  display(st);

  free(arr);
  free(st);

  return 0;
}
