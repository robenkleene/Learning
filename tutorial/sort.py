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

def bucket_sort(alist):
    largest = max(alist)
    length = len(alist)
    size = largest/length

    buckets = [[] for _ in range(length)]
    for i in range(length):
        j = int(alist[i]/size)
        if j != length:
            buckets[j].append(alist[i])
        else:
            buckets[length - 1].append(alist[i])

    for i in range(length):
        insertion_sort(buckets[i])

    result = []
    for i in range(length):
        result = result + buckets[i]

    return result

def insertion_sort(alist):
    for i in range(1, len(alist)):
        temp = alist[i]
        j = i - 1
        while (j >= 0 and temp < alist[j]):
            alist[j + 1] = alist[j]
            j = j - 1
        alist[j + 1] = temp

# Merge Sort
def merge_sort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    lower = merge_sort(arr[:mid])
    higher = merge_sort(arr[mid:])
    i = 0
    j = 0
    result = []
    while i < len(lower) and j < len(higher):
        if lower[i] > higher[j]:
            result.append(higher[j])
            j += 1
        else:
            result.append(lower[i])
            i += 1
    result += lower[i:]
    result += higher[j:]
    return result

arr = [1, 2, 1, 5, 3, 2, 5]
print("arr =", arr)

print("Selection")
result = selection(arr)
print("result =", result)

print("Merge Sort")
result = merge_sort(arr)
print("result =", result)

print("Selection")
quicksort(arr)
print("arr =", arr)
