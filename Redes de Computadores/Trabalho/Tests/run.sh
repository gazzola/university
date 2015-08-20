#!/bin/bash

if [ $# -ne 3 ]
then
	echo "Deve ser informado o nome do tipo, pasta dos tipos de saida e o num de execucao."
	exit 1
fi


tipo=$1
pasta=$2

printf "\nExec #"$3"\n------------\n" >> $pasta/AES.out
printf "ENTRADA 1:\n=================\n\n" >> $pasta/AES.out
./bin/teste_aes_$tipo < entradas/entrada1.txt >> $pasta/AES.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/AES.out
./bin/teste_aes_$tipo < entradas/entrada2.txt >> $pasta/AES.out

printf "\nExec #"$3 >> $pasta/Blowfish.out
printf "ENTRADA 1:\n=================\n\n" >> $pasta/Blowfish.out
./bin/teste_blo_$tipo < entradas/entrada1.txt >> $pasta/Blowfish.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/Blowfish.out
./bin/teste_blo_$tipo < entradas/entrada2.txt >> $pasta/Blowfish.out

printf "\nExec #"$3 >> $pasta/RC5.out
printf "ENTRADA 1:\n=================\n\n" >> $pasta/RC5.out
./bin/teste_rc5_$tipo < entradas/entrada1.txt >> $pasta/RC5.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/RC5.out
./bin/teste_rc5_$tipo < entradas/entrada2.txt >> $pasta/RC5.out

printf "\nExec #"$3 >> $pasta/Skipjack.out
printf "ENTRADA 1:\n=================\n\n" >> $pasta/Skipjack.out
./bin/teste_ski_$tipo < entradas/entrada1.txt >> $pasta/Skipjack.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/Skipjack.out
./bin/teste_ski_$tipo < entradas/entrada2.txt >> $pasta/Skipjack.out

printf "\nExec #"$3 >> $pasta/TEA.out
printf "ENTRADA 1:\n=================\n\n" >> $pasta/TEA.out
./bin/teste_tea_$tipo < entradas/entrada1.txt >> $pasta/TEA.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/TEA.out
./bin/teste_tea_$tipo < entradas/entrada2.txt >> $pasta/TEA.out	
