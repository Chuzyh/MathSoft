make:./src/roots_newton.c ./src/roots_bisection.c
	if [ ! -d "./bin/" ];then mkdir ./bin; fi
	g++ -o ./bin/roots_newton ./src/roots_newton.c -lgsl -lgslcblas
	g++ -o ./bin/roots_bisection ./src/roots_bisection.c -lgsl -lgslcblas
	
dmk: ./src/data_maker.cpp
	g++ -o ./bin/dmk ./src/data_maker.cpp	

report:make dmk test ./doc/report.tex  ./doc/quote.bib 
	cp ./doc/report.tex ./doc/quote.bib ./doc/get_eg1.gp ./
	cp ./data/data1 ./data/data2 ./
	gnuplot get_eg1.gp
	xelatex report
	bibtex report
	xelatex report
	xelatex report
	mv report.pdf ./doc
	rm data1 data2
	rm report.* quote.bib get_eg1.gp eg1.tex
	

test: make dmk ./bin/roots_newton ./bin/roots_bisection ./bin/dmk 
	if [ ! -d "./data/" ];then mkdir ./data; fi
	cd bin && ./dmk>../data/equation.in
	cd bin && ./roots_newton<../data/equation.in>data1
	cd bin && ./roots_bisection<../data/equation.in>data2
	
	mv ./bin/data1 ./data
	mv ./bin/data2 ./data
	
example: test
	cd bin && ./dmk>../data/equation.in
	cd bin && ./roots_newton -t<../data/example
	cd bin && ./roots_bisection -t<../data/example

overview: make dmk ./bin/roots_newton ./bin/roots_bisection ./bin/dmk 
	if [ ! -d "./data/" ];then mkdir ./data; fi
	cd bin && ./dmk>../data/equation.in
	cd bin && ./roots_newton -t -o<../data/equation.in
	cd bin && ./roots_bisection -t -o<../data/equation.in