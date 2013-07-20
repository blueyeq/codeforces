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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    if(a == b)  printf("Equal\n");
    else
    {
        int div = gcd(a, b);
        LL g = (LL) a / div * b;

        LL t1 = (LL)g / a - 1;
        LL t2 = (LL)g / b - 1;
        if(a < b)   ++t2;
        else ++t1;

        if(t1 > t2) printf("Dasha\n");
        else if(t1 < t2)    printf("Masha\n");
        else  printf("Equal\n");
    }
	return 0;
}
