#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;

const int mod = 1000000007;
const int MAXN = 110;

char s[MAXN];
int dp[2][30][30];

void up(int &a, int b)
{
    a += b;
    if(a >= mod)  a-= mod;
}

int main()
{
    freopen("C.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF){
        while(n--)
        {
            scanf("%s", s);
            printf("%s\n", s);
            int len(strlen(s));
            memset(dp, 0, sizeof(dp));
            dp[1][0][s[0] - 'a'] = 1;
            int now = 0, ans(0);
            for(int i = 0; i < len - 1; ++i)
            {
                for(int j = 0; j < 26; ++j)
                for(int k = 0; k < 26; ++k)
                    dp[now][j][k] = 0;
                dp[now][s[i] - 'a'][s[i + 1] - 'a'] = 1;

                for(int j = 0; j < 26; ++j)
                {
                    for(int k = 0; k < 26; ++k)
                    {
                        if(!dp[!now][j][k])   continue;
                        for(int d = 1; d < 26; ++d)
                        {
                            if(k + d < 26 && s[i + 1] - 'a' - d >= 0)
                                up(dp[now][k + d][s[i + 1] - 'a' - d], dp[!now][j][k]);
                            if(k - d >= 0 && s[i + 1] - 'a' + d < 26)
                                up(dp[now][k - d][s[i + 1] - 'a' + d], dp[!now][j][k]);
                        }
                    }
                }

                for(int j = 0; j < 26; ++j)
                for(int k = 0; k < 26; ++k)
                    up(ans, dp[now][j][k]);

                up(ans, mod - 1);
                printf("ans = %d\n", ans);
                now = !now;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
