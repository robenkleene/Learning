#!/usr/bin/swift

import Foundation

typealias ListNode = Node<Int>

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
        var cur: Node? = head
        while cur != nil {
            if let cur = cur {
                values.append("\(cur)")
            }
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
    return llist
}

class Solution {
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        return ListNode()
    }
}

let arr = [1, 2, 3, 4, 5]
let llist = makeList(from: arr)
print("llist = \(llist)")
let head = llist.head
let k = 2
let result = Solution().rotateRight(head, k)
print("result = \(result as Optional)")
