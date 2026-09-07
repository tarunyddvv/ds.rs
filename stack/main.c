#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int* arr;
};

void push(struct Stack *st, int elem) {
    st->top++;
    st->arr[st->top] = elem;
}

void display(struct Stack *st) {
    for(int i=0;i<st->size;i++){
        printf("| %d | ", st->arr[i]);
    }
    printf("\n");
}

int main()
{
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

    display(st);

    return 0;
}
