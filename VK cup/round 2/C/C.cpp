#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 100010;
const double eps = 1e-10;

double pos[MAXN * 2];
double ans[MAXN];

int main()
{
//    freopen("C.in", "r", stdin);
    int n;
    double dis, v1, v2;
    while(scanf("%d%lf%lf%lf", &n, &dis, &v1, &v2) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &pos[i]);
            pos[i + n] = pos[i] + dis + dis;
        }

        pos[n + n] = 1e20;

        double lt(pos[0]), rt = dis /(v1 + v2) * v2 + lt;
        int ptr1(0), ptr2(0);
        while(pos[ptr2 + 1] < rt + eps)  ++ptr2;

        memset(ans, 0, sizeof(ans));
        while(ptr1 < n)
        {
            double l1 = pos[ptr1 + 1] - lt;
            double l2 = pos[ptr2 + 1] - rt;
            if(l1 < l2 + eps)
            {
                ans[ptr2 - ptr1] += l1;
                lt += l1;
                rt += l1;
                ++ptr1;
            }
            else
            {
                ans[ptr2 - ptr1] += l2;
                lt += l2;
                rt += l2;
                ++ptr2;
            }
//            printf("%d   %d   %lf    %lf   %lf   %lf\n", ptr1, ptr2, lt,  rt, l1, l2);
        }
        for(int i = 0; i <= n; ++i)
        {
            if(i == n)  printf("%.9lf\n", ans[n] / (dis * 2));
            else  printf("%.9lf ", ans[i] / (dis * 2.0));
        }
    }


    return 0;
}
