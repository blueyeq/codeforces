#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double eps = 1e-9;

int main()
{
    int n;
    double dis, vv;
    while(scanf("%d%lf%lf", &n, &vv, &dis) != EOF)
    {
        double pre(0);
        for(int i = 0; i < n; ++i)
        {
            double v, tim;
            scanf("%lf%lf", &tim, &v);
            double t = v / vv;
            double len = 0.5 * vv * t * t;
            if(dis - len > eps)
            {
                t += (dis - len) / v;
            }
            else
            {
                t = sqrt(2.0 * dis / vv);
            }
            t += tim;
            t = max(t, pre);
            if(i == n - 1) printf("%.5lf\n", t);
            else  printf("%.5lf\n", t);
            pre = t;
        }
    }


    return 0;
}
