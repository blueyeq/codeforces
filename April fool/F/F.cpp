#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;


const int MAXN = 1000000;
bool dele[MAXN];
int prim[MAXN];

int rev(int x)
{
    int res(0);
    while(x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

void init()
{
    int cnt(0);
    for(int i = 2; i < MAXN; ++i)
    {
        if(!dele[i])  prim[cnt++] = i;
        for(int j = 0; j < cnt && prim[j] * i < MAXN; ++j)
        {
            dele[i * prim[j]] = 1;
            if(i % prim[j] == 0)  break;
        }
    }

    int k(0);
    for(int i = 0; i < cnt; ++i)
    {
        int tmp = rev(prim[i]);
        if(!dele[tmp] && tmp != prim[i])    prim[k++] = prim[i];
    }
//    printf("kk %d   %d\n", k, cnt);
//    for(int i = 0; i < 10; ++i)
//        printf("%d\n", prim[i]);
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", prim[n - 1]);
    }

    return 0;
}




