#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 1000010;
char ch[MAXN], tmp[MAXN];
int a[MAXN];

int main()
{
//    freopen("in", "r", stdin);
    while(scanf("%s", tmp) != EOF)
    {
        int n = strlen(tmp);
        for(int i = 0, j = n - 1; j >= 0; --j, ++i)
            ch[i] = tmp[j];
        ch[n] = 0;
//        printf("%s\n", ch);
        memset(a, 0, sizeof(a));

        int pres(-1000), pret(-1000);
        for(int i = 0; i < n; ++i)
        {
            while(ch[i] == '0' && i < n) ++i;
            if(i >= n)  break;
            if(pret - pres >= 1 && pret + 2 >= i)
            {
                if(pret + 2 == i)
                {
                    a[pret + 1] = -1;
                    while(ch[i] == '1' && i < n)  ++i;
                    pret = i - 1;
                    a[pret + 1] = 1;
                }
            }
            else
            {
                pres = i;
                a[pres] = -1;
                while(ch[i] == '1' && i < n) ++i;
                pret = i - 1;
                if(pret - pres >= 1)  a[pret + 1] = 1;
                else a[pres] = 1;
            }
        }
        int m(0);
        for(int i = 0; i <= n; ++i)
            if(a[i] != 0)  ++m;
        printf("%d\n", m);
        for(int i = 0; i <= n; ++i)
        {
            if(a[i] == 1)  printf("+2^%d\n", i);
            if(a[i] == -1)  printf("-2^%d\n", i);
        }
    }
    return 0;
}
