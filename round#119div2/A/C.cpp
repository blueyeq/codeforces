#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


const int MAXN = 200100;

int a[MAXN], b[MAXN], p[MAXN];

int main()
{
    int n;
//    freopen("C.in", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)  scanf("%d", a + i);
        for(int i = 1, j; i <= n; ++i)
        {

            scanf("%d", &j);
            p[j] = i;
        }
        int Mx(0), ans(0);
        for(int i = 1; i <= n; ++i)
        {
            if(p[a[i]] < Mx)
            {
//                printf("--%d\n", i);
                ans = n - i + 1;
                break;
            }
            Mx = p[a[i]];
        }
        printf("%d\n", ans);
    }


    return 0;
}
