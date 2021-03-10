class Node():
    """
    Node
    """
    def __init__(self):
        self.key = None
        self.value = None
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.size = 0
        self.capacity = capacity
        self.head, self.tail = Node(), Node()
        self.head.next = self.tail
        self.tail.prev = self.head


    def get(self, key: int) -> int:
        """
        get
        """
        node = self.cache.get(key, None)
        if not node:
            return None
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        """
        put
        """
        node = self.cache.get(key)

        if not node:
            new = Node()
            new.key = key
            new.value = value
            self.cache[key] = new
            self._add(new)
            self.size += 1
            if self.size > self.capacity:
                tail = self._pop()
                del self.cache[tail.key]
                self.size -= 1
        else:
            node.value = value
            self._move_to_head(node)

    def _add(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _remove(self, node):
        prev = node.prev
        new = node.next
        prev.next = new
        new.prev = prev

    def _move_to_head(self, node):
        self._remove(node)
        self._add(node)

    def _pop(self):
        node = self.tail.prev
        self._remove(node)
        return node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
