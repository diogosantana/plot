set terminal png
set output 'plot.png'
plot 'test.txt' with lines smooth csplines
set output