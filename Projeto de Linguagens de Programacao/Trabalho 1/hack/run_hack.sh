#!/bin/bash

echo "" > ../results_hack

#max executions of a algorithm
max=5

#ratio of increase input algorithm value
ratioMatrix=50
ratioFactorial=4

for filename in *.php; do

	arg=0

	for((i=1; i<=$max; ++i )); 
	do
		
		if [ $filename = "lacos.php" ]; then
			((arg = $arg + $ratioMatrix));
		else
			((arg = $arg + $ratioFactorial));
		fi

		echo "executando $filename com arg: $arg"

		#save the results in a file
		echo "executando $filename com arg: $arg" >> ../results_hack
		time hhvm $filename $arg >> ../results_hack
		echo "" >> ../results_hack

		printf "\n\n"
	
	done
done