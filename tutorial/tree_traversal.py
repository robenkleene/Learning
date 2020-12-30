#!/usr/bin/env python3

from collections import deque

class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

    def __repr__(self):
        return str(self.val)

    def chain_string(self, level=0, left=None):
        result = ""
        if self.left != None:
            result += self.left.chain_string(level + 1, True)
        char = '' if left == None else '/ ' if left else '\\ '
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
        vertex = stack.pop()
        if goal != None and vertex.val == goal:
            visited.append(vertex)
            return visited
        if vertex not in visited:
            visited.append(vertex)
            children = set()
            if vertex.left != None:
                children.add(vertex.left)
            if vertex.right != None:
                children.add(vertex.right)
            stack.extend(children - set(visited))
    return visited

def dfs_recu(start, goal=None):
    path = [start]
    return dfs_recu_impl(start, goal, [start])

def dfs_recu_impl(curr, goal, path):
    if goal != None and curr == goal:
        return path
    if curr.left != None:
        return dfs_recu_impl(curr.left, goal, path + [curr.left])
    if curr.right != None:
        return dfs_recu_impl(curr.right, goal, path + [curr.right])
    return path

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
