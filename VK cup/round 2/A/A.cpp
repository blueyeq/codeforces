#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 5010;
const int mod = 1000000007;

int dp[2][MAXN];
char strS[MAXN], strT[MAXN];

int main()
{
//    freopen("A.in", "r", stdin);
    while(scanf("%s%s", strS + 1, strT + 1) != EOF)
    {
        strS[0] = strT[0] = '#';
        int lenS = strlen(strS);
        int lenT = strlen(strT);

        int now(1);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < lenT; ++i)
        {
            dp[!now][0] = 0;
            for(int j = 1; j < lenS; ++j)
            {
                if(strT[i] == strS[j])
                {
                    dp[now][j] = (dp[!now][j - 1] + 1 + dp[!now][j]) % mod;
                }
                else
                {
                    dp[now][j] = dp[!now][j];
                }
            }
            now = !now;
        }
        int ans(0);
        for(int i = 1; i < lenS; ++i)
            ans = (ans + dp[!now][i]) % mod;
        printf("%d\n", ans);
    }


    return 0;
}
