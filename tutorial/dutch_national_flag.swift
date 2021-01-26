#!/usr/bin/swift

func sortDutchFlagColors(arr: [Int]) {
    var arr = arr
    for i in 0..<arr.count {
        var zerosCount = 0
        var twosCount = 0
        let val = arr[i]
        switch i {
        case 0:
            zerosCount += 1
        case 2:
            twosCount += 1
            let index = arr.count - 1 - twosCount
            arr[i] = arr[index]
            arr[index] = val
        default:
            break
        }
    }
}
