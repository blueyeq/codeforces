#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0, s = 2 * n; i <= 2 * n; ++i, puts(""))
        {
            int t;
            if(i <= n)  t = 2 * n + 2 * (i + 1);
            else t = 2 * n + 2 * (i - (i - n) + 1);

            for(int j = 0, h(0); j < t && h >= 0; ++j)
            {
                if(j % 2 == 0 && j >= s)
                {
                    printf("%d", h);
                    if(j < 2 * n)  ++h;
                    else --h;
                }
                else putchar(' ');
            }
            if(i < n)  s -= 2;
            else s += 2;
        }
    }
    return 0;
}
