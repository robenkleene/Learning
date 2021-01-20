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

def quicksort(arr, start=0, end=None):
    if end is None:
        end = len(arr) - 1
    def _quicksort(array, start, end):
        if start >= end:
            return
        pivot = partition(array, start, end)
        _quicksort(array, start, pivot - 1)
        _quicksort(array, pivot + 1, end)
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

arr = [1, 2, 1, 5, 3, 2, 5]
print("arr =", arr)
result = selection(arr)
print("result =", result)
