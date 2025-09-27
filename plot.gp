set terminal png
set output 'plot/plot.png'
plot 'dist/test.txt' with lines smooth csplines
set output