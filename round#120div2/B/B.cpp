#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;

const double eps = 1e-9;

double sqr(double x)
{
    return x * x;
}
int main()
{
    double px1, px2, py1, py2, r1, r2;
    while(scanf("%lf%lf%lf%lf%lf%lf", &px1, &py1, &r1, &px2, &py2, &r2) != EOF)
    {
        double len = sqrt(sqr(px1 - px2) + sqr(py1 - py2));

        double ans;
        if(r1 + r2 - len + eps >= 0)   ans = 0.0;
        else
        {
            ans = 0.5 * (len - r1 - r2);
        }
        printf("%.7lf\n", ans);

    }


    return 0;
}

