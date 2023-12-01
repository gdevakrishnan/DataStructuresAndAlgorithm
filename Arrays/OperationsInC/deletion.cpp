// Delete an Element in an Array

#include <stdio.h>

int binarySearch(int arr[], int target, int size) {
    int start = 0, end = size - 1, mid;
    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            end = mid - 1;
        }

        else if (arr[mid] < target) {
            start = mid + 1;
        }
    }

    return -1;
}

int deleteAnElement(int arr[], int target, int pos, int size) {
    int i;
    for(i = pos;i < size;i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target= 3, i;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Deletion\n");
    for (i = 0;i < size;i++) {
        printf("%d ", arr[i]);
    }

    int pos = binarySearch(arr, target, size);

    if (pos == -1) {
        printf("\nElement Not Found");
        return 0;
    }

    int n = deleteAnElement(arr, target, pos, size);
    printf("\nAfter Deletion Deletion\n");
    for (i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}