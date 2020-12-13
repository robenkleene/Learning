#!/usr/bin/swift

import Foundation

class Solution {
    func sortColors(_ nums: inout [Int]) {
        var curr = 0
        var p0 = 0
        var p2 = nums.count - 1
        while curr <= p2 {
            if nums[curr] == 0 {
                (nums[p0], nums[curr]) = (nums[curr], nums[p0])
                p0 += 1
                curr += 1
            } else if nums[curr] == 2 {
                (nums[curr], nums[p2]) = (nums[p2], nums[curr])
                p2 -= 1
            } else {
                curr += 1
            }
        }
    }
}

var nums = [2, 0, 2, 1, 1, 0]
print(nums)
Solution().sortColors(&nums)
print(nums)
