#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 400010;
const int INF = 1000000000;

int a[MAXN], b[MAXN], c[MAXN], cnt1[MAXN], cnt2[MAXN];
int n, cnt;
void readin()
{
    cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",a + i, b + i);
        c[cnt++] = a[i];
        c[cnt++] = b[i];

    }
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    sort(c, c + cnt);
    cnt = unique(c, c + cnt) - c;
    for(int i = 0; i < n; ++i)
    {
        int id1 = lower_bound(c, c + cnt, a[i]) - c;
        int id2 = lower_bound(c, c + cnt, b[i]) - c;
        ++cnt1[id1];
        if(id1 != id2)  ++cnt2[id2];
    }
}
int main()
{
//    freopen("D.in", "r", stdin);
    while(~scanf("%d", &n))
    {
        readin();
        int mid = (n + 1) / 2;
        int ans(mid + 1);
        for(int i = 0; i < cnt; ++i)
        {
            if(cnt1[i] + cnt2[i] >= mid)
            {
                ans = min(ans, mid - cnt1[i]);
                ans = max(ans, 0);
//                printf("%d  %d  %d\n", c[i], cnt1[i], cnt2[i]);
            }
        }
        if(ans > mid)  ans = -1;
        printf("%d\n", ans);
    }


    return 0;
}

