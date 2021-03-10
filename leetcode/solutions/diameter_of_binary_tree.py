# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        diameter
        """
        ans = 1
        def depth(node, ans):
            if not node:
                return 0, ans
            depth_left, ans = depth(node.left, ans)
            depth_right, ans = depth(node.right, ans)
            ans = max(ans, depth_left + depth_right + 1)
            return max(depth_left, depth_right) + 1, ans

        _, ans = depth(root, ans)
        return ans - 1