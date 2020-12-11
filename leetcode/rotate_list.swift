#!/usr/bin/swift

import Foundation

class Node<T: Equatable> {
    var value: T? = nil
    var next: Node? = nil
}

extension Node: CustomStringConvertible {
    var description: String {
        guard let value = value else {
            return "nil"
        }
        return "\(value)"
    }
}

class LinkedList<T: Equatable> {
  var head = Node<T>()
}

extension LinkedList: CustomStringConvertible {
    var description: String {
        var values = [String]()
        var cur: Node? = self.head
        while cur != nil {
            values.append("\(self)")
            cur = cur?.next
        }
        return values.joined(separator: " -> ")
    }
}

func makeList<T: Equatable>(from array: [T]) -> LinkedList<T> {
    let llist = LinkedList<T>()
    var current: Node<T>?
    for item in array {
        let node = Node<T>()
        node.value = item
        if let current = current {
            current.next = node
        } else {
            llist.head = node
        }
        current = node
    }
    return LinkedList<T>()
}

let arr = [1, 2, 3, 4, 5]
let llist = makeList(from: arr)
print("llist = \(llist)")
