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

void insert(struct Array *arr, int elem, int index) {
    for(int i=arr->len;i>index;i--){
        arr->ptr[i] = arr->ptr[i-1];
    }
    arr->ptr[index] = elem;
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

    insert(&arr, 5, 1);

    display(arr);

    free(arr.ptr);

    return 0;
}
