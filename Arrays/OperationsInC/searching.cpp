#include <stdio.h>

int searchAnElement(int arr[], int target, int size) {
    for (int i = 0;i < size;i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = searchAnElement(arr, target, size);

    (result == -1) ? printf("The Element is not found in this array") : printf("The Element is found in an index of %d", result);

    return 0;
}