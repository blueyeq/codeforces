/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 0

using namespace std;

typedef long long LL;

int n, m, k;
int op[100010][2];
int pos[1010][1010][4];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char mp[1010][1010];

void init()
{
    memset(pos, 0, sizeof(pos));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
    {
        if(mp[i][j] == '#')  continue;

        if(i == 0 || mp[i - 1][j] == '#')  pos[i][j][0] = 0;
        else  pos[i][j][0] = pos[i - 1][j][0] + 1;

        if(j == 0 || mp[i][j - 1] == '#')  pos[i][j][3] = 0;  //  dir ?
        else  pos[i][j][3] = pos[i][j - 1][3] + 1;
    }

    for(int i = n - 1; i >= 0; --i)
    for(int j = m - 1; j >= 0; --j)
    {
        if(mp[i][j] == '#')  continue;

        if(i == 0 || mp[i + 1][j] == '#')  pos[i][j][2] = 0;
        else  pos[i][j][2] = pos[i + 1][j][2] + 1;

        if(j == 0 || mp[i][j + 1] == '#')  pos[i][j][1] = 0;
        else  pos[i][j][1] = pos[i][j + 1][1] + 1;
    }
}
char s[10];
bool vis[30];

bool dfs(int r, int c, int th)
{
    if(th >= k)  return true;
    if(mp[r][c] == '#')  return false;

    if(pos[r][c][op[th][0]] >= op[th][1])
    {
        if(op[th][0] == 0)  r -= op[th][1];
        else if(op[th][0] == 1)  c += op[th][1];
        else if(op[th][0] == 2)  r += op[th][1];
        else if(op[th][0] == 3)  c -= op[th][1];
        return dfs(r, c, th + 1);
    }
    return false;
}


void solve()
{
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
    {
        if(mp[i][j] != '#' && !vis[mp[i][j] - 'A'])
        {
            if(dfs(i, j, 0))
                vis[mp[i][j] - 'A'] = true;
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s", &mp[i]);
        init();
        scanf("%d", &k);
        for(int i = 0; i < k; ++i)
        {
            scanf("%s%d",s, &op[i][1]);
            if(s[0] == 'N')  op[i][0] = 0;
            else if(s[0] == 'E')  op[i][0] = 1;
            else if(s[0] == 'S')  op[i][0] = 2;
            else if(s[0] == 'W')  op[i][0] = 3;
        }

        memset(vis, 0, sizeof(vis));
        solve();
        bool fg(false);
        for(int i = 0; i < 30; ++i)
        {
            if(vis[i])
            {
                printf("%c", 'A' + i);
                fg = true;
            }
        }
        if(!fg)  printf("no solution");
        puts("");
    }
	return 0;
}
