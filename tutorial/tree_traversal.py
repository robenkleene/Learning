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

def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend([vertex.left, vertex.right] - visited)
    return visited

arr = [3,5,2,1,4,6,7,8,9,10,11,12,13,14]
tree = make_tree(arr)
result = dfs(tree, tree.root)
print("result = ", result)
