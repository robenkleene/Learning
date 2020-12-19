#!/usr/bin/swift

class ListNode<T> {
    var value: T
    var next: ListNode?

    init(value: T) {
        self.value = value
    }
}

extension ListNode: CustomStringConvertible {
    var description: String {
        return "\(value)"
    }
}

extension ListNode {
    func chainString() -> String {
        var values = [String]()
        var cur: ListNode? = self
        while cur != nil {
            if let cur = cur {
                values.append("\(cur)")
            }
            cur = cur?.next
        }
        return values.joined(separator: " -> ")
    }
}

class LinkedList<T> {
    var head: ListNode<T>?
    init(head: ListNode<T>? = nil) {
        self.head = head
    }
}

extension LinkedList: CustomStringConvertible {
    var description: String {
        guard let head = head else {
            return "nil"
        }
        return head.chainString()
    }
}

func makeList<T>(from array: [T]) -> LinkedList<T> {
    let llist = LinkedList<T>()
    var current: ListNode<T>?
    for item in array {
        let node = ListNode<T>(value: item)
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
    func rotateRight(_ head: ListNode<Int>?, _ k: Int) -> ListNode<Int>? {
        guard let head = head else {
            return nil
        }
        if head.next == nil {
            return head
        }
        var oldTail = head
        var n = 1
        while oldTail.next != nil {
            guard let next = oldTail.next else {
                assertionFailure()
                break
            }
            oldTail = next
            n += 1
        }
        oldTail.next = head

        var newTail = head

        for _ in 0 ..< n - k % n - 1 {
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
