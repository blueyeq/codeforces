#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

void inline checkMin(int &a, int b) {if(a > b) a = b;}
int main()
{
//    freopen("std.in","r", stdin);
    int day, year;
    while(scanf("%d%d", &day, &year) != EOF)
    {
        LL ans(0);
        for(int i = 0; i < year; ++i)
        {
            int n(i + day), m(day + i);
            for(int j = 1; j * j <= n; ++j)
            {
                if(n % j == 0)
                {
                    int root = sqrt(n / j);
                    if(root * root == n / j)
                        checkMin(m, j);
                    root = sqrt(j);
                    if(root * root == j)
                        checkMin(m, n / j);
                }

            }
            ans += m;
        }
        printf("%I64d\n", ans);
    }



}
