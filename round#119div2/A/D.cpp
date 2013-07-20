#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 62;
const int INF = 1000000000;

int dis[MAXN][MAXN][MAXN];
int g[MAXN][MAXN][MAXN];
int n, car, q;

int main()
{
//    freopen("D.in", "r", stdin);
    while(scanf("%d%d%d", &n, &car, &q) != EOF)
    {
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        for(int u = 0; u < n; ++u)
        {
            dis[i][j][u] = INF;
            if(i == j)  dis[i][j][u] = 0;
        }

        for(int i = 0; i < car; ++i)
        for(int j = 0; j < n; ++j)
        for(int k = 0; k < n; ++k)
           scanf("%d", &g[j][k][i]);

        for(int u = 0; u < car; ++u)
        for(int k = 0; k < n; ++k)
        for(int j = 0; j < n; ++j)
        for(int i = 0; i < n; ++i)
            g[i][j][u] = min(g[i][j][u], g[i][k][u] + g[k][j][u]);

        for(int u = 0; u < car; ++u)
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dis[i][j][0] = min(dis[i][j][0], g[i][j][u]);


        for(int tim = 1; tim < n; ++tim)
        for(int k = 1; k < n; ++k)
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            dis[i][j][tim] = min(dis[i][j][tim], dis[i][k][tim - 1] + dis[k][j][0]);
            dis[i][j][tim] = min(dis[i][j][tim], dis[i][k][0] + dis[k][j][tim - 1]);
            dis[i][j][tim] = min(dis[i][j][tim], dis[i][j][tim - 1]);
//            printf("--%d\n", dis[i][j][tim]);
        }
        for(int i = 0; i < q; ++i)
        {
            int ta, tb, tc;
            scanf("%d%d%d", &ta, &tb, &tc); --ta; --tb;
            int ans(INF);
            for(int j = 0; j <= tc && j < n; ++j)
            {
                ans = min(ans, dis[ta][tb][j]);
            }
            printf("%d\n", ans);
        }
        // query  --s --t;
    }
    return 0;
}
