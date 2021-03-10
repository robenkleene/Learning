class Node {
    var value: Int?
    var key: Int?
    var next: Node?
    var prev: Node?
}

class LRUCache {
    var cache = [Int: Node]()
    var size = 0
    let capacity: Int
    let head = Node()
    let tail = Node()

    init(_ capacity: Int) {
        self.capacity = capacity
        head.next = tail
        tail.prev = head
    }

    func get(_ key: Int) -> Int {
        guard
            let node = cache[key],
            let value = node.value else {
            return -1
        }
        moveToHead(node)
        return value
    }

    func put(_ key: Int, _ value: Int) {
        guard let node = cache[key] else {
            let new = Node()
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

    private func add(_ node: Node) {
        node.prev = head
        node.next = head.next
        head.next?.prev = node
        head.next = node
    }

    private func remove(_ node: Node) {
        guard let prev = node.prev, let next = node.next else {
            return
        }
        prev.next = next
        next.prev = prev
    }

    private func moveToHead(_ node: Node) {
        remove(node)
        add(node)
    }

    private func pop() -> Node? {
        guard let node = tail.prev, node !== head else {
            return nil
        }
        remove(node)
        return node
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache(capacity)
 * let ret_1: Int = obj.get(key)
 * obj.put(key, value)
 */
