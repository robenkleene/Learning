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

def dfs(start, goal=None):
    """
    dfs_iter
    """
    visited, stack = [], [start]
    while stack:
        curr = stack.pop()
        visited.append(curr)
        if goal is not None and curr.val == goal:
            return visited
        if curr.left is not None:
            stack.append(curr.left)
        if curr.right is not None:
            stack.append(curr.right)
    return visited

def bfs(start, goal=None):
    """
    bfs_iter
    """
    visited, queue = [], [start]
    while queue:
        curr = queue.pop(0)
        visited.append(curr)
        if goal is not None and curr.val == goal:
            return visited
        if curr.left is not None:
            queue.append(curr.left)
        if curr.right is not None:
            queue.append(curr.right)
    return visited

def dfs_recu(curr, goal=None, visited=None):
    """
    dfs_recu
    """
    visited = visited or [curr]
    if goal is not None and curr.val == goal:
        return visited
    if curr.left is not None:
        visited += dfs_recu(curr.left, goal, [curr.left])
    if curr.right is not None:
        visited += dfs_recu(curr.right, goal, [curr.right])
    return visited

def diameter(root):
    """
    diameter
    """
    def depth_diameter(node, result = 1):
        if not node:
            return 0, result
        depth_left, result = depth_diameter(node.left, result)
        depth_right, result = depth_diameter(node.right, result)
        result = max(result, depth_left + depth_right + 1)
        return max(depth_left, depth_right) + 1, result

    _, result = depth_diameter(root)
    return result - 1

def depth(node):
    """
    depth
    """
    if node is None:
        return 0
    left_depth = depth(node.left)
    right_depth = depth(node.right)
    return max(left_depth, right_depth) + 1

def main():
    """
    main
    """
    tree = Tree.make([1, 2, 3, 4, 5])
    print(tree)
    result = diameter(tree.root)
    print("diameter =", result)
    result = depth(tree.root)
    print("depth =", result)

main()
