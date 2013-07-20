#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int n;
double p[25];
double k[25];
double have[25];
double inline min(double a, double b)
{
    return a < b ? a : b;
}
int main()
{
    double v, a;
    while(scanf("%d%lf",&n,&v) != EOF)
    {
        double sum(0);
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf",&k[i]);
            sum += k[i];
        }
        for(int i = 0; i < n; ++i)
        {
            p[i] = k[i] / sum;

        }
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf",&have[i]);
        }
        double ans = v;
        for(int i = 0; i < n; ++i)
        {

            ans = min(ans,have[i]/p[i]);
        }
        printf("%.4lf\n",ans);
    }

}
