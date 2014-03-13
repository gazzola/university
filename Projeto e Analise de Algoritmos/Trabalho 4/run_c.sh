#!/bin/bash

echo "Passe o nome do arquivo contido na pasta colecoes/ que deseja ler ou digite `all` para executar todos arquivos"
read value

if [[ $value = "all" || $value = "ALL" ]]; then

	cd colecoes/

	for filename in *; do
		echo "Compilando e executando para o arquivo: $filename"
		cd ../c/
		gcc -o teste main.c -Wall
		./teste < ../colecoes/$filename
		cd ../colecoes/
		echo ""
		sleep 1
	done
	
else

	cd c
	gcc -o teste main.c -Wall
	./teste < ../colecoes/$value

fi

