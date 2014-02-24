from huffman_heap import Huffman

h = Huffman("entrada")

h.queueHeap()
h.joinElements()

h.compress()

h.saveFile('saida')
h.saveFileBin('bsaida')

h.printTexts()
print("\n")

final = h.extract('bsaida')
print("EXTRACT:\n"+final)