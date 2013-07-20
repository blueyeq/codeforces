#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        LL ans(0);
        for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
        {
            LL up = i;
            LL down = n - i;
            LL lt = j;
            LL rt = m - j;
            LL tmp = min(up, down) * min(lt, rt);
            tmp = max(tmp, 0LL);
            ans += tmp;
//            if(ans < 0) puts("error");
        }
        printf("%I64d\n", ans);
    }


    return 0;
}
