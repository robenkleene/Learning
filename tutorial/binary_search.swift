#!/usr/bin/swift

func bs_iter<T: Comparable>(arr: [T], target: T) -> Int? {
    var start = 0, end = arr.count - 1
    while start <= end {
        let mid = start + end / 2
        let val = arr[mid]
        if target < val {
            end = mid - 1
        } else if target > val {
            start = mid + 1
        } else {
            return mid
        }
    }
    return nil
}


