#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int pi = partition(arr, p, r);
        quickSort(arr, p, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {32, 20, 1, 100, 38, 23, -12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}