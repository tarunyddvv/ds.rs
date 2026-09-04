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

int linearSearch(struct Array arr, int elem) {
    for(int i=0;i<arr.len;i++){
        if(arr.arr[i] == elem){
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array arr, int elem) {
    int l=0, h=arr.len-1, mid = 0;
    while(l<=h){
        mid=(l+h)/2;
        if(arr.arr[mid] == elem) {
            return mid;
        } else if (elem < arr.arr[mid]){
            h = mid-1;
        } else {
            l = mid+1;
        }
    }

    return -1;
}

int main() {
    struct Array arr = {{10, 20, 30, 40}, 15, 4};
    // push(&arr, 10);
    // push(&arr, 20);
    // push(&arr, 30);
    // push(&arr, 40);

    // insert(&arr, 5, 1);

    display(arr);

    printf("elem 30 is at index: %d\n", linearSearch(arr, 30));
    printf("elem 30 is at index: %d\n", binarySearch(arr, 30));
    return 0;
}
