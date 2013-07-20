#include <stdio.h>

using namespace std;

typedef long long LL;

int main()
{
    int a;
    while(scanf("%d", &a) != EOF)
    {
        LL ans(1), dx(3);
        for(int i = 2; i <= a; ++i)
        {
            ans += 6 * dx - 6;
            dx += 2;
        }
        printf("%I64d\n", ans);
    }



}
