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
        tree = Tree()
        for val in arr:
            tree.insert(val)
        return tree

class RecuLogger:
    """
    RecursiveLogger
    """
    def __init__(self):
        self.level = 0

    def inc(self):
        """
        inc
        """
        self.level += 1

    def print(self, string):
        """
        print
        """
        print("\t" * self.level, self.level, ":", string)

def insert(node, val, logger = RecuLogger()):
    """
    insert
    """
    logger.inc()
    logger.print("call")
    if node is None:
        logger.print(f"returning val={val}")
        return Node(val)

    if val < node.val:
        new = insert(node.left, val, logger)
        logger.print(f"setting node.left new={new}")
        node.left = new
        # node.left = insert(node.left, val, logger)
    else:
        new = insert(node.right, val, logger)
        logger.print(f"setting node.right new={new}")
        node.right = new
        # node.right = insert(node.right, val, logger)
    logger.print(f"returning node={node}")
    return node

def search(node, val):
    """
    search
    """
    if node is None or val == node.val:
        return node
    if val < node.val:
        return search(node.left, val)
    return search(node.right, val)

def main():
    """
    main
    """
    tree = Tree.make([4,2,7,1,3])
    print(tree)
    root = tree.root
    result = search(root, 2)
    print(result.chain_string())
    insert(tree.root, 5)
    print(tree)

main()
