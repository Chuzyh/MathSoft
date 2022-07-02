make:./src/roots.c
	if [ ! -d "./bin/" ];then mkdir ./bin; fi
	g++ -o ./bin/root ./src/roots.c -lgsl -lgslcblas	
report:./doc/report.tex
	xelatex ./doc/report
	mv report.pdf ./doc
	rm report.*
