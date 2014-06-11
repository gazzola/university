#!/bin/bash

echo "Digite a quantidade de processos: "
read processos

echo ""

echo "Digite 0 para passar a execucao atraves da tecla ENTER ou um numero em segundos:"
read tempo

g++ -o teste ProcessRep.cpp -Wall -Wextra
./teste $processos $tempo
