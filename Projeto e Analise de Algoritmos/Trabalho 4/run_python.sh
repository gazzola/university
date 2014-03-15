#!/bin/bash

echo "Passe python3/pypy para o nome do interpretador"
read inter

echo "Passe o nome do arquivo contido na pasta colecoes/ que deseja ler ou digite all para executar todos arquivos"
read value

echo ""

if [ $inter = "pypy" ] || [ $inter = "python3" ] || [ $inter = "python" ]; then
	if [[ $value = "all" || $value = "ALL" ]]; then
		cd colecoes/

		for filename in *; do
			echo "Executando para o arquivo: $filename"
			cd ../python/
			$inter main.py $filename
			cd ../colecoes/
			echo ""
			sleep 1
		done

	else
		cd python/
		$inter main.py $value
	fi

else
	echo "Interpretador nao aceito"
fi