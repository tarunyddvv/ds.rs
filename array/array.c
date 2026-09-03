#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *ptr;
    int capacity;
    int len;
};

void push(struct Array *arr, int elem) {
    arr->ptr[arr->len] = elem;
    arr->len += 1;
}

void display(struct Array arr) {
    for(int i=0;i<arr.len;i++){
        printf(" |%d| ", arr.ptr[i]);
    }
    printf("\n");
}

int main() {
    struct Array arr;
    arr.capacity = 4;
    arr.len = 0;

    arr.ptr = (int *)malloc(arr.capacity * sizeof(int));
    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30);
    push(&arr, 40);

    display(arr);

    return 0;
}
