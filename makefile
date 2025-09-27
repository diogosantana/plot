clean :
	rm -rf dist

build :
	mkdir dist
	clang -o dist/main main.c

run :
	dist/main

plot :
	gnuplot-base plot.gp

all : clean build run plot
	