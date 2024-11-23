#!/usr/bin/swift

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var values: [Int: Int] = [:];
        for i in 0..<nums.count {
            let num = nums[i]
            let diff = target - num
            if let result = values[diff] {
                return [result, i]
            }
            values[num] = i
        }
        return [];
    }
}

func test(_ nums: [Int], _ target: Int) {
    let solution = Solution();
    print("nums = \(nums)")
    let result = solution.twoSum(nums, target)
    print("result = \(result)")
}

test([2, 7, 11, 15], 9) // [0, 1]
print("")
test([3, 2, 4], 6); // [1, 2]
