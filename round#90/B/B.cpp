#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

const double eps = 1e-10;
double val[110], b[110];
bool vis[110];

int main()
{
    int n, num, m;
    while(scanf("%d%d", &n, &num) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%lf", &val[i]);
        scanf("%d", &m);
        double Min(10000000000.0), Max(-1.0);
        memset(vis, 0, sizeof(vis));
        int per = n / num;
        for(int i = 0; i < m; ++i)
        {
            double tmp(0.0);
            int ta;
            for(int i = 0; i < per; ++i)
            {
                scanf("%d", &ta);
                --ta;
                vis[ta] = 1;
                tmp += val[ta];
            }
            tmp = (double) tmp / per;
            if(tmp - Max > eps)  Max = tmp;
            if(Min - tmp > eps)  Min = tmp;
        }
        int cnt(0);
        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])  b[cnt++] = val[i];
        }
        sort(b, b + cnt);
        if(cnt >= per)
        {
            double tmp(0.0);
            for(int i = 0; i < per; ++i)
                tmp += b[i];
            tmp = (double) tmp / per;
            if(tmp - Max > eps)  Max = tmp;
            if(Min - tmp > eps)  Min = tmp;
            tmp = 0;
            for(int i = cnt - 1; i >= cnt - per; --i)
                tmp += b[i];
            tmp = (double) tmp / per;

            if(tmp - Max > eps)  Max = tmp;
            if(Min - tmp > eps)  Min = tmp;
        }
        printf("%.6lf %.6lf\n", Min, Max);
    }


    return 0;
}
