#!/bin/bash

echo "" > ../results_ruby

#max executions of a algorithm
max=5

#ratio of increase input algorithm value
ratioMatrix=50
ratioFactorial=4

for filename in *.rb; do

	arg=0

	for((i=1; i<=$max; ++i )); 
	do
		
		if [ $filename = "lacos.rb" ]; then
			((arg = $arg + $ratioMatrix));
		else
			((arg = $arg + $ratioFactorial));
		fi

		echo "executando $filename com arg: $arg"

		#save the results in a file
		echo "executando $filename com arg: $arg" >> ../results_ruby
		time ruby $filename $arg >> ../results_ruby
		echo "" >> ../results_ruby

		printf "\n\n"
	
	done
done