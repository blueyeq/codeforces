#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const int MAXN = 110;

double a[MAXN];
int n;

int main()
{
    double lf;
    while(scanf("%d%lf", &n, &lf) != EOF)
    {
        double sum(0), Max(0);
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &a[i]);
            sum += a[i];
            Max = max(Max, a[i]);
        }
        sum += lf;
        double res = sum / n;
        if(res + eps < Max)
        {
            puts("-1");
            continue;
        }
        for(int i = 0; i < n; ++i)
        {
            printf("%.7lf\n", res - a[i]);
        }
    }


    return 0;
}
