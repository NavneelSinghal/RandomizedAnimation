set size ratio 1
unset border
unset xtics
unset ytics
unset label
set style line 4 ps 0.05
set terminal png
set output 'out.png'
plot 'out' ls 4 notitle
exit
