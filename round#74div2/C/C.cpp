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

LL a[10100];

int main()
{
    int n, m, k;
    while(scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        LL Min(1000000000);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%I64d",&a[i]);
            if((i & 1) && a[i] < Min)
                Min = a[i];
        }
        if(!(n&1))
        {
            printf("0\n");
            continue;
        }
        LL cnt = (n+1) / 2;
        LL num = (LL)m / cnt;
        LL sum = (LL)num * k;  //  here   long long
        if(sum > Min)   sum = Min;
        //sum = min(sum, Min);
        cout<<sum<<endl;
    }
	return 0;
}
