#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;

char mp[MAXN][MAXN];
int cnt[MAXN][MAXN][2];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s", mp[i]);
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cnt[i][j][0] = cnt[i][j][1] = INF;

        cnt[n - 1][m - 1][0] = 0;
        for(int i = n; i >= 0; --i)
        for(int j = m; j >= 0; --j)
        {
            if(mp[i][j] == '.')
            {
                if(j + 1 < m)  cnt[i][j][0] = cnt[i][j + 1][0];
                if(i + 1 < n)  cnt[i][j][1] = cnt[i + 1][j][1];
            }
            else
            {
                if(j + 1 < m)  cnt[i][j][0] = cnt[i][j + 1][0];
                if(i + 1 < n)  cnt[i][j][1] = cnt[i + 1][j][1];
                if(cnt[i][j][0] > cnt[i][j][1] + 1)  cnt[i][j][0] = cnt[i][j][1] + 1;
                if(cnt[i][j][1] > cnt[i][j][0] + 1)  cnt[i][j][1] = cnt[i][j][0] + 1;
            }

        }
        if(cnt[0][0][0] != INF)  printf("%d\n", cnt[0][0][0]);
        else  puts("-1");
    }


    return 0;
}
