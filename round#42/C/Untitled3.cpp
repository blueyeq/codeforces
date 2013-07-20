#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int n, a;
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&a);
        ++cnt[a%3];
    }
    int ans = cnt[0]/2 + min(cnt[1],cnt[2]);
    printf("%d\n",ans);
    return 0;
}
