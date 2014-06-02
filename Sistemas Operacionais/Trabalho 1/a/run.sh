#!/bin/bash

echo "Digite o tempo de espera a cada execução de thread: "
read tempo

max=9
min=4


g++ -o teste prodcons.cpp -Wall -Wextra -lpthread

for((i=$min; i<=$max; ++i )); 
do

	printf "\n--------------------------------------\n\n"
	for((j=$min; j<=$max; ++j )); 
	do
		printf "\nExecutando para qtd.prod=$i e qtd.cons=$j:\n"
		./teste $tempo $i $j
	done	

done