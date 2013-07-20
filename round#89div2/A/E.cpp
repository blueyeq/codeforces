#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int MXN = 100010;

int head[MXN], cnt, nid;

struct Edg
{
    int v, id, next, from;
    bool fg;
}edg[MXN * 6];

inline void add(int a, int b, int id)
{
    edg[cnt].v = b; edg[cnt].next = head[a]; edg[cnt].id = id;
    edg[cnt].fg = 0;  edg[cnt].from = a; head[a] = cnt++;
}

int dfn[MXN],  low[MXN], belong[MXN];
stack<int> st;
bool inStack[MXN];
void dfs(int x, int f)
{
    dfn[x] = low[x] = nid++;
    st.push(x);  inStack[x] = 1;
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        int v = edg[i].v;
        if(edg[i].v == f)  continue;
        if(dfn[v] == -1)
        {
            edg[i].fg = 1;
            dfs(v, x);
            low[x] = min(low[x], low[v]);
        }
        else if(inStack[v])
        {
            if(dfn[v] < low[x] && x != 1)
                edg[i].fg = 1;
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(low[x] == dfn[x])
    {
        while(!st.empty())
        {
            int u = st.top();  st.pop();
            belong[u] = cnt;
            if(u == x)  break;
        }
        ++cnt;
    }
}

bool vis[MXN * 6];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            add(ta, tb, i);
            add(tb, ta, i);
        }
        memset(inStack, 0, sizeof(inStack));
        memset(dfn, -1, sizeof(dfn));
        cnt = nid = 0;
        while(!st.empty())  st.pop();
        dfs(1, -1);
        bool fg(cnt == 1);

        for(int i = 1; i <= n && fg; ++i)
        {
            if(belong[i] != 0 || dfn[i] == -1)  fg = 0;
        }
        if(!fg)  puts("0");
        else
        {
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < 2 * m; ++i)
            {
                if(edg[i].fg)   vis[edg[i].id] = 1;
            }
            for(int i = 0; i < 2 * m; ++i)
            {
                if(edg[i].fg || !vis[edg[i].id])
                {
                    vis[edg[i].id] = 1;
                    printf("%d %d\n", edg[i].from, edg[i].v);
                }
            }
        }
    }
    return 0;
}
