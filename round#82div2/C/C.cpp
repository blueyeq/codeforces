/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 0

using namespace std;

typedef long long LL;

int n, m, c0, d0, lf, ci, bi, di;
int dp[15][1500];

int main()
{
    while(scanf("%d%d%d%d", &n, &m, &c0, &d0) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 0;  i <= n; ++i)
            dp[0][i] = (i / c0) * d0;

        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d%d", &lf, &bi, &ci, &di);

            int j = min(lf / bi, n / ci);
            for(;j > 0; --j)
            {
                int v = j * ci, u = j * di;
                for(int k = n; k >= v; --k)
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - v] + u);
            }
            for(int j = 0; j <= n; ++j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);

        }
        int ans(0);
        for(int i = 0; i <= n; ++i)
            ans = max(ans, dp[m][i]);
        printf("%d\n", ans);
    }



	return 0;
}
