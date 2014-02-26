class HeapMin:

	__heap = []
	__capacity = 0
	__inf = float("inf")

	def __init__(self, node, capacity, inf):
		self.__heap.append(node)
		self.__capacity = capacity
		self.__inf = inf


	def __issetNode(self, node):
		return (node < len(self.__heap))


	def __getFather(self, node):
		return self.__heap[int(node/2)]


	def __getLeftSon(self, node):
		if(self.__issetNode(node*2)):
			return self.__heap[node*2]
		return self.__inf


	def __getRightSon(self, node):
		if(self.__issetNode(node*2+1)):
			return self.__heap[node*2 + 1]
		return self.__inf


	def __rollUp(self, node):
		while self.__getFather(node).freq > self.__heap[node].freq:
			temp = self.__getFather(node)
			self.__heap[int(node/2)] = self.__heap[node]
			self.__heap[node] = temp;
			node = int(node/2)


	def __rollDown(self, node):
		while self.__heap[node].freq > self.__getLeftSon(node).freq or self.__heap[node].freq > self.__getRightSon(node).freq:
			
			if(self.__getRightSon(node).freq < self.__getLeftSon(node).freq):
				pos = node*2 + 1
			else:
				pos = node*2

			if(self.__issetNode(pos) == False):
				break

			temp = self.__heap[pos]
			self.__heap[pos] = self.__heap[node]
			self.__heap[node] = temp
			node = pos


	def __swap(self, node1, node2):
		temp = self.__heap[node1]
		self.__heap[node1] = self.__heap[node2]
		self.__heap[node2] = temp


	def heapify(self, node):
		bigger = node

		if(self.__getLeftSon(node).freq < self.__heap[node].freq and self.__getLeftSon(node) != False):
			bigger = node*2

		if(self.__getRightSon(node).freq < self.__heap[bigger].freq and self.__getRightSon(node) != False):
			bigger = node*2 + 1

		if(bigger != node):
			self.__swap(node, bigger)
			self.heapify(bigger)


	def buildHeap(self):
		i = int(len(self.__heap)/2);
		while(i>0):
			self.heapify(i)
			i-=1


	def insertNodeWithoutRoll(self, node):
		if(len(self.__heap)+1 > self.__capacity):
			raise CapacityError("Reached Capacity", "Maximum numbers of nodes in heap was reached!")

		self.__heap.append(node)


	def extractMin(self):
		if(len(self.__heap) > 2):
			temp = self.__heap[1]
			self.__heap[1] = self.__heap.pop()
			self.__rollDown(1)
		else:
			temp = self.__heap.pop()

		return temp


	def insertNode(self, node):
		pos = len(self.__heap)
		if(pos+1 > self.__capacity):
			raise CapacityError("Reached Capacity", "Maximum numbers of nodes in heap was reached!")

		self.__heap.append(node)
		self.__rollUp(pos)


	def printHeap(self):
		i, nl = 1, 2

		while(i < len(self.__heap)):
			print(self.__heap[i], end=" ")
			i += 1

			if(i == nl):
				nl *= 2
				print("\n", end="")


	def getSize(self):
		return len(self.__heap)


	def getNode(self, pos):
		return self.__heap[pos]



class CapacityError(Exception):
    def __init__(self, expr, msg):
        self.expr = expr
        self.msg = msg