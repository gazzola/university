#!/bin/bash

echo "" > ../results_haskell

#max executions of a algorithm
max=5

#ratio of increase input algorithm value
ratioMatrix=50
ratioFactorial=4

#compiled file name
compfile="teste"

for filename in *.hs; do

	arg=0

	for((i=1; i<=$max; ++i )); 
	do
		
		if [ $filename = "lacos.hs" ]; then
			((arg = $arg + $ratioMatrix));
		else
			((arg = $arg + $ratioFactorial));
		fi

		echo "executando $filename com arg: $arg"

		#save the results in a file
		echo "executando $filename com arg: $arg" >> ../results_haskell
		ghc -o $compfile $filename
		time ./$compfile $arg >> ../results_haskell
		echo "" >> ../results_haskell

		printf "\n\n"
	
	done
done

#remove the generated files of compilation
if [ -f "$compfile" ]; then
	rm $compfile
	rm *.hi
	rm *.o
fi