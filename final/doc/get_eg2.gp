set size 0.7,0.7
set terminal latex
set output "eg2.tex"
set xlabel "迭代次数"
set ylabel "未求出解的方程的比例"
plot "data1" title "Newton" with linespoints,"data2" title "Bisection" with linespoints lt 1 pt 7
