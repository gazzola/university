#!/bin/bash

flex -o calc.lex.cpp calc.lex
bison -y -d calc.yacc
g++ y.tab.c -o trab
./trab < input.txt
rm y.tab.*
rm calc.lex.cpp
rm trab