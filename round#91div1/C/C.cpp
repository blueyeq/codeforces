#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL MAXN = 100000000000LL;

LL a[1000000];
int cnt;
void dfs(LL x)
{
    if(x > MAXN)  return;
    if(x > 0)  a[cnt++] = x;
    dfs(x * 10 + 4);
    dfs(x * 10 + 7);
}
LL fact[15];
int b[15], use[15];
void dfs(int k, int nb, int m, LL n)
{
    if( k < 1)  return;
    for(int i = 1; i <= m; ++i)
    {
        if(use[i])  continue;
        if(n > fact[k - 1] && !use[i])  n -= fact[k - 1];
        else if(n <= fact[k - 1] && !use[i])
        {
            b[nb] = i;
            use[i] = 1;
            dfs(k - 1, nb + 1, m, n);
            return;
        }
    }
}
bool ok(LL x)
{
    while(x > 0)
    {
        if(x % 10 != 4 && x % 10 != 7)  return 0;
        x /= 10;
    }
    return 1;
}
int main()
{
    cnt = 0;
    dfs(0);
    sort(a, a + cnt);
    fact[0] = 1;
    for(int i = 1; i <= 15; ++i)
        fact[i] = fact[i - 1] * i;
    LL n, k;
    for(int i = 1; i < 15; ++i)
        b[i] = i;
//    for(int i = 0; i < 15; ++i)
//        printf("%d  %I64d\n", i, fact[i]);
    while(scanf("%I64d%I64d", &n, &k) != EOF)
    {
        if(n < 15 && fact[n] < k)
        {
            puts("-1");
            continue;
        }
        int i(0);
        for(i = 1; ; ++i)
            if(fact[i] >= k)  break;
        memset(use, 0, sizeof(use));
        dfs(i, 1, i, k);
//        for(int j = 1; j <= i; ++j)
//            printf("%d\n", b[j]);
        LL rt = n - i, res(0);
        for(int j = 1; j <= i; ++j)
        {
            LL t = b[j] + rt;
            if(ok(t) && ok(rt + j))
                ++res;
            //printf("%d  %d\n", j, b[j]);
        }

        i = 0;
        while(a[i] <= rt && i < cnt) ++i;
        res += i;
        printf("%I64d\n", res);
    }

    return 0;
}
