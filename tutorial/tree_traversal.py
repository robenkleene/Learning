#!/usr/bin/env python3

from collections import deque

class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

    def __repr__(self):
        return str(self.val)

    def chain_string(self, level=0, is_left=None):
        result = ""
        if self.left != None:
            result += self.left.chain_string(level + 1, True)
        char = '' if is_left == None else '/ ' if is_left else '\\ '
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

def dfs_iter(start, goal=None):
    visited, stack = [], [start]
    while stack:
        curr = stack.pop()
        visited.append(curr)
        if goal != None and curr.val == goal:
            return visited
        if curr.left != None:
            stack.append(curr.left)
        if curr.right != None:
            stack.append(curr.right)
    return visited

def bfs_iter(start, goal=None):
    visited, queue = [], [start]
    while queue:
        curr = queue.pop(0)
        visited.append(curr)
        if goal != None and curr.val == goal:
            return visited
        if curr.left != None:
            queue.append(curr.left)
        if curr.right != None:
            queue.append(curr.right)
    return visited

def dfs_recu(curr, goal=None, visited=None):
    if visited == None:
        visited = [curr]
    if goal != None and curr.val == goal:
        return visited
    if curr.left != None:
        visited += dfs_recu(curr.left, goal, [curr.left])
    if curr.right != None:
        visited += dfs_recu(curr.right, goal, [curr.right])
    return visited

arr = [3,5,2,1,4,6,7,8,9,10,11,12,13,14]
tree = make_tree(arr)

print(tree)
print("Depth-First")
print("Iterative")
result = dfs_iter(tree.root)
print(result)
result = dfs_iter(tree.root, 6)
print(result)
print("Recursive")
result = dfs_recu(tree.root)
print(result)
result = dfs_recu(tree.root, 6)
print(result)
print()
print("Breadth-First")
print("Iterative")
result = bfs_iter(tree.root)
print(result)
result = bfs_iter(tree.root, 6)
print(result)
