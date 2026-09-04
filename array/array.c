#include <stdio.h>
#include <stdlib.h>

struct Array {
    int arr[10];
    int capacity;
    int len;
};

void push(struct Array *arr, int elem) {
    if (arr->len < arr->capacity)
        arr->arr[arr->len] = elem;
    arr->len += 1;
}

void insert(struct Array *arr, int elem, int index) {
    if (index < 0 || index >= arr->capacity) return;
    for(int i=arr->len;i>index;i--){
        arr->arr[i] = arr->arr[i-1];
    }
    arr->arr[index] = elem;
    arr->len += 1;
}

void delete(struct Array *arr, int index) {
    if (index < 0 || index >= arr->capacity) return;
    for(int i=index;i<arr->len-1;i++){
        arr->arr[i] = arr->arr[i+1];
    }
    arr->len -= 1;
}

void display(struct Array arr) {
    for(int i=0;i<arr.len+1;i++){
        printf(" |%d| ", arr.arr[i]);
    }
    printf("\n");
}

int main() {
    struct Array arr = {{10, 20, 30, 40}, 15, 4};
    // push(&arr, 10);
    // push(&arr, 20);
    // push(&arr, 30);
    // push(&arr, 40);

    // insert(&arr, 5, 1);

    display(arr);
    return 0;
}
