#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100010;
queue<int> q;
int come[MAXN], to[MAXN];
int dis[MAXN], tim[MAXN], ans[MAXN];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        while(!q.empty())  q.pop();
        for(int i = 0; i < n; ++i)
            scanf("%d%d", come + i, to + i);
        int now(0);
        for(int i = 0; i < n; i += m)
        {
            int cnt(0);
            for(int j = i; j < i + m && j  < n; ++j)
            {
                q.push(j);
                now = max(now, come[j]);
                dis[cnt++] = to[j];
            }
            sort(dis, dis + cnt);
            int k, waste = 0;
            for(int i = 0; i < cnt; ++i)
            {
                if(i == 0 || dis[i] != dis[i - 1])
                {
                    tim[dis[i]] =  dis[i];
                    if(i != 0)   tim[dis[i]] += 1 + k / 2 + waste;
                    if(i != 0)  waste += 1 + k / 2;
                    k = 1;
                }
                else  ++k;
            }

            while(!q.empty())
            {
                int u = q.front();  q.pop();
                ans[u] = tim[to[u]] + now;
            }
            now += tim[dis[cnt - 1]] + dis[cnt - 1];
            if(cnt == 1 || cnt > 1 && dis[cnt - 1] == dis[cnt - 2])
                now += 1 + k / 2;
        }
        for(int i = 0; i < n; ++i)
            printf("%d%c", ans[i], i == n - 1 ? '\n':' ');
    }


    return 0;
}
