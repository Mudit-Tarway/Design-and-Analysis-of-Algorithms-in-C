#include <stdio.h>

void printArr(int temp[], int size) {
    printf("After sorted (Merge Sort): ");
    for(int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

void merge(int arr[], int si, int mid, int ei) {
    int temp[ei - si + 1];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= ei) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= ei) {
        temp[k++] = arr[j++];
    }

    for(int x = 0; x < k; x++) {
        arr[si + x] = temp[x];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main() {
    int size;
    printf("Enter the size of the array = ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size - 1);

    printf("\nFinal Sorted Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}