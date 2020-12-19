class TreeNode<T> {
    var left: TreeNode?
    var right: TreeNode?
    var value: T
    init(value: T) {
        self.value = value
    }
}

extension TreeNode: CustomStringConvertible {
    var description: String {
        return "\(value)"
    }
}

class BinaryTree<T> {
    var root: TreeNode<T>?
    init(root: TreeNode<T>? = nil) {
        self.root = root
    }
}

extension BinaryTree: CustomStringConvertible {
    func generateDescription(for node: TreeNode<T>, level: Int = 0) -> String {
        var description = ""
        if let left = node.left {
            description += generateDescription(for: left, level: level + 1)
        }
        description += "\(String(repeating:" ", count: 4 * level)) -> \(node) + \n"
        if let right = node.right {
            description += generateDescription(for: right, level: level + 1)
        }
    }

    var description: String {
        guard let root = root else {
            return "nil"
        }
        return generateDescription(for: root)
    }
}

func makeTree<T>(_ arr: [T]) -> BinaryTree<T> {
    if arr.count < 1 {
        return BinaryTree<T>()
    }
    var items = arr
    let item = items.removeFirst()
    let root = TreeNode(value: item)
    var fringe = [root]
    var left = true
    for item in items {
        let head = fringe.removeFirst()
        let node = TreeNode(value: item)
        if left {
            head.left = node
        } else {
            head.right = node
        }
        left = !left
    }

    let tree = BinaryTree<T>()
    tree.root = root
    return tree
}

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
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        
    }
}
