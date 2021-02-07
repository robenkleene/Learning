#!/usr/bin/swift

class Node<Key: Hashable, Value> {
    var value: Value?
    var key: Key?
    var next: Node?
    var prev: Node?
}

class LRUCache<Key: Hashable, Value> {
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

    func set(value: Value, for key: Key) {
        guard let node = cache[key] else {
            let new = NodeType()
            new.key = key
            new.value = value
            cache[key] = new
            add(new)
            size += 1
            if size > capacity, let node = pop(), let key = node.key {
                cache.removeValue(forKey: key)
                size -= 1
            }
            return
        }
        node.value = value
        moveToHead(node)
    }
}


let lru = LRUCache<Int, Int>(capacity: 2)
lru.set(value: 1, for: 1)
lru.set(value: 2, for: 2)
print(lru.value(for: 1) ?? "")
lru.set(value: 3, for: 3)
print(lru.value(for: 2))
lru.set(value: 4, for: 4)
print(lru.value(for: 1) ?? "")
print(lru.value(for: 3) ?? "")
print(lru.value(for: 4) ?? "")
