#!/usr/bin/env python3

"""
tree
"""

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

    def insert(self, val) -> Node:
        """
        insert
        """

        def insert_recu(val, node):
            if node is None:
                return Node(val)

            if val > node.val:
                node.right = insert_recu(val, node.right)
            else:
                node.left = insert_recu(val, node.left)
            return node

        if self.root is None:
            self.root = Node(val)
            return self.root
        return insert_recu(val, self.root)

    @staticmethod
    def make(arr):
        """
        Make from string
        """
        tree = Tree()
        for val in arr:
            tree.insert(val)
        return tree

def insert(val, node):
    if node is None:
        return Node(val)

    if val > node.val:
        node.right = insert(val, node.right)
    else:
        node.left = insert(val, node.left)
    return node

def search(self, val):
    """
    search
    """
    def search_recu(val, node):
        if node is None or val == node.val:
            return node
        if val < node.val:
            return search_recu(node.left, val)
        return search_recu(node.right, val)
    return search_recu(val, self.root)


def main():
    """
    main
    """
    tree = Tree.make([4,2,7,1,3])
    print(tree)
    tree = Tree.make([4,2,7,1,3])
    print(tree)

main()
