#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];

struct Node
{
    int sale, len, id;
    Node(int _sale = 0, int _len = 0)
    {
        sale = _sale, len = _len;
    }
    bool operator < (const Node &other)  const
    {
        return sale > other.sale;
    }
}node[MAXN];

bool cmp1(const  Node &a1, const Node &a2)
{
    return a1.sale > a2.sale;
}
bool cmp2(const Node &a1, const Node &a2)
{
    return a1.len < a2.len;
}
int vis[MAXN], dep, belong[MAXN];

bool dfs(int x)
{
    for(int i = 0; i < g[x].size(); ++i)
    {
        int v = g[x][i];
//        printf("%d  %d  %d  %d\n",x, v, vis[x], dep);
        if(vis[v] == dep)  continue;
        vis[v] = dep;
        if(belong[v] == -1 || dfs(belong[v]))
        {
            belong[v] = x;
            return 1;
        }
    }
    return 0;
}

void debug(int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d %d\n",node[i].len, node[i].sale);
}
int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        map<int, int> hh;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &node[i].sale, &node[i].len);
            hh[node[i].len] = node[i].id = i;
            g[i].clear();
        }
        //sort(node, node + n, cmp2);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);

            int k = hh[tb];
            if(node[k].sale <= ta && node[k].len == tb)
            {
                g[k].push_back(i);
            }

            k = hh[tb + 1];
            if(node[k].sale <= ta && node[k].len == tb + 1)
            {
                g[k].push_back(i);
            }
        }

        memset(belong, -1, sizeof(belong));
        memset(vis, 0, sizeof(vis));
        sort(node, node + n);
        int cnt(0);
         dep = 2;
        long long ans(0);
        for(int i = 0; i < n; ++i)
        {
            ++dep;
            if(dfs(node[i].id))
            {
                ++cnt;
                ans += node[i].sale;
            }
        }
        printf("%I64d\n%d\n", ans, cnt);
        for(int i = 0; i < m; ++i)
            if(belong[i] != -1)  printf("%d %d\n", i + 1, belong[i] + 1);
    }

    return 0;
}
