package main

// Node represents an element in the doubly linked list.
type Node struct {
	key   int
	value int
	prev  *Node
	next  *Node
}

type LRUCache struct {
	capacity int
	cache    map[int]*Node
	head     *Node // Dummy head (MRU side)
	tail     *Node // Dummy tail (LRU side)
}

func Constructor(capacity int) LRUCache {
	head := &Node{}
	tail := &Node{}
	head.next = tail
	tail.prev = head

	return LRUCache{
		capacity: capacity,
		cache:    make(map[int]*Node),
		head:     head,
		tail:     tail,
	}
}

// removeNode unlinks an existing node from the list in O(1).
func (this *LRUCache) removeNode(node *Node) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

// addToHead inserts a node right after the dummy head (MRU position) in O(1).
func (this *LRUCache) addToHead(node *Node) {
	node.next = this.head.next
	node.prev = this.head
	this.head.next.prev = node
	this.head.next = node
}

// moveToHead moves an existing node to the MRU position.
func (this *LRUCache) moveToHead(node *Node) {
	this.removeNode(node)
	this.addToHead(node)
}

// removeTail removes the least recently used node right before dummy tail.
func (this *LRUCache) removeTail() *Node {
	lru := this.tail.prev
	this.removeNode(lru)
	return lru
}

func (this *LRUCache) Get(key int) int {
	node, exists := this.cache[key]
	if !exists {
		return -1
	}
	// Mark as recently accessed
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {
	node, exists := this.cache[key]

	if exists {
		// Update value and move to MRU
		node.value = value
		this.moveToHead(node)
	} else {
		newNode := &Node{key: key, value: value}
		this.cache[key] = newNode
		this.addToHead(newNode)

		// Evict least recently used if capacity is exceeded
		if len(this.cache) > this.capacity {
			lru := this.removeTail()
			delete(this.cache, lru.key)
		}
	}
}