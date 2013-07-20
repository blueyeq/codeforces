#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;
const int MAXN = 100010;

LL a[MAXN], b[MAXN];

int main()
{
//    freopen("D.in", "r", stdin);
    int n, day; LL m;
    while(scanf("%d%d", &n, &day) != EOF)
    {
        scanf("%I64d", &m);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        --n;
        sort(b, b + n);
        LL sum(0);
        for(int i = n - 1, j(0); i >= 0 && j < day - 1; --i, ++j)   sum += b[i];

        printf("%I64d  %d  %d\n", sum, day, n);
        int ans(n + 1);
        for(int i = 0;  i < n; ++i)
        {
            if(day > n)
            {
                if(sum > m)
                {
                    ans = i + 1;
                    break;
                }
                continue;
            }
            if(b[n-day] >= a[i])  // b[n-day] >= a[i]
            {
                if(sum + a[i] > m)
                {
                    ans = i + 1;
                    break;
                }
            }
            else
            {
                if(sum + b[n - day] > m)
                {
                    ans = i + 1;
                    break;
                }
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}

