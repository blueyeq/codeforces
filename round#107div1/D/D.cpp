#include <stdio.h>
#include <string>
#include <cstring>

using namespace  std;

const int MAXN = 160;
const int INF = -100000000;

int cost[MAXN], f[MAXN][MAXN], g[MAXN][MAXN][MAXN];
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
        for(int len = 0; len <= n; ++len)
        for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
        for(int k = 0; k <= n; ++k)
        {
            g[i][j][k] = INF;
            if(j < i && k == 0)   g[i][j][k] = 0;
        }
        memset(f, 0, sizeof(f));
        for(int len = 1; len <= n; ++len)
        for(int i = 0; i + len <= n; ++i)
        {
            g[i][i][1] = 0;

            if(cost[1] != -1)  g[i][i][0] = cost[1];
            int j = i + len - 1;
            if(s[i] == s[j] && i < j)
            {
                for(int tlen = 2; tlen <= len; ++tlen)
                for(int v = i; v <= j - 1; ++v)
                {
                    if(g[i + 1][v][tlen - 2] != INF && g[v + 1][j - 1][0] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i + 1][v][tlen - 2] + g[v + 1][j - 1][0]);
                    if(g[i + 1][v][0] != INF && g[v + 1][j - 1][tlen - 2] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i + 1][v][0] + g[v + 1][j - 1][tlen - 2]);
                }
                    //g[i][j][tlen] = max(g[i][j][tlen], max(g[i + 1][v][tlen - 2] + g[v + 1][j - 1][0], g[i + 1][v][0] + g[v + 1][j - 1][tlen - 2]));
            }
            for(int tlen = 0; tlen <= len; ++tlen)
            {
                for(int v = i; v <= j; ++v)
                {
                    if(g[i][v][0] != INF && g[v + 1][j][tlen] != INF)
                        g[i][j][tlen] = max( g[i][j][tlen], g[i][v][0] + g[v + 1][j][tlen]);
                    if(g[i][v][tlen] != INF && g[v + 1][j][0] != INF)
                        g[i][j][tlen] = max(g[i][j][tlen], g[i][v][tlen] + g[v + 1][j][0] );
                }
                if(cost[tlen] != -1 && g[i][j][tlen] != INF)
                    g[i][j][0] = max(g[i][j][0], g[i][j][tlen] + cost[tlen]);
            }
        }
//        int x, y, z;
//        while(scanf("%d%d%d", &x, &y, &z) != EOF)  printf("%d\n", g[x][y][z]);
        for(int len = 1; len <= n; ++len)
        for(int i = 0; i + len <= n; ++i)
        {
            int j = i + len - 1;
            for(int k = i; k <= j; ++k)
            {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
                if(i == j && cost[1] != -1)  f[i][i] = cost[1];
            }
            if(s[i] == s[j] && i < j)
            {
                for(int v = 0; v <= len - 2; ++v)
                {
                    if(cost[v + 2] != -1 && g[i + 1][j - 1][v] != INF)
                        f[i][j] = max(f[i][j], g[i + 1][j - 1][v] + cost[v + 2]);
                    if(cost[2] != -1 && cost[v] != -1 && g[i + 1][j - 1][v] != INF)
                        f[i][j] = max(f[i][j], g[i + 1][j - 1][v] + cost[2] + cost[v]);
                }
            }
        }
        printf("%d\n", f[0][n - 1]);
    }

    return 0;
}
