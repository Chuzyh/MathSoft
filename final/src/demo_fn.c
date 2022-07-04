double
myf (double x, void *params)
{
  struct myf_params *p 
    = (struct myf_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;
  double d = p->d;
  double e = p->e;
  double f = p->f;
  double si = p->si;
  double co = p->co;
  

  return (((((a * x + b) * x + c) *x +d)*x+e)*x+f)+si*sin(x)+co*cos(x);
}

double
myf_deriv (double x, void *params)
{
  struct myf_params *p 
    = (struct myf_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;
  double d = p->d;
  double e = p->e;
  double f = p->f;
  double si = p->si;
  double co = p->co;

  return (((5.0*a*x+4.0*b)*x+3.0*c)*x+2.0*d)*x+e+si*cos(x)-co*sin(x);
}

void
myf_fdf (double x, void *params, 
               double *y, double *dy)
{
  struct myf_params *p 
    = (struct myf_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;
  double d = p->d;
  double e = p->e;
  double f = p->f;
  double si = p->si;
  double co = p->co;

  *y = (((((a * x + b) * x + c) *x +d)*x+e)*x+f)+si*sin(x)+co*cos(x);
  *dy = (((5.0*a*x+4.0*b)*x+3.0*c)*x+2.0*d)*x+e+si*cos(x)-co*sin(x);
}
