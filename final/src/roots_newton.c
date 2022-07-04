#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

#include "demo_fn.h"
#include "demo_fn.c"

const int N=100001,mx=30;
const double eps=1e-3;
double progress[N][mx+1];
int iter_time[N],success;
double sum[mx+10],avg_time;
int
main (int argc,char* argv[])
{
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    int status;
    int iter = 0, max_iter = mx;
    const gsl_root_fdfsolver_type *T;
    gsl_root_fdfsolver *s;
    double x0, x = 0;//r_expected = sqrt (0);
    gsl_function_fdf FDF;
    double P[8];
    for(int i=0;i<8;i++)scanf("%lf",&P[i]);
    struct myf_params params = {P[0],P[1],P[2],P[3],P[4],P[5],P[6],P[7]};

    FDF.f = &myf;
    FDF.df = &myf_deriv;
    FDF.fdf = &myf_fdf;
    FDF.params = &params;

    T = gsl_root_fdfsolver_newton;
    s = gsl_root_fdfsolver_alloc (T);
    gsl_root_fdfsolver_set (s, &FDF, x);

    if(argc==2)
    {printf ("using %s method\n",
            gsl_root_fdfsolver_name (s));

    printf ("%-5s %10s %10s %10s\n",
            "iter", "root", "err","del");}
    do
      {
        iter++;
        status = gsl_root_fdfsolver_iterate (s);
        x0 = x;
        x = gsl_root_fdfsolver_root (s);
        status = gsl_root_test_delta (x, x0, 0, eps);

        if(argc==2)
        {   if (status == GSL_SUCCESS)
          printf ("Converged:\n");

        printf ("%5d %10.7f %+10.7f %10.7f\n",
                iter, x, fabs(myf(x,&params)), x - x0);}
        progress[i][iter]=x;
        iter_time[i]=iter;
      }
    while (status == GSL_CONTINUE && iter < max_iter);
    if(status==GSL_SUCCESS)
    {
      success++;
      for(int j=1;j<iter_time[i];j++)sum[j]+=1;
      avg_time+=iter_time[i];
    }
    gsl_root_fdfsolver_free (s);
  }
  if(argc==1)
  for(int i=1;i<=mx;i++)printf("%d %lf\n",i,(sum[i]+T-success)/T);
  if(argc==3)printf("%d %lf\n",success,avg_time/success);
  return 0;
}
