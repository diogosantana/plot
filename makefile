clean :
	rm -rf dist
	
clean-plot: 
	rm -rf plot

clean-all: clean clean-plot

build : clean
	mkdir -p dist
	clang -o dist/main main.c

run : build
	dist/main

gen-plot :
	mkdir -p plot
	gnuplot-base plot.gp

all : clean build run gen-plot
