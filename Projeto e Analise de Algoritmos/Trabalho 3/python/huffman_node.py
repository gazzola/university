from node import Node

class Huffman:

	__queue, __table = {}, {}
	__nodes = []
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
		for char in sorted(self.__queue, key=self.__queue.get):
			print("%c:%d" %(char, self.__queue[char]))


	def queueNodes(self):
		for char in sorted(self.__queue, key=self.__queue.get):
			self.__nodes.append(Node(char, self.__queue[char]))


	def printAllNodes(self):
		i=0
		while(i<len(self.__nodes)):
			print("")
			level = self.__nodes[i].height(self.__nodes[i])+1
			self.__nodes[i].printNode(self.__nodes[i], level)
			i+=1


	def printSequenceNodes(self):
		i = 0
		while(i < len(self.__nodes)):
			print("")
			self.__nodes[i].printNodeLine(self.__nodes[i])
			i+=1


	def extractMin(self):
		pos = 0
		m, i = self.__nodes[pos], 1
		while(i < len(self.__nodes)):
			if(self.__nodes[i].freq < m.freq):
				m = self.__nodes[i]
				pos = i
			i += 1

		del self.__nodes[pos]
		return m


	def joinElements(self):
		while(len(self.__nodes) > 1):
			left = self.extractMin()
			right = self.extractMin()
			root = Node(left.char+right.char, left.freq+right.freq, left, right)
			self.__nodes.append(root)


	def compress(self):
		self.__nodes[0].passTree(self.__nodes[0])
		self.__table = self.__nodes[0].getTable()


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
		bytetable = [("0000000"+bin(x)[2:])[-7:] for x in range(128)]
		text = "".join(bytetable[ord(x)] for x in b)
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