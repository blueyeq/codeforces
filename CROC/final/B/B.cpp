#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 300;
const double eps = 1e-9;

int px[MAXN], py[MAXN];
int ans[1000100];
int n, m;

int main()
{
//    freopen("std.in",  "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < m; ++i)
            scanf("%d%d", px + i, py + i);
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
        {
            double dx = px[j] - px[i];
            double dy = py[j] - py[i];
            if(abs(dy) < eps)  continue;

            double axi;
            if(abs(dx) < eps)  axi = px[i];
            else  axi =  (-py[i] * dx) / dy + px[i];
            if(abs(axi - (int) axi) > eps || (int) axi > n || (int) axi < 1) continue;

            int cnt = 0;
            for(int k = 0; k < m; ++k)
            {
                if(k == i || k == j)  continue;
                    if(dy * (px[k] - px[i]) == (py[k] - py[i]) * dx)  ++cnt;
            }
            ans[(int)axi] = max(ans[(int)axi], cnt + 2);
        }
        int sum(0);
        for(int i = 1; i <= n; ++i)
        {
            sum += max(1, ans[i]);
        }
        printf("%d\n", sum);
    }


    return 0;
}
