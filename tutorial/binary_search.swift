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

let target = 4
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print("arr =", arr)
let result = bs_iter(arr, 4)
print("result = \(result?.description ?? "")")
// result = bs_recu(arr, 4)
// print("result =", result)

