#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char s[1010];
int f[1010];
int tmp[1010], h[1010], num[30];

int find(int x)
{
    if(f[x] == x)  return x;
    return f[x] = find(f[x]);
}

int main()
{
    while(scanf("%s", s) != EOF)
    {
        int n = strlen(s);
        for(int i = 1; i <= n; ++i)
            f[i] = i;
        for(int i = 2; i <= n; ++i)
        {
            int cnt(0);
            int t = i;
            for(int j = 2; j <= t; ++j)
            {
                if(t % j == 0)
                {
                    f[find(j)] = t;
                }
            }
        }
        memset(num, 0, sizeof(num));
        memset(h, 0, sizeof(h));
        for(int i = 1; i <= n; ++i)
            ++h[find(i)];
        for(int i = 0; i < n; ++i)
            ++num[s[i] - 'a'];
        bool fg(1);
        for(int i = n; i >= 1 && fg; --i)
        {
            if(h[i] == 0)  continue;
            int Min(10000), Min_j(-1);
            for(int j = 0; j < 26; ++j)
            {
                if(num[j] >= h[i] && num[j] < Min)
                {
                    Min = num[j];
                    Min_j = j;
                }
            }
            if(Min_j == -1)  fg = 0;
            else num[Min_j] -= h[i], h[i] = Min_j;
        }
        if(!fg)  puts("NO");
        else
        {
            puts("YES");
            for(int i = 1; i <= n; ++i)
            {
                printf("%c", h[find(i)] + 'a');
            }
            puts("");
        }
    }



    return 0;
}




