#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


int gcd(int a, int b)
{
    return b?gcd(b, a % b) : a;
}
int f[100010];
int main()
{
    int g12, g23, g123;
    int n, s;
    while(scanf("%d%d", &n, &s) != EOF)
    {
        int c1(0), c2(0), c3(0);
        for(int i = 0, j; i < n; ++i)
        {
            scanf("%d", &j);
            if(j == 3) ++c1;
            if(j == 2) ++c2;
            if(j == 5) ++c3;
        }
        g12 = c1 * c2 / gcd(c1, c2);
        g23 = c2 * c3 / gcd(c2, c3);
        for(int i = 1; i <= g23 * 2 && i <= s; ++i)
        {
            f[s] = -1;
            for(int j = 0; j <= i; ++j)
            {
                if((i - c2 * j) % c3 == 0)
                {
                    int tmp = abs(c2 * j - i - c2 * j) / 3;
                }
            }
        }
    }



    return 0;
}

