make: ./src/main.cpp ./src/bitmap.cpp
	g++ -o test ./src/main.cpp ./src/bitmap.cpp -I ./include
report:hw4.tex quote.bib
	xelatex hw4
	bibtex hw4
	xelatex hw4
	xelatex hw4
	rm *.aux *.log *.bbl *.blg *.out
