#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 210;
const double eps = 1e-10;

double dp[MAXN][MAXN][MAXN + MAXN];

double pro[MAXN];
int val[MAXN];

int main()
{
//    freopen("B.in", "r", stdin);
    int n, m, init;
    while(scanf("%d%d%d", &n, &m, &init) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &pro[i]);
            pro[i] *= 0.01;
        }
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &val[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][init + 200] = 1.0;
        for(int i = 0; i < n; ++i)
        for(int k = 0; k <= i; ++k)
        {
            for(int j = 0; j <= 401; ++j)
            {
                if(dp[i][k][j] < eps)  continue;

                dp[i + 1][k][j] += dp[i][k][j] * (1.0 - pro[i]);
                if(val[i] + j >= 0)  dp[i + 1][k + 1][min(401, j + val[i])] += dp[i][k][j] * pro[i];
            }
        }
        double ans(0.0);
        for(int i = m; i <= n; ++i)
        for(int k = 200; k <= 401; ++k)
            ans +=  dp[n][i][k];
        printf("%.7lf\n", ans);
    }
    return 0;
}
