#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MAXN = 3010;

int head[MAXN], cnt;
int fa[MAXN], dis[MAXN], dep[MAXN];
bool isloop[MAXN], vis[MAXN];

struct Edg
{
    int v, next;
}edg[MAXN * 2];

void add(int a, int b)
{
    edg[cnt].v = b; edg[cnt].next = head[a]; head[a] = cnt++;
}
int v1, v2;
void dfs(int x, int hig, int f)
{
    if(vis[x])
    {
        v1 = x; v2 = f;
        return ;
    }
    dep[x] = hig;
    fa[x] = f;
    vis[x] = 1;
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        int v = edg[i].v;
        if(v == f)  continue;
        dfs(v, hig + 1, x);
    }
}

void bfs(int x,  int f)
{
    if(vis[x])  return;
    vis[x] = 1;
    if(!isloop[x])   dis[x] = dis[f] + 1;
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        bfs(edg[i].v, x);
    }
}
int main()
{
    //freopen("in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            add(s, t);
            add(t, s);
        }
        memset(vis, 0, sizeof(vis));
        dfs(1, -1, 0);
        memset(isloop, 0, sizeof(isloop));
        while(dep[v1] > dep[v2])
        {
            isloop[v1] = 1;
            v1 = fa[v1];
        }
        while(dep[v2] > dep[v1])
        {
            isloop[v2] = 1;
            v2 = fa[v2];
        }
        while(v1 != v2)
        {
            isloop[v1] = isloop[v2] = 1;
            v1 = fa[v1];
            v2 = fa[v2];
        }
        isloop[v1] = 1;
        for(int i = 1; i <= n; ++i)
            dis[i] = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(isloop[i])
            {
                memset(vis, 0, sizeof(vis));
                bfs(i, -1);
                break;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == n) printf("%d\n", dis[i]);
            else printf("%d ", dis[i]);
        }
    }



    return 0;
}
