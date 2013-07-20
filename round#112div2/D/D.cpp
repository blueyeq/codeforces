#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100010;

int ele[3 * MAXN][2];
vector<int> lca[MAXN];

int typ[MAXN * 3], val[MAXN * 3],  ans_lca[MAXN * 3];
int pre[MAXN], final[MAXN], color[MAXN], depth[MAXN];

int belong[MAXN], head[MAXN];
struct Edg
{
    int v, next, eid;
}edg[MAXN * 2];

int cnt, n, m;
void inline add(int a, int b, int c)
{
    edg[cnt].v = b; edg[cnt].next = head[a];  edg[cnt].eid = c; head[a] = cnt++;
}

int father[MAXN];

int find(int x)
{
    if(father[x] == x)  return x;
    return father[x] = find(father[x]);
}
void dfs(int x, int dep)
{
    pre[x] = ++cnt;
    color[x] = 1;
    depth[x] = dep;
    father[x] = x;
    for(int i = head[x]; i != -1; i = edg[i].next)
    {
        int v = edg[i].v;
//        printf("%d-->%d\n", x, v);
        if(color[v] == -1)
        {
            dfs(v, dep + 1);
            belong[edg[i].eid] = v;
            father[v] = x;
        }
    }
    for(int i = 0; i < lca[x].size(); ++i)
    {
        int id = lca[x][i];
        int v = ele[id][0];
        if(v == x)  v = ele[id][1];
        if(color[v] != -1)   ans_lca[id] = find(v);
    }
    final[x] = cnt;
}

int c[MAXN];
void update(int x, int v)
{
    while(x <= n)
    {
        c[x] += v;
        x += x & (-x);
    }
}
int get(int x)
{
    int res(0);
    while(x > 0)
    {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}
int main()
{
//    freopen("std.in", "r", stdin);
    int ta, tb, tc;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)  lca[i].clear();
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d", &ta, &tb);
            add(ta, tb, i);
            add(tb, ta, i);
        }
//        for(int i = 1; i <= n; ++i, puts(""))
//        for(int j = head[i]; j != -1; j = edg[j].next)
//            printf(">>%d  ",  edg[j].v);

        scanf("%d", &m);
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d",typ + i);
            if(typ[i] == 1 || typ[i] == 2)
                scanf("%d", val + i);
            else
            {
                scanf("%d%d", &ele[i][0], &ele[i][1]);
                lca[ele[i][0]].push_back(i);
                lca[ele[i][1]].push_back(i);
            }
        }

        memset(color, -1, sizeof(color));
        cnt = 0;
        dfs(1, 0);

        memset(c, 0, sizeof(c));
        memset(color, 0, sizeof(color));
        for(int i = 1; i <= m; ++i)
        {
//            printf("typ-> %d\n", typ[i]);
            if(typ[i] == 1)
            {
                if(color[val[i]] == 1)   //  bian hei
                {
                    int v = belong[val[i]];
                    update(pre[v], -1);
                    update(final[v] + 1, 1);
                    color[val[i]] = 0;
                }
            }
            if(typ[i] == 2)
            {
                if(color[val[i]] == 0)
                {
                    int v = belong[val[i]];
//                    printf("%d   %d   %d\n", pre[v], final[v], val[i]);
                    update(pre[v], 1);
                    update(final[v] + 1, -1);
                    color[val[i]] = 1;
                }
            }
            if(typ[i] == 3)
            {
//                printf("lca: %d\n", ans_lca[i]);
                int fa = ans_lca[i];
                int v1 = ele[i][0];
                int v2 = ele[i][1];

                int sum1 = get(pre[fa]) * 2;
                int sum2 = get(pre[v1]);
                int sum3 = get(pre[v2]);
                int ans = -1;
                if(sum1 == sum2 + sum3)  ans = depth[v1] - depth[fa] + depth[v2] - depth[fa];
                printf("%d\n", ans);
            }
        }
    }



    return 0;
}
