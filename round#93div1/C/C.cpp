#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 2010;

char mp[MAXN][MAXN];
int col[MAXN], diag[MAXN];

int main()
{
    //freopen("in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s", mp[i]);
        memset(col, 0, sizeof(col));
        memset(diag, 0, sizeof(diag));
        int ans(0);
        for(int i = 0; i < n; ++i)
        {
            int tmp(0);
            for(int j = n - 1; j > i; --j)
            {
                if(mp[i][j] == '1' && (col[j] + tmp) % 2 == 0
                || mp[i][j] == '0' && (col[j] + tmp) % 2 == 1)
                {
                    ++ans;
                    ++col[j];
                    ++tmp;
                    ++diag[i];  ++diag[j];
                }
            }
        }
        memset(col, 0, sizeof(col));
        for(int i = n - 1; i >= 0; --i)
        {
            int tmp(0);
            for(int j = 0; j < i; ++j)
            {
                if(mp[i][j] == '1' && (col[j] + tmp) % 2 == 0
                || mp[i][j] == '0' && (col[j] + tmp) % 2 == 1)
                {
                    ++ans;
                    ++col[j];
                    ++tmp;
                    ++diag[i];  ++diag[j];
                }
            }
        }
        for(int i = 0; i < n; ++i)
            if(mp[i][i] == '0' && diag[i] % 2 == 1
            || mp[i][i] == '1' && diag[i] % 2 == 0)
                ++ans;
        printf("%d\n", ans);
    }

    return 0;
}
