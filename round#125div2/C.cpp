#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
const int MAXN = 1000010;

LL get(int x, int n, LL k, LL b)
{
    LL res(0), f(1);
    for(int i = 0; i <= n - x - 1; ++i, f *= k)
    {
        res += b * f;
        if(res > MAXN)  return MAXN + 10000;
//        if(n == 4 && x == 0 && b == 4 && k == 1)
//        {
////            printf(">>>>%d  %I64d  %I64d\n", i, res, f);
//        }
    }
    res += f;
    return res;
}

int main()
{
//    freopen("C.in", "r", stdin);
    int n; LL t, b, k;
    while(scanf("%I64d%I64d%d%I64d", &k, &b, &n, &t) != EOF)
    {
        int l(0), r(n + 1), res;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            LL tmp = get(mid, n, k, b);
//            printf("%d  %I64d   %I64d\n", mid, t, tmp);
            if(tmp > t)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                res = mid;
            }
        }
        printf("%d\n", res);
    }




    return 0;
}
