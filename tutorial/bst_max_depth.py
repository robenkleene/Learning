#!/usr/bin/env python3

"""
tree
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

class BinaryTree:
    """
    BinaryTree
    """
    def __init__(self):
        self.root = None

    def __repr__(self):
        return self.root.chain_string()

    def insert(self, val):
        """
        insert
        """
        def insert_recu(node, val):
            if node is None:
                return Node(val)

            if val > node.val:
                node.right = insert_recu(node.right, val)
            else:
                node.left = insert_recu(node.left, val)
            return node

        if self.root is None:
            self.root = Node(val)
            return self.root
        return insert_recu(self.root, val)

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
                value = next(n)
                if value is not None:
                    head.left = Node(value)
                fringe.append(head.left)
                value = next(n)
                if value is not None:
                    head.right = Node(value)
                fringe.append(head.right)
            except StopIteration:
                break
        tree = BinaryTree()
        tree.root = root
        return tree


def max_depth(node):
    """
    max_depth
    """
    if node is None:
        return 0
    left_height = max_depth(node.left)
    right_height = max_depth(node.right)
    return max(left_height, right_height) + 1

def main():
    """
    main
    """
    tree = BinaryTree.make([3,9,20,None,None,15,7])
    print(tree)
    result = max_depth(tree.root)
    print(result)

main()
