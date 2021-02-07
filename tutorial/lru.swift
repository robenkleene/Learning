#!/usr/bin/swift

class Node<Key: Hashable, Value> {
    var value: Value?
    var key: Key?
    var next: Node?
    var prev: Node?
}

struct LRUCache<Key: Hashable, Value> {
    typealias NodeType = Node<Key, Value>
    var cache = [Key: NodeType]()
    var size = 0
    let capacity: Int
    let head = NodeType()
    let tail = NodeType()
    init(capacity: Int) {
        self.capacity = capacity
        head.next = tail
        tail.prev = head
    }

    private func add(_ node: NodeType) {
        node.prev = head
        node.next = head.next
        head.next?.prev = node
        head.next = node
    }

    private func remove(_ node: NodeType) {
        guard let prev = node.prev, let next = node.next else {
            return
        }
        prev.next = next
        next.prev = prev
    }

    private func moveToHead(_ node: NodeType) {
        remove(node)
        add(node)
    }

    private func pop() -> NodeType? {
        guard let node = tail.prev, node !== head else {
            return nil
        }
        remove(node)
        return node
    }

    func value(for key: Key) -> Value? {
        guard let node = cache[key] else {
            return nil
        }
        moveToHead(node)
        return node.value
    }
}
