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
def partition(array, begin, end):
    pivot = begin
    for i in range(begin+1, end+1):
        if array[i] <= array[begin]:
            pivot += 1
            array[i], array[pivot] = array[pivot], array[i]
    array[pivot], array[begin] = array[begin], array[pivot]
    return pivot

def quicksort(array, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    def _quicksort(array, begin, end):
        if begin >= end:
            return
        pivot = partition(array, begin, end)
        _quicksort(array, begin, pivot-1)
        _quicksort(array, pivot+1, end)
    return _quicksort(array, begin, end)

# Selection Sort
def selection(arr):
    for i in range(len(arr)):
        # lowest, index = min((lowest, index) for (index, lowest) in enumerate(arr))
        # for j in range(i, len(arr)):
        #     arr[j]
        lowest = min(arr[i:])
        index = arr[i:].index(lowest) + i
        arr[index] = arr[i]
        arr[i] = lowest
    return arr

arr = [1, 2, 1, 5, 3, 2, 5]
print("arr =", arr)
result = selection(arr)
print("result =", result)
