#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

typedef long long LL;

LL c[50][50];
void init()
{
    memset(c, 0, sizeof(c));
    for(int i = 0; i < 50; ++i)
        c[i][0] = 1;
    for(int i = 1; i < 50; ++i)
    for(int j = 1; j <= i; ++j)
    {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

int main()
{
    //freopen("in", "r", stdin);
    init();
    LL n, m, t;
    while(scanf("%I64d%I64d%I64d", &n, &m, &t) != EOF)
    {
        LL ans(0);
        for(LL i = 4; i <= n; ++i)
        {
            if(t - i <= m && t - i >= 1)
            {
                ans += c[n][i] * c[m][t - i];
            }
        }
        printf("%I64d\n", ans);
    }


    return 0;
}
