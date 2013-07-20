#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int MAXN = 210;
const int INF = 10000000;

int dp[(1<<7) + 10][MAXN];
int mp[MAXN][MAXN];
int num[MAXN][MAXN];
int f[1<<7][MAXN][3],  dv[1<<7][MAXN], vis[MAXN][MAXN];
int n, m, numImportant;

void dfs(int u, int i)
{
    if(dv[u][i])  return;
    dv[u][i] = 1;
    int uu = f[u][i][0];
    int j = f[u][i][1];
    vis[i / m][i % m] = 1;
    if(j != -1)  vis[j / m][j % m] = 1;
    if(j != -1 && f[uu][j][0] != -1) dfs(uu, j);
    if(f[u ^ uu][i][0] != -1)  dfs(u ^ uu, i);
}
int dx[5] = {0, 0, -1, 1, 0};
int dy[5] = {-1, 1, 0, 0, 0};

int main()
{
    while(scanf("%d%d%d", &n, &m, &numImportant) != EOF)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &mp[i][j]);
        memset(num, -1, sizeof(num));
        for(int i = 0; i < numImportant; ++i)
        {
            int px, py;
            scanf("%d%d", &px, &py);
            num[px - 1][py - 1] = i;
        }
        int cnt = n * m;
        for(int i = 0; i < (1 << numImportant); ++i)
            for(int j = 0; j < cnt; ++j)
                dp[i][j] = INF;
        memset(f, -1, sizeof(f));
        memset(vis, 0, sizeof(vis));
        int ans(INF), full((1<<numImportant) - 1), ans_i;
        for(int i = 0; i < cnt; ++i)
        {
            if(num[i / m][i % m] != -1)
            {
                dp[1<<num[i / m][i % m]][i] = mp[i / m][i % m];
                if(numImportant == 1)
                {
                    ans = dp[full][i];
                    ans_i = i;
                }
                vis[i / m][i % m] = 1;
            }
            else   dp[0][i] = mp[i / m][i % m];
        }

        int h = cnt / 2;
        for(int j = 1; j < h; ++j)
            for(int u1 = 1; u1 <= full; ++u1)
                for(int u2 = 0; u2 <= u1; ++u2)
                {
                    if((u1 & u2) != u2)  continue;
                    for(int i = 0; i < n; ++i)
                        for(int j = 0; j < m; ++j)
                            for(int k = 0; k < 5; ++k)
                            {
                                int r1 = i + dx[k], c1 = j + dy[k];
                                int v1 = i * m + j, v2 = r1 * m + c1;
                                if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && dp[u2][v1] != INF && dp[u1 ^ u2][v2] != INF)
                                {
                                    int t = dp[u2][v1] + dp[u1 ^ u2][v2];
                                    if(k == 5)   t -= mp[i][j];
                                    if(t < dp[u1][v1])
                                    {
                                        dp[u1][v1] = t;
                                        f[u1][v1][0] = u1 ^ u2;
                                        f[u1][v1][1] = v2;
                                    }
                                    if(u1 == full && ans >= t)
                                    {
                                        ans = t;
                                        ans_i = v1;
                                    }
                                }
                            }
                }
        printf("%d\n", ans, ans_i);
        memset(dv, 0, sizeof(dv));
        if(numImportant > 1)dfs(full, ans_i);

        for(int i = 0; i < n; ++i, puts(""))
            for(int j = 0; j < m; ++j)
            {
                char c = '.';
                if(vis[i][j])  c = 'X';
                putchar(c);
            }
    }
    return 0;
}
