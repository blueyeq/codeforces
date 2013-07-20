#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

const int MAXN = 210;
const LL INF = 1000000000000000000LL;
int n, m;
LL dp[2][MAXN * 2][2];
int ch[MAXN * 2];

int r[MAXN * MAXN], c[MAXN * MAXN];

inline LL add(int s, int sum)
{
    return dp[s][sum][0] + dp[s][sum][1];
}

LL get()
{
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;
    int now(0);
    for(int i = m + n - 1; i >= 2; --i, now = !now)
    {
        for(int j = 0; j <= m + n; ++j)
            dp[now][j][0] = dp[now][j][1] = 0;
        for(int j = 0; j <= m + n - i + 1; ++j)
        {

            if(ch[i] == ')')
            {
                if(j > 0)  dp[now][j][1] += add(!now, j - 1);
            }
            else if(ch[i] == '(')
            {
                dp[now][j][0] += add(!now, j + 1);
            }
            else if(ch[i] == -1)
            {
                dp[now][j][0] += add(!now, j + 1);
                if(j > 0)  dp[now][j][1] += add(!now, j - 1);

            }
            dp[now][j][0] = dp[now][j][0] > INF ? INF : dp[now][j][0];
            dp[now][j][1] = dp[now][j][1] > INF ? INF : dp[now][j][1];
        }

    }
    return dp[!now][0][0];
}

int main()
{
    //freopen("in.", "r", stdin);
    LL th;
    while(scanf("%d%d%I64d", &n, &m, &th) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            int ta;
            scanf("%d", &ta);
            r[ta] = i;
            c[ta] = j;
        }
        memset(ch, -1, sizeof(ch));
        ch[2] = '(';  ch[n + m] = ')';

        for(int i = 1; i <= n * m; ++i)
        {
            if(ch[r[i] + c[i]] != -1)  continue;
            ch[r[i] + c[i]] = '(';
            LL nn = get();
            //printf("%d  %d   %d  %I64d\n", i, r[i], c[i], nn);
            if(th > nn)
            {
                th -= nn;
                ch[r[i] + c[i]] = ')';
            }
        }
        for(int i = 1; i <= n; ++i, puts(""))
        for(int j = 1; j <= m; ++j)
            printf("%c", ch[i + j]);
    }

    return 0;
}
