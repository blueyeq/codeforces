#include <stdio.h>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000000;
int n, m, numV;
int head[MAXN], e_cnt, s, t;
bool volunt[MAXN];

struct Edg
{
    int v, next;
}edg[MAXN * 4];

inline void add(int a, int b)
{
    edg[e_cnt].v = b; edg[e_cnt].next = head[a];  head[a] = e_cnt++;
}
int dis[MAXN];
bool inq[MAXN];
bool spfa(int x)
{
    for(int i = 1; i <= n; ++i)
        dis[i] = INF;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();  q.pop();  inq[u] = 0;
        if(volunt[u])  dis[u] = 0;

        for(int i = head[u]; i != -1; i = edg[i].next)
        {
            int v = edg[i].v;
            if(dis[v] > dis[u] + 1 && dis[u] + 1 <= x)
            {
                dis[v] = dis[u] + 1;
                if(!inq[v])  q.push(v);
                inq[v] = 1;
            }
        }
    }
    return dis[t] != INF;
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &numV) != EOF)
    {
        memset(volunt, 0, sizeof(volunt));
        e_cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0, j; i < numV; ++i)
        {
            scanf("%d", &j);
            volunt[j] = 1;
        }
        for(int i = 0; i < m; ++i)
        {
            int ta, tb;
            scanf("%d%d", &ta, &tb);
            add(ta, tb);
            add(tb, ta);
        }
        scanf("%d%d", &s, &t);
        int rt(m), lt(1), ans(-1);
        while(lt <= rt)
        {
            int mid = (lt + rt) >> 1;
            if(spfa(mid))
            {
                rt = mid - 1;
                ans = mid;
            }else
                lt = mid + 1;
        }
        printf("%d\n", ans);
    }


    return 0;
}
