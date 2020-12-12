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

extension Node  {
    func chainString() -> String {
        var values = [String]()
        var cur: Node? = self
        while cur != nil {
            if let cur = cur {
                values.append("\(cur)")
            }
            cur = cur?.next
        }
        return values.joined(separator: " -> ")
    }
}

class LinkedList<T: Equatable> {
  var head = Node<T>()
}

extension LinkedList: CustomStringConvertible {
    var description: String {
        return self.head.chainString()
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
        guard let head = head else {
            return nil
        }
        if head.next == nil {
            return head
        }
        var oldTail = head
        var n = 1
        while (oldTail.next != nil) {
            guard let next = oldTail.next else {
                assertionFailure()
                break
            }
            oldTail = next
            n += 1
        }
        oldTail.next = head

        var newTail = head

        for _ in 0..<n - k % n - 1 {
            guard let next = newTail.next else {
                assertionFailure()
                break
            }
            newTail = next
        }
        guard let next = newTail.next else {
            assertionFailure()
            return nil
        }
        let newHead = next
        newTail.next = nil
        return newHead
    }
}

let arr = [1, 2, 3, 4, 5]
let llist = makeList(from: arr)
print("llist = \(llist)")
let head = llist.head
let k = 2
let result = Solution().rotateRight(head, k)
print("result = \(result?.chainString() ?? "nil")")
