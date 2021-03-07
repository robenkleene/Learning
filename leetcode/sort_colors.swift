class Solution {
    func sortColors(_ nums: inout [Int]) {
        var curr = 0
        var p0 = 0
        var p2 = nums.count - 1
        while curr <= p2 {
            switch nums[curr] {
                case 0:
                    if p0 != curr {
                        (nums[p0], nums[curr]) = (nums[curr], nums[p0])
                    }
                    p0 += 1
                    curr += 1
                case 2:
                    (nums[curr], nums[p2]) = (nums[p2], nums[curr])
                    p2 -= 1
                default:
                    curr += 1
            }
        }
    }
}
