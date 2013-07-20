#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;

const int INF = 1000000000;
const int MAXN = 1000;

int a[MAXN], b[MAXN];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
         for(int i = 0; i <= n; ++i)
        {
            scanf("%d", &a[i]);

        }
        for(int j = 0 ;j <= m; ++j)
        {
            scanf("%d", &b[j]);
        }
        if(n == m)
        {
            if(b[0] < 0)
            {
                b[0] = -b[0];
                a[0] = -a[0];
            }
            int g = gcd(abs(a[0]), abs(b[0]));
            printf("%d/%d\n", a[0]/  g, b[0] / g);
        }
        if(n > m)
        {
            if(a[0] * b[0] > 0)
            {
                puts("Infinity");
            }
            else  puts("-Infinity");
        }
        else if(n < m)
        {
            puts("0/1");
        }
    }
    return 0;
}

