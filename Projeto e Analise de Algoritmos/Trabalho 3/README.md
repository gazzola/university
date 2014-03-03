Marcos Vinícius Treviso (121150107)

Exercício Prático 2 - Projeto e Análise de Algoritmos
=========================================================

Implemente o algoritmo de Huffman (usando um Heap) para compactar textos.


Implementação
===============

Implementado usando Heap de Mínimo na linguagem de programação Python versão 3.

Foi criado uma classe heapInteger para testes de funcionalidades do heap, apeans utilizando inteiros como conteúdo.

Foi criado dois tipos de algoritmos para testar o desempenho do algoritmo, um foi utilizando fila+árvore (huffman_node) e outro heap+árvore (huffman_heap).

A classe Node eh utilizada para criar os nós da árvore e também os nós para serem colocados no heap.


Execução
==========

Arquivo main.py ($ python3 main.py)
Ou execute o arquivo: ./run_huffman.sh

Necessário um arquivo de entrada na pasta python/ para a entrada de texto do programa.


Extra
======

Foram realizados testes utilizando a linguagem C, entretanto a implementação completa foi feita em Python.