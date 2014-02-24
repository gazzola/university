import math

class Node():

	__table = {}
	__space = '$'

	def __init__(self, char, freq, left=None, right=None):
		self.char = char
		self.freq = freq
		self.left = left
		self.right = right
	

	def __str__(self):
		return str(self.char)+":"+str(self.freq)


	def height(self, node):
	    if node is None:
	        return 0
	    else:
	        return max(self.height(node.left), self.height(node.right)) + 1


	def powerTwo(self, num):
		if num < 1:
			return 0
		return int(math.log(num, 2))


	def printNode(self, tree, level=0):
		if(tree == None):
			return
	
		self.printNode(tree.left, level-1)

		print('-'*2*level, end="")
		if(tree.char == ' '):
			print(self.__space+":"+str(tree.freq), end="")
		else:
			print(tree, end="")
	
		if(self.powerTwo(level)):
			print("\n", end="")

		self.printNode(tree.right, level-1)


	def printNodeLine(self, tree):
		if(tree == None):
			return

		if(tree.char == ' '):
			print(self.__space, end=" - ")
		else:
			print(tree.char, end=" - ")

		if(len(tree.char) == 1):
			print("")

		self.printNodeLine(tree.left)
		self.printNodeLine(tree.right)


	def passTree(self, tree, direction='', text=''):
		if(tree == None):
			return

		text += direction
		if(len(tree.char) == 1):
			self.__table[tree.char] = text

		self.passTree(tree.left, '0', text)
		self.passTree(tree.right, '1', text)


	def getTable(self):
		return self.__table


#left = Node('a', 1)
#right = Node('b', 2)
#root = Node('c', 3, left, right)

#print("\n")
#root.printNode(root, root.height(root))
#print("\n")