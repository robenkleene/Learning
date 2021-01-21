#!/usr/bin/swift

func getCombinations(_ arr1: [Any], _ arr2: [Any]) -> [Any] {
    var result = [(Any, Any)]()
    for item1 in arr1 {
        for item2 in arr2 {
            result.append((item1, item2))
        }
    }
    return result
}

func getPermutations(_ arr1: [Any], _ arr2: [Any]) -> [Any]{
    var result = [(Any, Any)]()
    for item1 in arr1 {
        for item2 in arr2 {
            result.append((item1, item2))
            result.append((item2, item1))
        }
    }

    return result
}

let arr1 = [1, 2, 3, 4]
let arr2 = ["a", "b"]
print("arr1.count = \(arr1.count)")
print("arr1 = \(arr1)")
print("arr2.count = \(arr2.count)")
print("arr2 = \(arr2)")
let combinations = getCombinations(arr1, arr2)
print("combinations.count = \(combinations.count)")
print("combinations = \(combinations)")
let permutations = getPermutations(arr1, arr2)
print("permutations.count = \(permutations.count)")
print("permutations = \(permutations)")
