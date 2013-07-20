#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool dp[600][110];

bool ok(int n, int x)
{
    int mid = (n + 1) / 2;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1, k = 1; i <= mid * 2 - 1; ++i)
    {
//        printf("%d  %d\n", i, k);


        for(int j = 1; j <= k; ++j)
        {
            if(j == k && n % 2 == 0)  continue;
            int s=0;
            for(int u = x; u >= 0; --u)
            {
                int v = 4;
                if(j == k && i == mid)  v = 1;
                else  if(j == k)  v = 2;
                if(u >= v)
                {
                    dp[i][u] |= dp[max(0, i - 2)][u - v];
                    dp[i][u] |= dp[i][u - v];
                }
//                if(dp[i][u])  printf("%d  %d  %d\n",i, u, dp[i][u]);
            }
        }
        if(i < mid) ++k;
        else  --k;
        for(int j = 0; j <= x; ++j)
            dp[i][j] |= dp[i - 1][j];
    }
    return dp[mid * 2 - 1][x];
}

int main()
{
//    int sum;
//    ok(5, 9);
//    while(scanf("%d", &sum) != EOF)
    for(int sum = 1; sum <= 100; ++sum)
    {
        int t1, t2;
        for(int i = 1; ; ++i)
        {
            if(ok(i, sum))
            {
//                printf("%d\n", i);
                t1 = i;
                break;
            }
        }
        for(int i = 1; i <= sum; ++i)
        {
            if(2 * i * i - 2 * i + 1 >= sum)
            {
                t2 = 2 * i - 1;
                break;
            }
        }
//        if(t1 != t2)  printf("%d   %d  %d\n",t1, t2, sum);
        printf("%d  %d\n",sum, t1);
    }


    return 0;
}

