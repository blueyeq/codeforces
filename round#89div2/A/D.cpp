#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const int mod = 100000000;
const int MAXN = 210;

int dp[2][2 * MAXN][2 * MAXN][11][11];

void up(int &a, int b)
{
    a += b;
    if(a > mod)  a-= mod;
}

int main()
{
    int n1, n2, k1, k2;
    while(scanf("%d%d%d%d", &n1, &n2,&k1, &k2) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][n1][n2][0][0] = 1;

        int sum = n1 + n2, now(1);
        for(int k = 1; k <= sum; ++k)
        {
            for(int i = 0; i <= n1; ++i)
            for(int l1 = 0; l1 <= k1 ; ++l1)
            {
                if(sum - k - i > n2) continue;
                for(int l2 = 0; l2 <= k2; ++l2)
                    dp[now][i][sum - k - i][l1][l2] = 0;
            }


            for(int i = 0; i <= n1; ++i)
            for(int l1 = 0; l1 <= k1 && l1 <= n1; ++l1)
            for(int l2 = 0; l2 <= k2 && l2 <= n2; ++l2)
            {
                if(sum - k - i > n2 || sum - i - k < 0) continue;
                if(i < n1 && l1 + 1 <= k1)
                    up(dp[now][i][sum - k - i][l1 + 1][0], dp[!now][i + 1][sum - k - i][l1][l2]);

                if(sum - i - k < n2 && l2 + 1 <= k2)
                    up(dp[now][i][sum - k - i][0][l2 + 1], dp[!now][i][sum - k - i + 1][l1][l2]);
//                if(dp[now][i][sum - k - i][l1 + 1][0] > 0)
//                    printf("*** %d\n", dp[now][i][sum - k - i][l1 + 1][0]);
//                if(dp[now][i][sum - k - i][0][l2 + 1] > 0)
//                    printf("** %d  %d  %d  %d\n",sum, k, i, dp[now][i][sum - k - i][0][l2 + 1]);
            }
            now = !now;
        }
        int res(0);
        for(int l1 = 1; l1 <= k1 && l1 <= n1; ++l1)
            up(res, dp[!now][0][0][l1][0]);
        for(int l2 = 1; l2 <= k2 && l2 <= n2; ++l2)
        {
            up(res, dp[!now][0][0][0][l2]);
        }

        printf("%d\n", res);
    }


    return 0;
}
