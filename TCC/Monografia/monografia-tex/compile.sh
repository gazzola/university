#!/bin/bash

pdflatex monografia.tex
bibtex monografia.aux
makeindex monografia.idx
makeindex monografia.nlo -s nomencl.ist -o monografia.nls
pdflatex monografia.tex
pdflatex monografia.tex