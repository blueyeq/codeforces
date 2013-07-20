#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 160;
const int INF = -1000000000;

int f[MAXN][MAXN], g[MAXN][MAXN][MAXN], cost[MAXN];
char s[MAXN];

int main()
{
//    freopen("D.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &cost[i]);
        scanf("%s", s);
        cost[0] = 0;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        for(int k = 0; k < n; ++k)
        {
            g[i][j][k] = INF;
            if(j < i && k == 0)  g[i][j][k] = 0;
        }
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; ++i)
        {
            if(cost[1] != -1)   g[i][i][0] = f[i][i] = cost[1];
            g[i][i][1] = 0;
        }

        for(int len = 1; len <= n; ++len)
        for(int i = 0; i + len <= n; ++i)
        {
            int j = i + len - 1;
            for(int tlen = 0; tlen <= len; ++tlen)
            {
                for(int k = i; k < j; ++k)
                {
                    if(g[i][k][0] != INF && g[k + 1][j][tlen] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i][k][0] + g[k + 1][j][tlen]);
                    if(g[i][k][tlen] != INF && g[k + 1][j][0] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i][k][tlen] + g[k + 1][j][0]);
                    if(tlen >= 2 && s[i] == s[j] && g[i + 1][j - 1][tlen - 2] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i + 1][j - 1][tlen - 2]);
                }
                if(cost[tlen] != -1 && g[i][j][tlen] != INF)
                    g[i][j][0] = max(g[i][j][0], g[i][j][tlen] + cost[tlen]);
            }
        }
        for(int len = 2; len <= n; ++len)
        for(int i = 0; i + len <= n; ++i)
        {
            int j = i + len - 1;
            for(int k = i; k < j; ++k)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
            if(s[i] == s[j])
            {
                for(int tlen = 0; tlen <= len - 2; ++tlen)
                {
                    if(g[i + 1][j - 1][tlen] != INF && cost[tlen + 2] != -1)
                        f[i][j] = max(f[i][j], g[i + 1][j - 1][tlen] + cost[tlen + 2]);
                }
            }
        }
        printf("%d\n", f[0][n - 1]);
    }

    return 0;
}

