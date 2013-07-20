#include <string>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const LL MAXN = 100000000000;

LL a[1000000];
int cnt;
void dfs(LL x)
{
    if(x > MAXN)  return;
    if(x >= 0)  a[cnt++] = x;
    dfs(x * 10 + 4);
    dfs(x * 10 + 7);
}

int main()
{
    LL lt, rt;
    cnt = 0;
    dfs(0);
    sort(a, a + cnt);
    while(scanf("%I64d%I64d", &lt, &rt) != EOF)
    {
        LL pre(lt), ans(0);
        int i = 0;
        while(a[i] < pre && i < cnt)
        {
            ++i;
          //  printf("%I64d  %I64d\n", pre, a[i]);
        }
        //printf("i = %d\n", i);
        --pre;
        for(; a[i] <= rt; ++i)
        {
            ans += (a[i] - pre) * a[i];
            pre = a[i];
        }
        if(i != 0 && a[i - 1] < rt)  ans += a[i] * (rt - max( lt - 1, a[i - 1]));  // if a[i] > pre
        printf("%I64d\n", ans);
    }


    return 0;
}
