#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1010];
int num[1010];

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    sort(a,a+n);
    num[0] = 1;

    int  k(0);
    for(int i = 1; i < n; ++i)
    {
        if(a[i] != a[i-1])  ++k;
        ++num[k];
    }

    int Max = num[0];
    for(int i = 0; i <= k; ++i)
    {
        if(Max < num[i]) Max = num[i];
    }
    printf("%d %d\n",Max,k+1);

    return 0;
}
