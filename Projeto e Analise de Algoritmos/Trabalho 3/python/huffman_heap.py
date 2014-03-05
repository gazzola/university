from heap import HeapMin, CapacityError
from node import Node
import sys

class Huffman:

	__queue, __table = {}, {}
	__heap_queue = []
	__text, __bintext = '', ''


	def __init__(self, filename):
		with open(filename, 'r') as f: 
			for line in f:
				for char in line:
					if char in self.__queue:
						self.__queue[char] += 1
					else:
						self.__queue[char] = 1

				self.__text += line
           		


	def printQueue(self):
		for char in self.__queue:
			print("%c:%d" %(char, self.__queue[char]))


	def queueHeap(self):
		size = len(self.__queue)+1
		first = Node('', -1)
		inf = Node('', float("inf"))

		self.__heap_queue = HeapMin(first, size, inf)

		for char in self.__queue:
			try:
				self.__heap_queue.insertNode(Node(char, self.__queue[char]))
			except CapacityError as e:
				print(e.expr.upper() + ":\n" + e.msg + "\n")
				sys.exit(0)


	def printHeapQueue(self):
		self.__heap_queue.printHeap()


	def printAllNodes(self):
		root = self.__heap_queue.getNode(1)
		level = root.height(root)+1
		root.printNode(root, level)


	def printSequenceNodes(self):
		root = self.__heap_queue.getNode(1)
		root.printNodeLine(root)


	def joinElements(self):
		while(self.__heap_queue.getSize() > 2):			
			left = self.__heap_queue.extractMin()
			right = self.__heap_queue.extractMin()
			root = Node(left.char+right.char, left.freq+right.freq, left, right)
			self.__heap_queue.insertNode(root)


	def compress(self):
		root = self.__heap_queue.getNode(1)
		root.passTree(root)
		self.__table = root.getTable()


	def extract(self, filename=''):
		b, txt = '', ''
		inv_table = dict((value, key) for key, value in self.__table.items())
		
		text = self.__bintext
		if(filename != ''):
			f = open(filename, 'rb')
			text = self.__convertStringToBin(f.read().decode('ascii'))
			f.close()

		for char in text:
			b += char
			if b in inv_table:
				txt += inv_table[b]
				b = ''
		return txt


	def saveFile(self, filename):
		f = open(filename, 'w+')
		b = ''
		for char in self.__text:
			b += self.__table[char]
			
		f.write(b)
		f.close()
		self.__bintext = b


	def saveFileBin(self, filename):
		f = open(filename, 'wb')
		b = ''
		for char in self.__text:
			b += self.__table[char]
		
		f.write(self.__convertBinToString(b).encode('ascii'))
		f.close()
		self.__bintext = b


	def __convertBinToString(self, b):
		start, end = 0, 7
		text = ''
		while(end < len(b)+7):
			temp = b[start:end]
			text += chr(int(temp, 2))
			start, end = end, end+7

		return text


	def __convertStringToBin(self, b):
		i = 0
		text = ''
		while(i < len(b)):
			temp = b[i]
			text += str(bin(ord(temp)))[2:].zfill(7)
			i += 1

		return text


	def printTexts(self):
		print(self.__text)
		print(self.__bintext)


	def printTable(self):
		print(self.__table)


	def printSizes(self):
		sizeOriginalText = len(self.__text)*8
		sizeCompressText = len(self.__bintext)
		compressRatio = 100-float((sizeCompressText*100)/sizeOriginalText)
		print("Tamanho do texto original em bits: %d" %(sizeOriginalText))
		print("Tamanho do texto compactado em bits: %d" %(sizeCompressText))
		print("Taxa de compactacao: %.2f%%" %compressRatio)