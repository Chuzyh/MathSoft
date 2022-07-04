set terminal latex
set output "eg1.tex"
plot "data1" title "Newton" with linespoints,"data2" title "Bisection" with linespoints lt 1 pt 7
