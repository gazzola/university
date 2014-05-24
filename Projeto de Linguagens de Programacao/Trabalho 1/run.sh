#!/bin/bash

echo "Passe o nome da linguagem que deseja executar [hack/haskell/python/ruby/all] ou deixe em branco para executar todas"
read value

if [[ $value = "hack" || $value = "HACK" ]]; then

	printf "Executando Hack!\n"
	printf "=================\n\n"
	cd hack/
	bash run_hack.sh

elif [[ $value = "haskell" || $value = "HASKELL" ]]; then

	printf "Executando Haskell!\n"
	printf "=================\n\n"
	cd haskell/
	bash run_haskell.sh

elif [[ $value = "python" || $value = "PYTHON" ]]; then

	printf "Executando Python!\n"
	printf "=================\n\n"
	cd python/
	bash run_python.sh

elif [[ $value = "ruby" || $value = "RUBY" ]]; then

	printf "Executando Ruby!\n"
	printf "=================\n\n"
	cd ruby/
	bash run_ruby.sh

else

	printf "Executando Todos!\n"
	printf "=================\n\n"

	printf "Executando Hack!\n"
	cd hack/
	bash run_hack.sh

	printf "Executando Haskell!\n"
	cd ../haskell/
	bash run_haskell.sh

	printf "Executando Python!\n"
	cd ../python/
	bash run_python.sh

	printf "Executando Ruby!\n"
	cd ../ruby/
	bash run_ruby.sh

fi

