#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

const int MAXN = 500010;

int col[MAXN * 4],  fa[2][MAXN], next[2][MAXN];
int n, m;
vector<int> g[MAXN];
void build(int id, int lt, int rt)
{
    col[id] = -1;
    if(lt >= rt)
    {
        col[id] = lt;
        return;
    }
    int mid = (lt + rt) >> 1;
    build(id << 1, lt, mid);
    build((id<<1) | 1, mid + 1, rt);
}
void update(int id, int lt, int rt, int nl, int nr, int val)
{
    if(nr < lt || nl > rt)  return;
    if(nl <= lt && nr >= rt)
    {
        col[id] = val;  return;
    }
    int mid = (lt + rt) >> 1;
    update(id<<1, lt, mid, nl, nr, val);
    update((id<<1) | 1, mid + 1, rt, nl, nr, val);
    if(col[id<<1] == col[(id<<1) | 1])  col[id] = col[id<<1];
    else  col[id] = -1;
}
int fc[MAXN];
int findc(int x)
{
    if(fc[x] == x) return x;
    return fc[x] = findc(fc[x]);
}
void query(int id, int lt, int rt)
{
    if(col[id] != -1)
    {
        int nc = findc(col[id]);
        for(int i = lt; i <= rt; ++i)
            g[nc].pb(i);
        return;
    }
    int mid = (lt + rt) >> 1;
    query(id<<1, lt, mid);
    query((id<<1) | 1, mid + 1, rt);
}
int get(int id, int lt, int rt, int nl, int nr)
{
    if(col[id] != -1)  return col[id];
    int mid = (lt + rt) >> 1;
    if(nr <= mid)  return get(id<<1, lt, mid, nl, nr);
    return get((id<<1) | 1, mid + 1, rt, nl, nr);
}
int find(int x, int e)
{
    if(fa[e][x] == x)  return x;
    return fa[e][x] = find(fa[e][x], e);
}
int colNext[MAXN];
int main()
{
//    freopen("std.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            g[i].clear();
            fa[0][i] = fa[1][i] = next[0][i] = next[1][i] = i;
            colNext[i] = fc[i] = i;
        }
        build(1, 1, n);
        for(int i = 1; i <= m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            g[ta].pb(tb);
            g[tb].pb(ta);
        }

        vector<int> :: iterator it1;
        for(int i = 1; i <= n; ++i)
        {
            g[i].pb(n + 1);
            sort(g[i].begin(), g[i].end());

            int lt(1), rt;
            int tc = get(1, 1, n, i, i);
            int root = findc(tc);

            for(it1 = g[i].begin(); it1 != g[i].end(); ++it1)
            {
                int rt = *it1 - 1;
                if(lt > rt)
                {
                    lt = *it1 + 1;
                    continue;
                }
                int f1 = find(lt, 0);
                int f2 = find(rt, 1);

                update(1, 1, n, f1, f2, i);

                for(int j = f1; j <= f2; j = next[0][j] + 1)
                {
                    fa[0][j] = f1;
//                    printf("%d  %d\n", j,colNext[j]);
                    int colFa = findc(colNext[j]);
                    fc[colFa] = root;
//                    printf("%d  %d  %d  %d\n",i, j, colFa, root);
                }
                for(int j = f2; j >= f1; j = next[1][j] - 1)
                    fa[1][j] = f2;
//                printf("%d  %d:  %d  %d  %d  %d\n", i, *it1, lt, rt, f1, f2);
                next[0][f1] = f2;
                next[1][f2] = f1;
                lt = *it1 + 1;
            }
        }
        for(int i = 1; i <= n; ++i)  g[i].clear();
        query(1, 1, n);
        int ans(0);
        for(int i = 1; i <= n; ++i)  if(g[i].size() > 0)  ++ans;
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i)
        {
            if(g[i].size() == 0)   continue;
            printf("%d", g[i].size());
            for(it1 = g[i].begin(); it1 != g[i].end(); ++it1)
                printf(" %d", *it1);
            puts("");
        }

    }

    return 0;
}
