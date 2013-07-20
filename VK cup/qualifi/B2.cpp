#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1010;

int maker[MAXN][MAXN], cap[MAXN][MAXN];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m, ta, tb;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(maker, 0, sizeof(maker));
        memset(cap, 0, sizeof(cap));

        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &ta, &tb);
            ++maker[ta][tb];
        }
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &ta, &tb);
            ++cap[ta][tb];
        }
        int ans1(0),  ans2(0);
        for(int i = 1; i <= 1000; ++i)
        {
            int sz1(0),  sz2(0);
            for(int j = 1; j <= 1000; ++j)
            {
                sz1 += maker[j][i];
                sz2 += cap[j][i];
                ans2 += min(cap[j][i], maker[j][i]);
            }
            ans1 += min(sz1, sz2);
        }
        printf("%d %d\n", ans1, ans2);
    }


    return 0;
}
