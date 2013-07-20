#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;
typedef long long LL;
int bita[20], bitb[20], bitc[20];

int main()
{
    //536870912
    int a, b, c;
    while(scanf("%d%d", &a, &c) != EOF)
    {
        int la(0), lb(0), lc(0);
        memset(bita, 0, sizeof(bita));
        memset(bitb, 0, sizeof(bitb));
        memset(bitc, 0, sizeof(bitc));
        while(a > 0)
        {
            bita[la++] = a % 3;
            a /= 3;
        }
        while(c > 0)
        {
            bitc[lc++] = c % 3;
            c /= 3;
        }
        int l = max(lc, la);
        for(int i = 0; i < l; ++i)
        {
            bitb[i] = (bitc[i] + 3 - bita[i]) % 3;
        }
        int b(0), t(1);
        for(int i = 0; i < l; ++i)
        {
            b = b + (LL) t * bitb[i];
            t = (LL) t * 3;
            printf("%d\n", bitb[i]);
        }
        printf("%d\n", b);
    }


    return 0;
}
