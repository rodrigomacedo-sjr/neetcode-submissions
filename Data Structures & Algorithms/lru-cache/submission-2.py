class Node:
    __slots__ = ('key', 'val', 'pv', 'nx')
    def __init__(self, val, key, pv = None, nx = None):
        self.val = val
        self.key = key
        self.pv = pv
        self.nx = nx

class LRUCache:
    def __init__(self, capacity: int):
        self.head = Node(0, 0)
        self.tail = Node(0, 0, self.head)
        self.head.nx = self.tail

        self.map = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if not key in self.map:
            return -1
        node = self.map[key]

        self._remove(node)
        self._add(node)
        return node.val
        

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.map[key].val = value
            self._remove(self.map[key])
        else:
            self.map[key] = Node(value, key)
        self._add(self.map[key])

        if len(self.map) <= self.capacity:
            return
        
        del self.map[self.tail.pv.key]
        self._remove(self.tail.pv)
        
    def _remove(self, node):
        node.pv.nx = node.nx
        node.nx.pv = node.pv
    
    def _add(self, node):
        node.nx = self.head.nx
        self.head.nx = node
        node.pv = self.head
        node.nx.pv = node

