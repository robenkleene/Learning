# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        def dfs(node):
            nonlocal ans
            if node:
                if low <= node.val <= high:
                    ans += node.val
                if low < node.val:
                    dfs(node.left)
                if high > node.val:
                    dfs(node.right)
        ans = 0
        dfs(root)
        return ans


