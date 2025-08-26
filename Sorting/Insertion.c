#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {100, 20, 19, 13, 12, 22, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("After sorting ");
    printArray(arr, n);

    return 0;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}