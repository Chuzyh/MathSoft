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
  int T;srand(233);
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    int status;
    int iter = 0, max_iter = mx;
    const gsl_root_fsolver_type *T;
    gsl_root_fsolver *s;
    double r = 0;
    double x_lo , x_hi;
    
    gsl_function F;
    double P[8];
    for(int i=0;i<8;i++)scanf("%lf",&P[i]);
    struct myf_params params = {P[0],P[1],P[2],P[3],P[4],P[5],P[6],P[7]};
    F.function = &myf;
    F.params = &params;
    for(int i=1;i<=2;i++)
    {
      
      x_lo=20.0*rand()/RAND_MAX;
      x_hi=20.0*rand()/RAND_MAX;
      if(rand()%2)x_lo=-x_lo;
      if(rand()%2)x_hi=-x_hi;
      if(x_lo>x_hi)
      {
        double tmp=x_lo;
        x_lo=x_hi;
        x_hi=tmp;
      }
      if(myf(x_lo,&params)*myf(x_hi,&params)<-eps)break;
    }
    if(myf(x_lo,&params)*myf(x_hi,&params)>0)
    {
      continue;
    }
    T = gsl_root_fsolver_bisection;
    s = gsl_root_fsolver_alloc (T);
    gsl_root_fsolver_set (s, &F, x_lo, x_hi);

    if(argc>=2)
    {printf ("using %s method\n",
          gsl_root_fsolver_name (s));

    printf ("%5s [%9s, %9s] %9s %10s %9s\n",
          "iter", "lower", "upper", "root",
          "err", "err(est)");}

    do
    {
      iter++;
      status = gsl_root_fsolver_iterate (s);
      r = gsl_root_fsolver_root (s);
      x_lo = gsl_root_fsolver_x_lower (s);
      x_hi = gsl_root_fsolver_x_upper (s);
      status = gsl_root_test_interval (x_lo, x_hi,
                                       0, 0.001);
      progress[i][iter]=(x_lo+x_hi)/2;
      iter_time[i]=iter;
      if(argc>=2)
      {
      if (status == GSL_SUCCESS)
        printf ("Converged:\n");

      printf ("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
              iter, x_lo, x_hi,
              r, myf(r,&params),
              x_hi - x_lo);
      }
    }
    while (status == GSL_CONTINUE && iter < max_iter);
    if(status==GSL_SUCCESS)
    {
      success++;
      //for(int j=1;j<iter_time[i];j++)sum[j]+=abs(progress[i][iter_time[i]]-progress[i][j]);

      for(int j=1;j<iter_time[i];j++)sum[j]+=1;
      avg_time+=iter_time[i];
    }
    gsl_root_fsolver_free (s);

  }
  if(argc==1)
  {printf("%d %lf\n",success,avg_time/success);
  for(int i=1;i<=mx;i++)printf("%d %lf\n",i,sum[i]/success);}
  return 0;
}
