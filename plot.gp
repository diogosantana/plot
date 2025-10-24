set terminal png
set output 'plot/plot.png'
#set logscale y
plot 'dist/fibo-recursive-microseconds.txt' with lines smooth csplines
set output