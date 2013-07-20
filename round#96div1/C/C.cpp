#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

bool dp[110][300][50][2];
char ch[110];
int dis[2] = {1, -1};
int main()
{
    int n;
//    freopen("in", "r", stdin);
    while(scanf("%s%d",ch + 1, &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i += 2)
            dp[0][110][i][0] = 1;
        ch[0] = '1';
        int len(strlen(ch));
        for(int i = 1; i < len; ++i)
        for(int j = 0; j < 250; ++j)
        for(int k = 0; k <= n; ++k)
        {
            for(int dir = 0; dir < 2; ++dir)
            {
                if(!dp[i - 1][j][k][dir])  continue;
                if(ch[i] == 'F')
                {
                    dp[i][j + dis[dir]][k][dir] = 1;
                    dp[i][j][k + 1][1 - dir] = 1;   // change dir
                }
                else
                {
                    dp[i][j][k][1 - dir] = 1;
                    dp[i][j + dis[dir]][k + 1][dir] = 1;
                }

                for(int u = 2; k + u <= n && dp[i][j][k][dir]; u += 2)
                    dp[i][j][k + u][dir] = 1;
            }
        }
        int ans(-1);
        for(int j = 0; j < 250; ++j)
        for(int k = 0; k < 2; ++k)
            if(dp[len - 1][j][n][k])
            {
                ans = max(ans, abs(j - 110));
            }
        printf("%d\n", ans);
    }


    return 0;
}
