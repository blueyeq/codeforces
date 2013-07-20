#include <stdio.h>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

const double eps = 1e-15;

int main()
{
    freopen("in", "r", stdin);
    double t1, t2, t0;
    int x1, x2;
    while(scanf("%lf%lf%d%d%lf", &t1, &t2, &x1, &x2, &t0) != EOF)
    {
        double dis(1e10);
        if(fabs(t1 - t0) < eps && fabs(t2 - t0) < eps)
        {
            printf("%d %d\n", x1, x2);
            continue;
        }
        if(fabs(t2 - t0) < eps)
        {
            printf("%d %d\n", 0, x2);
            continue;
        }
        if(fabs(t1 - t0) < eps)
        {
            printf("%d %d\n", x1, 0);
            continue;
        }

        int ans, ans1, ans2;
        for(int y1 = x1; y1 >= 0; --y1)
        {
            double  tmp = (t0 * y1 - t1 * y1) / (t2 - t0);

            for(int i = -1; i <= 1; ++i)
            {
                int y2 = (int) tmp + i;
                double tt = (t1 * y1 + t2 * y2) / (double)(y1 + y2);
                if(y2 < 0 || y2 > x2) continue;
                if(tt - t0 >= eps || tt == t0)
                {
                    if(tt - t0 < dis)
                    {
                        dis = tt - t0;
                        ans = y1 + y2;
                        ans1 = y1;
                        ans2 = y2;
                    }
                    else if(fabs(tt - t0 - dis) < eps && y1 + y2 > ans)
                    {
                        ans = y1 + y2;
                        ans1 = y1;
                        ans2 = y2;
                    }
                }
            }
        }
        if(ans1 == 0)  ans2 = x2;
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}
