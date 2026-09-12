#include "stack.h"

int isFull(struct Stack *st) {
  if (st->top == st->capacity - 1)
    return 1;
  return 0;
}

int isEmptyS(struct Stack *st) {
  if (st->top == -1)
    return 1;
  return 0;
}

void push(struct Stack *st, struct TNode *elem) {
  if (isFull(st)) {
    printf("stack overflow\n");
    return;
  }
  st->top++;
  st->arr[st->top] = elem;
}

struct TNode* pop(struct Stack *st) {
  if (st->top == -1) {
    printf("stack underflow\n");
    return NULL;
  }

  struct TNode* elem = st->arr[st->top];
  st->arr[st->top] = NULL;
  st->top--;

  return elem;
}

struct TNode* peek(struct Stack *st) {
  if (st->top == -1) {
    printf("stack underflow\n");
    return NULL;
  }

  return st->arr[st->top];
}

struct TNode* top(struct Stack *st) {
  if (isEmptyS(st)) {
    printf("stack is empty\n");
    return NULL;
  }

  return st->arr[st->top];
}
