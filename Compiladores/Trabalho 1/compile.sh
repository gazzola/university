#!/bin/bash

flex -o trab.lex.cpp trab.lex
bison -y -d -v trab.yacc
g++ y.tab.c -o trab
./trab < input.txt
rm y.tab.*
rm trab.lex.cpp
rm trab