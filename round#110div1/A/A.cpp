#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

const int MAXN = 2100;

int dp[MAXN][MAXN];
char s1[MAXN], s2[MAXN];

int main()
{
//    freopen("A.in", "r", stdin);
    while(scanf("%s%s", s1 + 1, s2 + 1) != EOF)
    {
        s1[0] = s2[0] = '#';
        int len1(strlen(s1)), len2(strlen(s2));

        for(int i = 0; i < len1; ++i)
            dp[i][0] = 0;
        for(int i = 0; i < len2; ++i)
            dp[0][i] = i;
        dp[0][0] = 0;
        for(int i = 1; i < len1; ++i)
        for(int j = 1; j < len2; ++j)
        {
            dp[i][j] = j;
            if(s1[i] == s2[j])   dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);  //  mody
        }
        int ans(len2);
        for(int i = 0; i < len1; ++i)
        for(int j = 0; j < len2; ++j)
            ans = min(dp[i][j] + len2 - j - 1, ans);
        printf("%d\n", ans);
    }


    return 0;
}
