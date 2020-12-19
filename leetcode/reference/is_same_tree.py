#!/usr/bin/env python3

from collections import deque

class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

    def __repr__(self):
        return self.val

    def chain_string(self, level=0, left=None):
        result = ""
        if self.left != None:
            result += self.left.chain_string(level + 1, True)
        char = '' if left == None else '/' if left else '\\'
        # char = left == None ? '' : left ? '/' : '\\'
        result += ' ' * 4 * level + char + str(self.val) + "\n"
        if self.right != None:
            result += self.right.chain_string(level + 1, False)
        return result

class Tree:
    def __init__(self):
        self.root = None

    def __repr__(self):
        return self.root.chain_string()

def make_tree(arr):
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

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """    
        # p and q are both None
        if not p and not q:
            return True
        # one of p and q is None
        if not q or not p:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.right, q.right) and \
               self.isSameTree(p.left, q.left)

arr1 = [3,5,2,1,4,6,7,8,9,10,11,12,13,14]
tree1 = make_tree(arr1)
tree2 = make_tree(arr1)

result = Solution().isSameTree(tree1.root, tree2.root)
print(result)

arr2 = [3,5,3,1,4,6,7,8,9,10,11,12,13,14]
tree3 = make_tree(arr2)
result = Solution().isSameTree(tree1.root, tree3.root)
print(result)
