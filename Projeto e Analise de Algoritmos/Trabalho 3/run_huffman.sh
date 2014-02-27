#!/bin/bash

cd python/
file="entrada"

if [ ! -f "$file" ]; then
	printf "um bom corredor nao precisa nunca ter medo do escuro" > $file
fi

python3 main.py