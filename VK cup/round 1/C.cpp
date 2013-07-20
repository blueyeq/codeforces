#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

const LL INF = 1000000000;
LL ans(0);

void dfs(LL l1, LL r1, LL l2, LL r2)
{
    if(l1 > r1 || l2 > r2)  return;
    if(ans > min(r1 - l1, r2 - l2))  return;

    if(l1 > l2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    if(r2 <= r1)
    {
        ans = max(ans, r2 - l2 + 1);
        return;
    }
    if(l2 <= r1)    ans = max(ans, r1 - l2 + 1);

    LL Max(0), cntBit1(0);
    for(LL x = l2; x > 0; x -= x&(-x), ++cntBit1)
        Max = max(Max, x & (-x));

    if(r2 >= (Max << 1))
    {
        dfs(l1, r1, (Max<<1) + 1, r2);
        r2 = (Max<<1) - 1;
    }
    if(cntBit1 == 1)  ++l2;
    if(Max)  dfs(l1, r1, l2 - Max, r2 - Max);
}

int main()
{
//    freopen("std.in", "r", stdin);
    LL l1, r1, l2, r2;
    while(scanf("%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2) != EOF)
    {
        ans = 0;
        dfs(l1, r1, l2, r2);
        printf("%I64d\n", ans);
    }

    return 0;
}
