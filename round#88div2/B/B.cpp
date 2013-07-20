#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 10000010;
bool vis[MAXN];

int main()
{
    LL a, b, m;
    while(scanf("%I64d%I64d%I64d", &a, &b, &m) != EOF)
    {
        bool fg(0);
        int ans(-3);
        if(b < m - 1)
        {
            fg = 0;
            int t(1000000000 % m);
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i <= b; ++i)
            {
                int v = (LL) t * i % m;
                vis[v]  = 1;
            }
            for(int i = 1; i <= a && i <= m; ++i)
            {
                int v = (LL) t * i % m;
                if((m - v) % m > b)
                {
                    ans = i;
                    fg = 1;
                    break;
                }
            }
        }
        if(!fg)  puts("2");
        else printf("1 %0.9d\n", ans);
    }
    return 0;
}
