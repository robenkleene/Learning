#!/usr/bin/swift

class Node<T: Hashable> {
    var value: T
    var key: String
    var next: Node?
    var prev: Node?
    init(key: String, value: T) {
        self.key = key
        self.value = value
    }
}
