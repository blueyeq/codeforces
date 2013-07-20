#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

int a[MAXN], b[MAXN];

int main()
{
//    freopen("in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i)  b[i] = a[i];

        sort(a, a + n);
        bool fg(0);
        if(b[n - 1] == 1)  fg = 1;
        for(int i = 0; i < n; ++i)
        {
            int ans;
            if(i == n - 1)
            {
                if(fg)  ans = 2;
                else if(i > 0)ans = a[i - 1];
                else ans = 1;
            }
            else if(i == 0)  ans = 1;
            else ans = a[i - 1];
            if(i == n - 1)  printf("%d\n", ans);
            else printf("%d ",ans);
        }
    }


    return 0;
}
