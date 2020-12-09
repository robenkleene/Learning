class Node<T: Equatable> {
    var value: T? = nil
    var next: Node? = nil
}

class LinkedList<T: Equatable> {
  var head = Node<T>()
}

extension LinkedList: CustomStringConvertible {
    var description: String {
        return "Got here"
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
