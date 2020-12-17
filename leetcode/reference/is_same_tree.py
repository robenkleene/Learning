#!/usr/bin/env python3

from collections import deque

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def __repr__(self):
        return self.data

    def chain_string(self):
        if node != None:
            chain_string(node.left, level + 1)
            print(' ' * 4 * level + '->', node.value)
            chain_string(node.right, level + 1)

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

arr = [3,5,2,1,4,6,7,8,9,10,11,12,13,14]
tree = make_tree(arr)
print(tree)

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
