/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 0

using namespace std;

typedef long long LL;

LL f[55];

int main()
{
    int n;
    LL m;
    f[0] = 0;
    for(int i = 1; i < 55; ++i)
        f[i] = f[i-1] + i;
    while(scanf("%d%I64d",&n,&m) != EOF)
    {
        m %= f[n];
        for(int i = 1; i <= m; ++i)
            m -= i;
        printf("%I64d\n",m);
    }



	return 0;
}
