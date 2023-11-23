""" 
    Problem Statement: Find an element in an array (list) using Binary Search Tree in python
"""

import math

def searching(arr, n, k):
    left = 0
    right = n - 1
    step = 1;

    while (left <= right):
        mid = math.floor((left + right) / 2)

        if (arr[mid] == k):
            print("No. Of Steps: ", step)
            print("index: ", mid)
            return

        elif (arr[mid] < k):
            step += 1
            left = mid + 1

        else:
            step += 1
            right = mid - 1

    print(k, "Not Found in the given Array")

searching([1, 2, 3, 4, 5], 5, 5)