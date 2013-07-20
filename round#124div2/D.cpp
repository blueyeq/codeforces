#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;

const int INF = 1000000000;
const int MAXN = 1600;

char mp[MAXN][MAXN];

int n, m ;
int vis[2][MAXN][MAXN], src[MAXN][MAXN], vis2[MAXN][MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int r, int c, int e)
{
    if(r < 0 || r >= n || c < 0 || c >= m)
    {
        if(mp[(r + n) % n][(c + m) % m] != '#')printf("===>%d  %d\n", r, c);
        r = (r + n) % n;
        c = (c + m) % m;

        if(mp[r][c] != '#')dfs(r, c, 1);

        return ;
    }
    if(mp[r][c] == '#' || vis[e][r][c])  return ;
    vis[e][r][c] = 1;

    for(int i = 0; i < 4; ++i)
        dfs(r + dx[i], c + dy[i], e);
}


int main()
{
    freopen("D.n", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int r, c;
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", mp[i]);
            for(int j = 0; j < m; ++j)
            {
                if(mp[i][j] == 'S')
                {
                    r = i;
                    c = j;
                }
            }
        }
        memset(src, 0, sizeof(src));
        memset(vis, 0, sizeof(vis));
        dfs(r, c, 0);
        printf("%s\n", vis[1][r][c] ?"Yes" : "No");
    }
    return 0;
}
