#!/bin/bash

pdflatex -shell-escape monografia.tex
bibtex monografia.aux
makeindex monografia.idx
makeindex monografia.nlo -s nomencl.ist -o monografia.nls
pdflatex -shell-escape monografia.tex
pdflatex -shell-escape monografia.tex