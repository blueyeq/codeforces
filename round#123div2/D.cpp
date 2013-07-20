#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

const double eps = 1e-10;
const int MAXN = 100010;
double pos[MAXN];


int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int cnt(0);
        for(int i = 0; i < n; ++i)
        {
            double tk, tb;
            scanf("%lf%lf", &tk, &tb);
            if(fabs(tk) < eps)  continue;
            pos[cnt++] = tb / tk;
        }
        if(cnt == 0)
        {
            puts("0");
            continue;
        }
        sort(pos, pos + cnt);
        printf("%d\n", unique(pos, pos + cnt) - pos);
    }


    return 0;
}

