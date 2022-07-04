#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(233);
    int T=100000;
    printf("%d\n",T);
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=8;j++)
        {
            double t=1.0*rand()/RAND_MAX;
            if(rand()%2)t=-t;
            printf("%lf ",t);

        }
        puts("");
    }
    return 0;
}