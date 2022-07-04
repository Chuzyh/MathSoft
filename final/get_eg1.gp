set terminal latex
set output "eg1.tex"
plot [-1.5:1.5] x**2 title "delta=0",x**2+x+1 title "delta<0",-x**2+1 title "delta>0",0 title "0"

