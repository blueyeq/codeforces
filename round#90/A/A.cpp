#include <stdio.h>
#include <cstring>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b, n;
    while(scanf("%d%d%d", &a, &b, &n) != EOF)
    {
        int len(0);
        while(1)
        {
            int t;
            if(len & 1)  t = gcd(n, b);
            else t = gcd(n, a);
            if(t > n)  break;
            n -= t;
            ++len;
        }
        if(len & 1)  puts("0");
        else puts("1");
    }


    return 0;
}
