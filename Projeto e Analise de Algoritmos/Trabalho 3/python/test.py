import sys
from heapok import HeapMin, CapacityError


#set the capacity of heap
heap = HeapMin(50)

try:
	heap.insertNode(3)
	heap.insertNode(7)
	heap.insertNode(5)
	heap.insertNode(8)
	heap.insertNode(13)
	heap.insertNode(6)
	heap.insertNode(12)
	heap.insertNode(15)
	heap.insertNode(8)
	heap.insertNode(4)
except CapacityError as e:
	print(e.expr.upper() + ":\n" + e.msg + "\n")
	sys.exit(0)


heap.printHeap()
print("\n\n")

mini = heap.extractMin()
heap.printHeap()
print("\n\nMIN:%d\n" %mini)