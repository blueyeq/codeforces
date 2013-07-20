#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 20010;
int val[MAXN];

int get(int dis, int n)
{
    int res(-1000000000);
    for(int i = 1; i <= dis; ++i)
    {
        int tmp(0);
        for(int j = i; j <= n; j += dis)
            tmp += val[j];
        res = res > tmp ? res : tmp;
    }
    return res;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int ans(0);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &val[i]);
            ans += val[i];
        }
        for(int i = 1; i * i <= n; ++i)
        {
            if(n % i == 0)
            {
                if(i >= 3)  ans = max(ans, get(n / i, n));
                if(n / i >= 3)  ans = max(ans, get(i, n));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
