#!/usr/bin/swift

class Node<Key: Hashable, Value> {
    var value: Value?
    var key: Key?
    var next: Node?
    var prev: Node?
}

struct LRUCache<Key: Hashable, Value> {
    var cache = [Key: Value]()
    var size = 0
    let capacity: Int
    let head = Node<Key, Value>()
    let tail = Node<Key, Value>()
    init(capacity: Int) {
        self.capacity = capacity
        head.next = tail
        tail.next = head
    }
}
