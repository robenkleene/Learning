#!/usr/bin/env python3

# Iterative
def bs_iter(arr, target):
    beg, end = 0, len(arr) - 1
    while beg <= end:
        mid = (beg + end) // 2
        if target < arr[mid]:
            end = mid - 1
        elif target > arr[mid]:
            beg = mid + 1
        else:
            return mid
    return None

def binary_search_iterative(arr, elem):
    start, end = 0, (len(arr) - 1)
    while start <= end:
        mid = (start + end) // 2
        if elem == arr[mid]:
            return mid
        if elem < arr[mid]:
            end = mid - 1
        else:  # elem > arr[mid]
            start = mid + 1

    return False

def binary_search_recursive(arr, elem, start=0, end=None):
    if end is None:
        end = len(arr) - 1
    if start > end:
        return False

    mid = (start + end) // 2
    if elem == arr[mid]:
        return mid
    if elem < arr[mid]:
        return binary_search_recursive(arr, elem, start, mid-1)
    # elem > arr[mid]
    return binary_search_recursive(arr, elem, mid+1, end)

target = 4
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
result = bs_iter(arr, 4)
print("arr =", arr)
print("result =", result)
