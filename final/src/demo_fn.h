struct myf_params
  {
    double a, b, c, d, e, f;
    double si,co;
  };

double myf (double x, void *params);
double myf_deriv (double x, void *params);
void myf_fdf (double x, void *params, 
                    double *y, double *dy);
