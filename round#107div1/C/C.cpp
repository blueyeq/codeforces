#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 150010;

struct Node
{
    LL ml, mr, val, Max;
}node[MAXN * 4];

Node Add(Node a, Node b)
{
    Node c;
    c.val = a.val + b.val;
    c.Max = max(a.Max, b.Max);
    c.ml = max(a.ml, a.val + b.ml);
    c.mr = max(b.mr, b.val + a.mr);
    c.Max = max(c.Max, a.mr + b.ml);
    return c;
}
LL value[MAXN];

void inline update(int id, int lc, int rc)
{
    node[id].val = node[lc].val + node[rc].val;
    node[id].ml = max(node[lc].ml, node[lc].val + node[rc].ml);
    node[id].mr = max(node[rc].mr, node[rc].val + node[lc].mr);
    node[id].Max = max(node[lc].Max, node[rc].Max);
    node[id].Max = max(node[id].Max, node[lc].mr + node[rc].ml);
}
void build(int id, int lt, int rt)
{
    if(lt >= rt)
    {
        node[id].val = node[id].ml = node[id].mr = value[lt];
        node[id].Max = max(0LL, value[lt]);
        return;
    }
    int mid = (lt + rt) >> 1;
    build(id * 2, lt, mid);
    build(id * 2 + 1, mid + 1, rt);
    update(id, id << 1, (id<<1) + 1);
}
Node query(int id, int lt, int rt, int ql, int qr)
{
    if(ql <= lt && qr >= rt)  return node[id];
    int mid = (lt + rt) >> 1;
    if(qr <= mid)  return query(id * 2, lt, mid, ql, qr);
    else if(ql > mid)  return query(id * 2 + 1, mid + 1, rt, ql, qr);
    else  return Add(query(id * 2, lt, mid , ql, qr) , query(id * 2 + 1, mid + 1, rt, ql, qr));
}
int main()
{
//    freopen("in.c", "r", stdin);
    int n, m;
    LL ff;
    while(scanf("%d%d%I64d", &n, &m, &ff) != EOF)
    {
        LL pre, now;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%I64d", &now);
            if(i > 1)    value[i - 1] = (LL)100 * (now - pre);
            pre = now;
        }
        LL precent;
        for(int i = 1; i < n; ++i)
        {
            scanf("%I64d", &precent);
            value[i] = value[i] / 2 - precent * ff;
        }
        build(1, 1, n - 1);
        int start, end;
        LL ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &start, &end);
            Node tmp = query(1, 1, n - 1, start, end - 1);
            ans += tmp.Max;
        }
        printf("%.6lf\n", (double)ans/100.00);
    }


    return 0;
}
