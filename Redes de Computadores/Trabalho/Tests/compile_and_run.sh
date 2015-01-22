#!/bin/bash

if [ $# -ne 2 ]
then
	echo "Deve ser informado o nome do arquivo e a pasta dos arquivos de saida"
	exit 1
fi

arquivo=$1
pasta=$2

g++ -o teste_aes_op $arquivo -lcrypto++ -Wall -Wextra -DA_AES
printf "ENTRADA 1:\n=================\n\n" > $pasta/AES.out
./bin/teste < entradas/entrada1.txt >> $pasta/AES.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/AES.out
./bin/teste < entradas/entrada2.txt >> $pasta/AES.out

g++ -o teste_blo_op $arquivo -lcrypto++ -Wall -Wextra -DA_BLO
printf "ENTRADA 1:\n=================\n\n" > $pasta/Blowfish.out
./bin/teste < entradas/entrada1.txt >> $pasta/Blowfish.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/Blowfish.out
./bin/teste < entradas/entrada2.txt >> $pasta/Blowfish.out

g++ -o teste_rc5_op $arquivo -lcrypto++ -Wall -Wextra -DA_RC5
printf "ENTRADA 1:\n=================\n\n" > $pasta/RC5.out
./bin/teste < entradas/entrada1.txt >> $pasta/RC5.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/RC5.out
./bin/teste < entradas/entrada2.txt >> $pasta/RC5.out

g++ -o teste_ski_op $arquivo -lcrypto++ -Wall -Wextra -DA_SKI
printf "ENTRADA 1:\n=================\n\n" > $pasta/Skipjack.out
./bin/teste < entradas/entrada1.txt >> $pasta/Skipjack.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/Skipjack.out
./bin/teste < entradas/entrada2.txt >> $pasta/Skipjack.out

g++ -o teste_tea_op $arquivo -lcrypto++ -Wall -Wextra -DA_TEA
printf "ENTRADA 1:\n=================\n\n" > $pasta/TEA.out
./bin/teste < entradas/entrada1.txt >> $pasta/TEA.out
printf "\nENTRADA 2:\n=================\n\n" >> $pasta/TEA.out
./bin/teste < entradas/entrada2.txt >> $pasta/TEA.out	
