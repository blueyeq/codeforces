#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int a[1010], d;
int ABS(int a, int b)
{
    if(a >= b) return a -b;
    return b - a;
}
int main()
{
    int n;
    while(scanf("%d%d",&n,&d) != EOF)
    {
        for(int i = 0; i != n; ++i)
        {
            cin>>a[i];
        }
        int ans(0);
        for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
        {
            if(ABS(a[i],a[j]) <= d)  ++ans;
        }
        cout<<2 * ans<<endl;
    }

    return 0;
}
