#!/usr/bin/swift

func sortDutchFlagColors(_ arr: [Int]) -> [Int] {
    var arr = arr
    var zerosIndex = 0
    var twosIndex = arr.count - 1
    var i = 0
    while i < twosIndex {
        let val = arr[i]
        switch val {
        case 0:
            arr[i] = arr[zerosIndex]
            arr[zerosIndex] = val
            zerosIndex += 1
            i += 1
        case 2:
            arr[i] = arr[twosIndex]
            arr[twosIndex] = val
            twosIndex -= 1
        default:
            i += 1
        }
    }
    return arr
}

let arr = [1, 0, 2, 2, 1, 1, 0, 0]
print("arr = \(arr)")
let result = sortDutchFlagColors(arr)
print("result = \(result)")
