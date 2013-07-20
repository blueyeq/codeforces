#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

bool ok(LL x)
{
    LL h = sqrt(x * 2);
    for(int i = -2; i <= 2; ++i)
    {
        if(i + h >= 0)
        {
            if((LL)(i + h) * (i + h + 1) / 2 == x)  return 1;
        }
    }
    return 0;
}

int main()
{
//    freopen(".in", "r", stdin);
    LL n;
    while(scanf("%I64d", &n) != EOF)
    {
        bool fg(0);
        for(LL i = 1; i * (i + 1) / 2 < n; ++i)
        {
            if(ok(n - (i + 1) * i / 2))
            {
                fg = 1;
                break;
            }
        }
        printf("%s\n", fg ? "YES" : "NO");
    }

    return 0;
}
