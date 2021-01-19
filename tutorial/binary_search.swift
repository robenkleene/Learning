#!/usr/bin/swift

func bs_iter<T: Comparable>(_ arr: [T], _ target: T) -> Int? {
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


func bs_recu<T: Comparable>(_ arr: [T], _ target: T, start: Int = 0, end: Int = arr.count - 1) -> Int? {
    if start > end {
        return nil
    }

    let mid = (start + end) / 2
    let val = arr[mid]
    if target < val {
        return bs_recu(arr, target, start: start, end: mid - 1)
    } else if target > val {
        return bs_recu(arr, target, start: mid + 1, end: end)
    } else {
        return mid
    }
}

let target = 4
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print("arr =", arr)
var result = bs_iter(arr, 4)
print("result = \(result?.description ?? "")")
result = bs_recu(arr, 4)
print("result = \(result?.description ?? "")")

