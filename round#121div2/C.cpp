#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 6 * 100000;

char nam[30];
int dp[300][300], b[300][300];

int main()
{
//    freopen("C.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));

        for(int k = 0; k < n; ++k)
        {
            scanf("%s", nam);
            int len(strlen(nam));
            int s = nam[0] - 'a', t = nam[len - 1] - 'a';

            int tmp(0);
            for(int i = 0; i < 26; ++i)
            {
                if(dp[i][s] > 0)
                {
                    b[i][t] =  max(dp[i][t], dp[i][s] + len);
                }else  b[i][t] = 0;
            }

            if(dp[s][t] < len)  dp[s][t] = len;

            for(int i = 0; i < 26; ++i)
            {
                  dp[i][t] = max(dp[i][t], b[i][t]);
            }

        }
        int ans(0);
        for(int i = 0; i < 26; ++i)  ans = max(ans, dp[i][i]);
        printf("%d\n", ans);
    }
    return 0;
}

