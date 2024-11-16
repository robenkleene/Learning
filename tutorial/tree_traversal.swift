#!/usr/bin/swift

import Foundation

class Node<T>: CustomStringConvertible {
    var left: Node?
    var right: Node?
    var value: T

    init(value: T) {
        self.value = value
    }

    var description: String {
        return "\(value)"
    }

    func chainString(level: Int = 0, isLeft: Bool? = nil) -> String {
        var result = ""
        if let left = left {
            result += left.chainString(level: level + 1, isLeft: true)
        }
        var char = ""
        if let isLeft = isLeft {
            char = isLeft ? "/ " : "\\ "
        }
        let indent = Array<String>(repeating: " ", count: level * 4).joined()
        result += "\(indent)\(char)\(value)\n"
        if let right = right {
            result += right.chainString(level: level + 1, isLeft: false)
        }
        return result
    }
}

class Tree<T>: CustomStringConvertible {
    var root: Node<T>?

    var description: String {
        guard let root = root else {
            return ""
        }
        return root.chainString()
    }

    convenience init(source: [T]) {
        self.init()
        self.root = Tree<T>.makeNodes(from: source)
    }

    static func makeNodes(from arr: [T]) -> Node<T> {
        var source = arr
        let root = Node(value: source.removeFirst())
        var fringe = [root]
        while true {
            let head = fringe.removeFirst()
            guard source.count > 0 else {
                break
            }
            let left = Node(value: source.removeFirst())
            head.left = left
            fringe.append(left)
            guard source.count > 0 else {
                break
            }
            let right = Node(value: source.removeFirst())
            head.right = right
            fringe.append(right)
        }
        return root
    }
}

func dfsIter<T: Equatable>(start: Node<T>, goal: T? = nil) -> [Node<T>] {
    var visited = [Node<T>]()
    var stack = [start]

    while let curr = stack.popLast() {
        visited.append(curr)
        if let goal = goal, curr.value == goal {
            return visited
        }
        if let left = curr.left {
            stack.append(left)
        }
        if let right = curr.right {
            stack.append(right)
        }
    }

    return visited
}

func bfsIter<T: Equatable>(start: Node<T>, goal: T? = nil) -> [Node<T>] {
    var visited = [Node<T>]()
    var queue = [start]

    while queue.count > 0 {
        let curr = queue.removeFirst()
        visited.append(curr)
        if let goal = goal, curr.value == goal {
            return visited
        }
        if let left = curr.left {
            queue.append(left)
        }
        if let right = curr.right {
            queue.append(right)
        }
    }

    return visited
}

func dfsRecu<T: Equatable>(start: Node<T>, goal: T? = nil, visited: [Node<T>]? = nil) -> [Node<T>] {
    var visited = visited ?? [start]
    if let goal = goal, start.value == goal {
        return visited
    }
    if let left = start.left {
        visited += dfsRecu(start: left, goal: goal, visited: [left])
    }
    if let right = start.right {
        visited += dfsRecu(start: right, goal: goal, visited: [right])
    }

    return visited
}

let arr = [3,5,2,1,4,6,7,8,9,10,11,12,13,14]
print("Array")
print(arr)
let tree = Tree(source: arr)
guard let root = tree.root else {
    assertionFailure()
    exit(1)
}
print("Tree")
print(tree)
print("Depth-First")
print("Iterative")
var result = dfsIter(start: root)
print(result)
result = dfsIter(start: root, goal: 6)
print(result)
print("Recursive")
result = dfsRecu(start: root)
print(result)
result = dfsRecu(start: root, goal: 6)
print(result)
print()
print("Breadth-First")
print("Iterative")
result = bfsIter(start: root)
print(result)
result = bfsIter(start: root, goal: 6)
print(result)
