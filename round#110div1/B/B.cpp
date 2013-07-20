#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

const int MAXN = 100010;

int is[MAXN], notIs[MAXN];
int val[MAXN];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; ++i)     is[i] = notIs[i] = 0;

        int sumNotIs(0);
        for(int i = 1, j; i <= n; ++i)
        {
            scanf("%d", &j);
            val[i] = j;
            if(j > 0)  ++is[j];
            else ++notIs[-j];
            if(j < 0)  ++sumNotIs;
        }
        int TRUTH(0);
        for(int i = 1; i <= n; ++i)
        {
            if(is[i] + sumNotIs - notIs[i] == m)  ++TRUTH;
        }
        for(int i = 1; i <= n; ++i)
        {
            int j = val[i];
            if(j < 0)  j = -j;
            int k = is[j] + sumNotIs - notIs[j];
            if(k == m)
            {
                if(TRUTH == 1 && val[i] == -j)  puts("Lie");
                else if(TRUTH == 1)  puts("Truth");
                else if(TRUTH > 1 ) puts("Not defined");
            }
            else
            {
                if(val[i] < 0)  puts("Truth");
                else puts("Lie");
            }

        }
    }


    return 0;
}
