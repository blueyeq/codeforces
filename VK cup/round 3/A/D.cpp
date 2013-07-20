#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 100010;
const int MAXM = 100010;

int n, m, e_cnt;
int head[2][MAXN], typ[MAXN];
bool vis[2][MAXN];

struct Edg
{
    int v, next;
}edg[MAXM * 4];

void add(int a, int b, int e)
{
    edg[e_cnt].v = b;  edg[e_cnt].next = head[e][a];  head[e][a] = e_cnt++;
}

void dfs(int x, int e, bool flag)
{
    if(vis[e][x])  return;
    vis[e][x] = 1;
    if(typ[x] == 1 && !flag && e == 1)  return ;
    for(int i = head[e][x]; i != -1; i = edg[i].next)
        dfs(edg[i].v, e, 0);
}
int main()
{
//    freopen("D.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", typ + i);
        e_cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            add(ta, tb, 0);
            add(tb, ta, 1);
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++i)
        {
            if(typ[i] == 1)  dfs(i, 0, 1);
            if(typ[i] == 2)  dfs(i, 1, 1);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(vis[0][i] && vis[1][i])   puts("1");
            else  puts("0");
        }
    }
    return 0;
}
