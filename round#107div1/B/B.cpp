#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long LL;

const LL mod = 1000000007;

int main()
{
    LL n, m, k;
    while(scanf("%I64d%I64d%I64d", &n, &m, &k) != EOF)
    {
        LL ans = 1;
        if(k == 1 || k > n)
        {
            for(int i = 0; i < n; ++i)  ans = ans * m % mod;
        }
        else if(n == k)
        {
            for(int i = 0; i < (n + 1) / 2; ++i)  ans = ans * m % mod;
        }
        else if(k & 1)  ans = m * m % mod;
        else ans = m;
        printf("%I64d\n", ans);

    }

    return 0;
}
