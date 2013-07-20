#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 4201000;

int dp[MAXN], ele[MAXN];

int main()
{
    int n, m(22);
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", ele + i);
            dp[ele[i] ^ ((1<<m) - 1)] = ele[i];
        }
        for(int i = 1<<m; i >= 0; --i)
        {
            for(int j = m; dp[i] != -1 && j >= 0; --j)
            {
                if(i & (1<<j))  dp[i^(1<<j)] = dp[i];
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(i == n - 1)   printf("%d\n", dp[ele[i]]);
            else   printf("%d ", dp[ele[i]]);
        }
    }


    return 0;
}
