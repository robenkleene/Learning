#!/usr/bin/env python3

def bs_iter(arr, target):
    start, end = 0, len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        value = arr[mid]
        if target < value:
            end = mid - 1
        elif target > value:
            start = mid + 1
        else:
            return mid
    return None

def bs_recu(arr, target, start=0, end=None):
    if end is None:
        end = len(arr) - 1
    if start > end:
        return None

    mid = (start + end) // 2
    value = arr[mid]
    if target < value:
        return bs_recu(arr, target, start, mid - 1)
    elif target > value:
        return bs_recu(arr, target, mid + 1, end)
    else:
        return mid

target = 4
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print("arr =", arr)
result = bs_iter(arr, 4)
print("result =", result)
result = bs_recu(arr, 4)
print("result =", result)
