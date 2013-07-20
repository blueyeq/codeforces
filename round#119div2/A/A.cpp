#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, a[3];

int main()
{
    while(scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]) != EOF)
    {
        sort(a, a + 3);
        int ans(0);
        for(int x = 0; x * a[0] <= n; ++x)
        for(int y = 0; y * a[1] + x * a[0] <= n; ++y)
        {
            if((n - x * a[0] - y * a[1]) % a[2] == 0)
            {
                ans = max(ans, x + y + (n - x * a[0] - y * a[1]) / a[2] );
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
