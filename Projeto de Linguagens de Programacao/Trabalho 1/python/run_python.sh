#!/bin/bash

echo "" > ../results_python

#max executions of a algorithm
max=5

#ratio of increase input algorithm value
ratioMatrix=50
ratioFactorial=4

for filename in *.py; do

	arg=0

	for((i=1; i<=$max; ++i )); 
	do
		
		if [ $filename = "lacos.py" ]; then
			((arg = $arg + $ratioMatrix));
		else
			((arg = $arg + $ratioFactorial));
		fi

		echo "executando $filename com arg: $arg"

		#save the results in a file
		echo "executando $filename com arg: $arg" >> ../results_python
		time python3 $filename $arg >> ../results_python
		echo "" >> ../results_python

		printf "\n\n"
	
	done
done