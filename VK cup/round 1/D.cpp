#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int>  g[50005];
int n, m;
long long ans;
void dfs(int x, int fa, int flen[])
{
    int tlen[501], tmp[501];
//    printf("%d --> %d\n", fa, x);
    if(fa != -1)
    {
        ans = ans + flen[m - 1];
//        printf("%d  %d\n", x, flen[m - 1]);
        for(int i = 1; i <= m; ++i)
        {
            tlen[i] = flen[i - 1];
            tmp[i] = flen[i - 1];
        }
    }
    else
    {
        memset(tlen, 0, sizeof(tlen));
        memset(tmp, 0, sizeof(tmp));
    }
    tmp[0] = 0;
    tlen[0] = 1;
    for(int i = 0; i < g[x].size(); ++i)
    {
        if(g[x][i] != fa)
        {
            dfs(g[x][i], x, tlen);
        }
    }
//    if(fa == 2)  printf("%d  %d\n", x, flen[1]);
    for(int i = 1; i <= m; ++i)
        flen[i] += tlen[i - 1] - tmp[i - 1];
//    if(fa == 2)  printf("%d  %d\n", x, flen[1]);
}

int main()
{
//    freopen("std.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
            g[i].clear();
        for(int i = 1; i < n; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            g[ta].push_back(tb);
            g[tb].push_back(ta);
        }
        ans = 0;
        int ll[501];
//        for(int i = 1; i <= n; ++i, puts(""))
//        for(int j = 0; j < g[i].size(); ++j)
//            printf("%d  ", g[i][j]);
        if(m <= n)  dfs(1, -1, ll);
        printf("%I64d\n", ans);
    }



    return 0;
}
