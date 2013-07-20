#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 400010;
const int INF = 1000000000;

int a[MAXN], q[MAXN];
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        int l =0,  r =0;
        q[l] = a[0];
        LL res(0);
        for(int i = 1; i < n; ++i)
        {
            while(l <= r && q[r] <= a[i])
            {
                res += a[i] - q[r];
                --r;
            }
            q[++r] = a[i];
        }
        while(l < r)
        {
            res -= q[r] - q[r - 1];
            --r;
        }
        res -= q[r];
        printf("%I64d\n", res);
    }


    return 0;
}

