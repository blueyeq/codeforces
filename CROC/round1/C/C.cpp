#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 505;

int sum[MAXN][MAXN];
int dp[MAXN][MAXN][251];
int a[MAXN][MAXN];
int n, m;

int get(int r2, int c2, int r1, int c1)
{
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

int main()
{
    freopen("std.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; ++i)
        {
            int tmp(0);
            for(int j = 1; j <= m; ++j)
            {
                tmp += a[i][j];
                sum[i][j] = sum[i - 1][j] + tmp;
            }
        }
//        printf("%d\n", sum[n][m]);
        memset(dp, 0, sizeof(dp));
        int ans(-1000000000);
        for(int i = 3; i <= n; ++i)
        for(int j = 3; j <= m; ++j)
        {
            int len(3), id(0);
            for(; len <= min(i, j); len += 2, id++)
            {
                if(len == 3)  dp[i][j][0] = get(i, j, i - 2, j - 2) - a[i - 1][j - 2];
                else if(len == 5)  dp[i][j][1] = get(i, j, i - 4, j - 4) - a[i - 3][j - 4] - get(i - 1, j - 1, i - 3, j - 3) + a[i - 2][j - 3] + a[i - 2][j - 2];
                else  dp[i][j][id] = get(i, j, i - len + 1, j - len + 1) - get(i - 1, j - 1, i - len + 2, j - len + 2) + dp[i - 2][j - 2][id - 2] + a[i - len + 3][j - len + 2] - a[i - len + 2][j - len + 1];
                if(ans < dp[i][j][id])  ans = dp[i][j][id];
//                if(len == 5)printf("%d  %d  %d   %d  %d\n", i, j, id, dp[i][j][id], get(i, j, i - 4, j - 4));
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
