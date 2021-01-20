#!/usr/bin/env python3

# Insertion Sort
def insertion(arr):
    for i in range(1, len(arr)):
        save = arr[i]
        j = i
        while j > 0 and arr[j - 1] > save:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = save

# Quick Sort
def partition(arr, begin, end):
    pivot = begin
    for i in range(begin+1, end+1):
        if arr[i] <= arr[begin]:
            pivot += 1
            arr[i], arr[pivot] = arr[pivot], arr[i]
    arr[pivot], arr[begin] = arr[begin], arr[pivot]
    return pivot

def quicksort(arr, start = 0, end = None):
    if end is None:
        end = len(arr) - 1
    def _quicksort(arr, start, end):
        if start >= end:
            return
        pivot = partition(arr, start, end)
        _quicksort(arr, start, pivot - 1)
        _quicksort(arr, pivot + 1, end)
    return _quicksort(arr, start, end)

# Selection Sort
def selection(arr):
    for i in range(len(arr)):
        minimum = arr[i]
        index = i
        for j in range(i, len(arr)):
            if arr[j] < minimum:
                minimum = arr[j] 
                index = j
        arr[index] = arr[i]
        arr[i] = minimum
    return arr

# Merge Sort
def merge_sort(arr):
    if len(arr) < 2:
        return arr
    result = []
    mid = int(len(arr) / 2)
    y = merge_sort(arr[:mid])
    z = merge_sort(arr[mid:])
    i = 0
    j = 0
    while i < len(y) and j < len(z):
        if y[i] > z[j]:
            result.append(z[j])
            j += 1
        else:
            result.append(y[i])
            i += 1
    result += y[i:]
    result += z[j:]
    return result

arr = [1, 2, 1, 5, 3, 2, 5]
print("arr =", arr)

print("Selection")
result = selection(arr)
print("result =", result)

print("Selection")
quicksort(arr)
print("arr =", arr)
