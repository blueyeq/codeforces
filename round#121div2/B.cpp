#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int a[MAXN], b[MAXN];

int main()
{
//    freopen("B.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int cnt(0);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", a + i);
            if(i != 0 && i != n - 1) b[cnt++] = a[i];
        }
        b[0] = a[0];
        for(int i = 1; i < n; ++i)
        {
            b[i] = 0;
            if(i > 1 && n != 3)  b[i] = b[i - 2];
            b[i] = max(b[i - 1], b[i]);
            b[i] = min(a[i], b[i]);
        }
        printf("%d\n", b[n - 1]);
    }

    return 0;
}
