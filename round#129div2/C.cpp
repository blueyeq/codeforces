#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 30;
const int INF = 1000000000;
char dig[30];
LL fun(int l)
{
    LL res(1);
    if(l <= 2)  return 9;
    for(int i = 3; i <= l; ++i)  res = res * 10LL;
    res *= 9;
    return res;
}
LL fact[30];
LL get(LL x)
{
    if(x < 10)  return x;  //  x = 0
    sprintf(dig, "%I64d", x);

    LL res(0);
    int len = strlen(dig);
    for(int i = 2; i <= len; ++i)   res += fun(i - 1);

    int s = dig[0] - '0';
    int t = dig[len - 1] - '0';
    if(s >= 2)  res += (LL)(s - 1) * fact[len - 2];

    LL tmp(0);
    for(int i = 1; i < len - 1; ++i) tmp = tmp * 10 + dig[i] - '0';
    if(t < s) res += tmp;
    else if(t >= s) res += tmp + 1;
    return res;
}
int main()
{
//    freopen("C.in", "r", stdin);
    fact[0] = 1;
    for(int i = 1; i < 30; ++i)  fact[i] = fact[i - 1] * 10;
    LL A, B;
    while(~scanf("%I64d%I64d", &A, &B))
    {
//        printf("%I64d  %I64d\n", get(B) , get(A));
        printf("%I64d\n", get(B) -get(A - 1));
    }

    return 0;
}

