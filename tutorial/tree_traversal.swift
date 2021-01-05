#!/usr/bin/swift

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
        let indent = Array<String>(repeating: " ", count: level * 4)
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

    static func make<T>(from arr: [T]) -> Tree<T> {
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
            fringe.append(right)
        }
        let tree = Tree<T>()
        tree.root = root
        return tree
    }
}

