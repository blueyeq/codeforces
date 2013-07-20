#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;

const int MAXN = 500000;

int a[MAXN], b[MAXN], num[MAXN];

int main()
{
//    freopen("cfd.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b + n);
        int cnt = unique(b, b + n) - b;
        memset(num, 0, sizeof(num));

        int lt(0);
        LL ans(0);
        for(int i = 0; i < n; ++i)
        {
            int id = lower_bound(b, b + cnt, a[i]) - b;
            num[id]++;
//            printf("%d  %d  %d\n", lt, id, num[id]);
            while(num[id] == m)
            {
                int tid = lower_bound(b, b + cnt, a[lt]) - b;
                --num[tid];
                ans += n - i;
//                printf("add: %d\n", n - i );
                ++lt;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
