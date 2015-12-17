#!/bin/bash

pdflatex demo.tex
bibtex demo.aux
makeindex demo.idx
makeindex demo.nlo -s nomencl.ist -o demo.nls
pdflatex demo.tex
pdflatex demo.tex