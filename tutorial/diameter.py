#!/usr/bin/env python3

"""
Diameter
"""

from collections import deque

class Node:
    """
    Node
    """
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

    def __repr__(self):
        return str(self.val)

    def chain_string(self, level=0, is_left=None):
        """
        Node children to string
        """
        result = ""
        if self.left is not None:
            result += self.left.chain_string(level + 1, True)
        char = '' if is_left is None else '/ ' if is_left else '\\ '
        result += ' ' * 4 * level + char + str(self.val) + "\n"
        if self.right is not None:
            result += self.right.chain_string(level + 1, False)
        return result

class Tree:
    """
    Tree
    """
    def __init__(self):
        self.root = None

    def __repr__(self):
        return self.root.chain_string()

    @staticmethod
    def make(arr):
        """
        Make from string
        """
        n = iter(arr)
        root = Node(next(n))
        fringe = deque([root])
        while True:
            head = fringe.popleft()
            try:
                head.left = Node(next(n))
                fringe.append(head.left)
                head.right = Node(next(n))
                fringe.append(head.right)
            except StopIteration:
                break
        tree = Tree()
        tree.root = root
        return tree

# def diameter(root):
#     ans = 1
#     def depth(node, ans):
#         if not node: return 0
#         L = depth(node.left, ans)
#         R = depth(node.right, ans)
#         ans = max(ans, L + R + 1)
#         return max(L, R) + 1

#     depth(root, ans)
#     return ans - 1

#          1
#         / \
#        2   3
#       / \
#      4   5

tree = Tree.make([1, 2, 3, 4, 5])
print(tree)
# result = diameter(tree.root)
# print(result)
