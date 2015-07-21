cls

flex -o trab.lex.cpp trab.lex
bison -y -d -v trab.yacc
g++ y.tab.c -o trab
trab.exe < %1

pause