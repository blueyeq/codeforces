#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

const int MAXN = 100100;
vector<int> g[MAXN];

struct Node
{
    int l, r, col;
    Node (int a, int b, int c) : l(a), r(b), col(c) {}
    bool operator < (const Node &other)  const
    {
        return l < other.l;
    }
};
vector< Node > vn[2];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)  g[i].clear();
        for(int i = 1; i <= m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            if(ta == tb)  continue;
            g[ta].push_back(tb);
            g[tb].push_back(ta);
        }
        for(int i = 1; i <= n; ++i)  vn[0].pb(Node(i, i, i));
        int now(1);
        for(int i = 1; i <= n; ++i, now = !now)
        {
            sort(g[i].begin(), g[i].end());
            g[i].pb(n + 1);

            vn[now].clear();
            int lt(1), rt;
            for(vector<int>::iterator it1 = g[i].begin(); it1 != g[i].end(); ++it1)
            {
                rt =  *it1 - 1;
                if(lt > rt)
                {
                    lt = *it1 + 1;
                    continue;
                }
                for(vector<Node> ::iterator it2 = vn[!now].begin(); it2 != vn[!now].end(); ++it2)
                {
                    int l = it2->l;
                    int r = it2->r;
                    if(l > rt)
                    {
                        vn[now].pb(Node(lt, rt, i));
                        break;
                    }
                    if(!(r < lt || l > rt))
                    {
                        rt = max(r, rt);
                        lt = min(lt, l);
                        vn[!now].erase(it2);
                        --it2;
//                        printf("%d  %d   %d   %d\n", l, r, lt, rt);
                    }
                }
                if(lt <= rt)  vn[now].pb(Node(lt, rt, i));
//                printf("%d  %d  %d\n", i, lt, rt);
                lt = *it1 + 1;
            }
            for(vector<Node> ::iterator it2 = vn[!now].begin(); it2 != vn[!now].end(); ++it2)
                vn[now].pb(*it2);

            sort(vn[now].begin(), vn[now].end());
            rt = vn[now][0].r;
            int col(vn[now][0].col);
//            for(vector<Node>::iterator it2 = vn[now].begin(); it2 != vn[now].end(); it2++)
//            {
//                printf("**%d  %d  %d  %d\n", i, it2->l, it2->r, it2->col);
//            }
            for(vector<Node>::iterator it2 = vn[now].begin() + 1, it1; it2 != vn[now].end(); it2++)
            {
                if(it2->l <= rt)
                {
                    it1 = it2 - 1;
                    if(it1->r < it2->r)  it1->r = it2->r;
                    if(it2->col == i) it1->col = i;
                    vn[now].erase(it2);
                    it2--;

                }
                else
                {
//                    it1 = it2 - 1;
//                    it1->r = rt;
//                    it1->col = col;
//                    col = it2->col;
                    rt = it2->r;
                }
            }

//            for(vector<Node>::iterator it2 = vn[now].begin(); it2 != vn[now].end(); it2++)
//            {
//                printf("^^%d  %d  %d  %d\n", i, it2->l, it2->r, it2->col);
//            }
        }
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(vector<Node>::iterator it2 = vn[!now].begin();  it2 != vn[!now].end(); ++it2)
        {
            int l = it2->l;
            int r = it2->r;
            int col = it2->col;
            for(int j = l; j <= r; ++j)
                g[col].pb(j);
        }
        int ans(0);
        for(int i = 1; i <= n; ++i)  if(g[i].size() > 0)  ++ans;
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i)
        {
            if(g[i].size() == 0)  continue;
            printf("%d", g[i].size());
            for(vector<int> ::iterator it1 = g[i].begin(); it1 != g[i].end(); ++it1)
                printf(" %d", *it1);
            puts("");
        }

    }
    return 0;
}
