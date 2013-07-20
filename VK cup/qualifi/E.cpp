#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
const int INF = 1000000000;

int start[MAXN], end[MAXN];
int org_s[MAXN], org_t[MAXN], org_len[MAXN];
int dp[4100][4100];

int main()
{
    //freopen("E.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int pre(1), day(86400);
        start[0] = 0;  end[0] = 0;
        int ans(0);
        for(int i = 1; i <= n; ++i)
        {
            int s, len;
            scanf("%d%d", &s, &len);
            org_s[i] = s;
            org_len[i] = len;
            start[i] = max(s, pre);
            end[i] = min(day, start[i] + len -1);
            pre = end[i] + 1;
            ans = max(ans, org_s[i] - end[i] - 1);
        }
        start[n + 1] = day + 1;  end[++n] = day + 1;   org_s[n] = day + 1;

        for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
        {
            if(i > j)  dp[i][j] = INF;
            else  dp[i][j] = 0;
        }
        for(int i = 0; i <= n; ++i)
            dp[i][0] = end[i];

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j] + 1, org_s[i]) + org_len[i] - 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }

        for(int i = 0; i < n; ++i)
        {
            ans = max(ans, org_s[i + 1] - dp[i][min(m, i)] - 1);
        }
        printf("%d\n",ans);
    }

    return 0;
}
