#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 200100;

struct Line
{
    int start, end, tim, id;
    bool typ;
    bool operator < (const Line &l) const
    {
        if(start != l.start)  return start < l.start;
        if(typ != l.typ)  return typ < l.typ;
        return end < l.end;
    }
}node[MAXN];

int cnt;
int ele[MAXN * 3];

int find(int x)
{
    int l(1), r(cnt), res, mid;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(ele[mid] == x)  return cnt - mid + 1;
        if(ele[mid] > x)   r = mid - 1;
        else  l = mid + 1;
    }
    return -1;
}

const int INF = -1;
int c[MAXN], src[MAXN];

void update(int x, int val, int from)
{
    while(x <= cnt)
    {
        if(c[x] < val)
        {
            c[x] = val;
            src[x] = from;
        }
        x += x & (-x);
    }
}
int get(int x, int tim)
{
    int res(-1), Max(INF);
    while(x > 0)
    {
        if(Max < c[x])
        {
            Max = c[x];
            res = src[x];
        }
        x -= x & (-x);
    }
   // printf("%d   %d\n", tim, Min);
    if(tim <= Max)  return res;
    return -1;
}
typedef long long LL;
int ans[MAXN];
int main()
{
    LL k = (1LL<<40) - 1;
    int a = (int) ((k - 1)/ 1);
    printf("%d", a);
//    freopen("E.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d%d", &node[i].start, &node[i].end, &node[i].tim);
            node[i].id = i + 1;
            node[i].typ = 0;
            ele[++cnt] = node[i].start;
            ele[++cnt] = node[i].end;
        }
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &node[i + n].start, &node[i + n].end, &node[i + n].tim);
            node[i + n].id = i + 1;
            node[i + n].typ = 1;
            ele[++cnt] = node[i + n].start;
            ele[++cnt] = node[i + n].end;
        }
        sort(node, node + n + m);
//        for(int i = 0; i < n + m; ++i)
//            printf("node: %d  %d  %d   %d\n", node[i].start, node[i].end, node[i].id, node[i].typ);

        sort(ele + 1, ele + cnt + 1);
        int k = 1;
        for(int i = 2; i <= cnt; ++i)
            if(ele[i] != ele[i - 1])  ele[++k] = ele[i];
        cnt = k;
//        for(int i = 1; i <= cnt; ++i)
//            printf("ele: %d\n", ele[i]);

        for(int i = 1; i <= cnt; ++i)   c[i] = INF;

        for(int i = 0; i < n + m; ++i)
        {
            int ss = find(node[i].start);
            int tt = find(node[i].end);
//            printf("%d  %d\n", ss, tt);
            if(!node[i].typ)
                update(tt, node[i].tim, node[i].id);
            else
                ans[node[i].id] = get(tt, node[i].tim);
        }
        for(int i = 1; i <= m; ++i)
        {
            if(i == m)  printf("%d\n", ans[i]);
            else  printf("%d ", ans[i]);
        }
    }
    return 0;
}
