/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func rangeSumBST(_ root: TreeNode?, _ low: Int, _ high: Int) -> Int {
        func rangeSumRecu(node: TreeNode, low: Int, high: Int, sum: inout Int) {
            if node.val >= low, node.val <= high {
                sum += node.val
            }
            if low < node.val, let node = node.left {
                rangeSumRecu(node: node, low: low, high: high, sum: &sum)
            }
            if high > node.val, let node = node.right {
                rangeSumRecu(node: node, low: low, high: high, sum: &sum)
            }

        }
        var sum = 0
        guard let root = root else {
            return sum
        }
        rangeSumRecu(node: root, low: low, high: high, sum: &sum)
        return sum
    }
}
