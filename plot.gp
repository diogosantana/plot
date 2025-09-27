set terminal png
set output 'dist/plot.png'
plot 'dist/test.txt' with lines smooth csplines
set output