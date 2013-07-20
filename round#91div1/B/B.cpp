#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 100010;

char bit[MAXN];

int main()
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        scanf("%s", bit);
        for(int i = 0; i < n; ++i)
        {
            if(k <= 0)  break;
            if(bit[i] == '4' && i + 1 < n && bit[i + 1] == '7')
            {
                --k;
                if(i&1)  bit[i] = '7';
                else bit[i + 1] = '4';
                if(i + 2 < n && bit[i + 1] == '4' && bit[i + 2] == '7')
                {
                    if(k & 1)
                    {
                        if(i&1)  bit[i] = '4';
                        else bit[i + 1] = '7';
                    }
                    k = -1000;
                }
                if(i > 0 && bit[i - 1] == '4' && bit[i] == '7')
                {
                    if(k & 1)
                    {
                        if(i & 1)  bit[i] = '4';
                        else bit[i + 1] = '7';
                    }
                     k = -1000;
                }
            }
        }
        printf("%s\n", bit);
    }
    return 0;
}
