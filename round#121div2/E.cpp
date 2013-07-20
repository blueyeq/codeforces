#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100010;
int head[MAXN], n, m, e_cnt;
int fa[MAXN], color[MAXN], we[MAXN], val[MAXN];

struct Edg
{
    int v, next, w, id;
}edg[MAXN * 2];
vector<int> g[MAXN];

inline void add(int a, int b, int id)
{
    edg[e_cnt].v = b; edg[e_cnt].next = head[a];
    edg[e_cnt].id = id;  head[a] = e_cnt++;
}

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unin(int x, int pre)
{
    fa[x] = x;
    color[x] = 1;
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        if(edg[i].v != pre)  unin(edg[i].v, x);
    }
    for(vector<int> ::iterator it = g[x].begin(); it != g[x].end(); ++it)
    {
        if(color[*it] == 0)  continue;
        int f1 = find(*it);
        if(f1 == *it)  continue;
//        printf("%d %d  %d\n", x, *it, f1);
        val[f1] -= 2;
        ++val[*it];
        ++val[x];
    }
    fa[x] = pre;
}
void dfs(int x, int pre)
{
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        int v = edg[i].v;
        if(v == pre)  continue;
        dfs(v, x);
        val[x] += val[v];
//        printf("->%d  %d  %d\n", edg[i].id, v, val[v]);
        we[edg[i].id] = val[v];
    }
}
int main()
{
//    freopen("E.in", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        memset(head, -1, sizeof(head));
        e_cnt = 0;
        int ta, tb;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d", &ta, &tb);
            add(ta, tb, i);
            add(tb, ta, i);
        }
        for(int i = 1; i <= n; ++i)  g[i].clear();
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &ta, &tb);
            g[ta].push_back(tb);
            g[tb].push_back(ta);
        }
        memset(color, 0, sizeof(color));
        memset(val, 0, sizeof(val));
        unin(1, 1);

        dfs(1, 1);
        for(int i = 1; i < n; ++i)
        {
            printf("%d", we[i]);
            printf("%c", i == n - 1 ? '\n' : ' ');
        }
    }



    return 0;
}
