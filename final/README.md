# 文件说明

#### src(源文件)

- `data_maker.cpp`：生成随机方程
- `roots_bisection.c`：使用二分法求根
- `roots_newton.c`：使用牛顿法求根
- `demo_fn.c,demo_fn.h`：自定义函数$f(x)=ax^5+bx^4+cx^3+dx^2+ex+f+si\sin(x)+co\cos(x)$

#### doc(文档)

- `report.tex`：论文源文件
- `slide.tex`：演示文稿源文件
- `quote.bib`：引用文献目录
- `get_eg1.gp,get_eg2.gp`：生成论文所需的的`gnuplot`指令

#### data(数据)

- `data1`：牛顿法求解结果统计数据
- `data2`：二分法求解结果统计数据
- `equation.in`：随机生成的方程
- `example`：论文中的样例方程

#### bin(可执行文件)

- `dmk`：生成随机方程
- `roots_bisection`：使用二分法求根
- `roots_newton`：使用牛顿法求根

# 编译说明

```bash
make
```

可获得`roots_bisection`和`roots_newton`

```bash
make dmk
```

可获得`dmk`

```bash
make report
```

可获得`report.pdf`

```bash
make slide
```

可获得`slide.pdf`

# 测试说明

```bash
make test
```

可获得`data1`和`data2`

```bash
make example
```

可获得对于论文中的样例方程的测试结果

```bash
make overview
```

可获得对于论文中提到的对于100000个随机方程的统计结果



