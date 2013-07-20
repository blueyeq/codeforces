#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

char name[110];
bool have[110][30];

typedef long long LL;

int main()
{
    //freopen("in.c", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(have, 0, sizeof(have));
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", name);
            for(int j = 0; j < m; ++j)
                have[j][name[j] - 'A'] = 1;
        }
        LL ans = 1;
        for(int j = 0; j < m; ++j)
        {
            int tmp(0);
            for(int k = 0; k < 26; ++k)
                if(have[j][k])  ++tmp;
           // printf("tmp = %d\n", tmp);
            ans = (LL) ans * tmp % 1000000007;
        }
        printf("%I64d\n", ans);
    }



    return 0;
}
