#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Stack {
  int capacity;
  int top;
  struct TNode **arr;
};

int isFull(struct Stack *st);

int isEmptyS(struct Stack *st);

void push(struct Stack *st, struct TNode *elem);

struct TNode* pop(struct Stack *st);

struct TNode* peek(struct Stack *st);

struct TNode* top(struct Stack *st);

#endif
