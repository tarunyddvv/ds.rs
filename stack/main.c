#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int capacity;
  int top;
  int *arr;
};

int isFull(struct Stack *st) {
  if (st->top == st->capacity - 1)
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
    printf("stack overflow\n");
    return;
  }
  st->top++;
  st->arr[st->top] = elem;
}

int pop(struct Stack *st) {
  if (st->top == -1) {
    printf("stack underflow\n");
    return -1;
  }

  int elem = st->arr[st->top];
  st->arr[st->top] = 0;
  st->top--;

  return elem;
}

int peek(struct Stack *st) {
  if (st->top == -1) {
    printf("stack underflow\n");
    return -1;
  }

  return st->arr[st->top];
}

int top(struct Stack *st) {
  if (isEmpty(st)) {
    printf("stack is empty\n");
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
  st->capacity = 5;
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

  // printf("removed elem: %d\n", pop(st));

  // printf("removed elem: %d\n", pop(st));

  // printf("removed elem: %d\n", pop(st));

  // printf("removed elem: %d\n", pop(st));

  // printf("removed elem: %d\n", pop(st));

  printf("elem at top is: %d\n", peek(st));

  printf("removed elem: %d\n", pop(st));

  printf("elem at top is: %d\n", peek(st));

  free(st);
  free(arr);

  return 0;
}
