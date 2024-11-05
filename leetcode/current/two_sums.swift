#!/usr/bin/swift

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {

    }
}

func test(_ nums: [Int], target: Int) {
    let solution = Solution();
    print("nums = \(nums)")
    let result = solution.twoSum(nums, target)
    print("result = \(result)")
}

test([2, 7, 11, 15], 9)
print("")
test([3, 2, 4], 6);
