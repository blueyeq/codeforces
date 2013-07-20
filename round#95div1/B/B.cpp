#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

LL a[11], b[11], c[11];

int main()
{
   // freopen("in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; ++i)
        {
            int ta;
            scanf("%d", &ta);
            if(ta > 0)  ++a[ta];
            else if(ta < 0)  ++b[-ta];
            else ++c[0];
        }
        LL ans(0);
        for(int i = 1; i <= 10; ++i)
        {
            ans += a[i] * b[i];
        }
        if(c[0] > 1)  ans += (LL) (c[0] - 1) * c[0] / 2;
        printf("%I64d\n", ans);
    }

    return 0;
}
