#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;
const int MAXN = 1000100;
int sz[MAXN];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(m == 1)
        {
            for(int i = 1; i <= n; ++i)
                puts("1");
            continue;
        }
        int mid = (m + 1) / 2;
        double mm = (m + 1) / 2.0;
        int lt = mid;
        int rt = mid + 1;
        memset(sz, 0, sizeof(sz));
        for(int i = 1; i <= n; ++i)
        {
            int res;
            if(sz[lt] > sz[rt])
            {
                res = rt;
                ++sz[rt];
                rt++;
                if(rt > m)  rt = mid + 1;  //
            }
            else if(sz[lt] < sz[rt])
            {
                res = lt;
                ++sz[lt];
                --lt;
                if(lt < 1)  lt = mid;
            }
            else
            {
                 if(fabs(lt - mm) > fabs(rt - mm))
                 {
                    res = rt;
                    ++sz[rt];
                    rt++;
                    if(rt > m)  rt = mid + 1;  //
                 }
                 else
                 {
                    res = lt;
                    ++sz[lt];
                    --lt;
                    if(lt < 1)  lt = mid;
                 }
            }
            printf("%d\n", res);
        }
    }


    return 0;
}
