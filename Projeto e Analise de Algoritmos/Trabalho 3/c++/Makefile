
#  Projeto e Análise de Algoritmos - Codificação de Huffman
#  Matheus S. Serpa - 121151631
#  matheusserpa@gmail.com


# Flags
FLAGS := -O2 -Wall -Wextra

# Target rules
all: huffman

node.o: node.cpp
	g++ $(FLAGS) -o $@ -c $<

heap.o: heap.cpp
	g++ $(FLAGS) -o $@ -c $<

huffman.o: huffman.cpp
	g++ $(FLAGS) -o $@ -c $<

main.o: main.cpp
	g++ $(FLAGS) -o $@ -c $<

huffman: node.o heap.o huffman.o main.o
	g++ $(FLAGS) -o $@ $+

run: huffman
	./huffman input.in

clean:
	rm -f huffman *.o