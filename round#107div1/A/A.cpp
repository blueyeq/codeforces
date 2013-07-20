#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

int main()
{
    LL n;
    while(scanf("%I64d", &n) != EOF)
    {
        int h = 0, ans(-1), pri1(-1), pri2(-1);
        LL t = n;
        for(int i = 2; (LL) i * i <= n; ++i)
        {
            while(n % i == 0)
            {
                n /= i;
                ++h;
                if(h == 1)  pri1 = i;
                if(h == 2)  pri2 = i;
            }
            if(h >= 3)  break;
        }
        if(n > 1)
        {
            ++h;
            ans = n;
        }
        if(h <= 1)   printf("1\n0\n");
        else if(h == 2)  printf("2\n");
        else
        {
            printf("1\n%I64d\n", (LL)pri1 * pri2);
        }

    }



    return 0;
}
