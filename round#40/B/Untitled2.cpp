#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    int n, a, k;
    int Max, Min, Min_n;
    Min = 5000, Max = -1;
    scanf("%d%d",&n,&k);
    int ans(k), tmp;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&a);
        if(Min > a)     Min = Max = a;
        else if(a > Max)    //  当且仅当遇到比之前价格低的时候才更新 ans
        {
            Max = a;
            Min_n = k / Min;
            tmp = Min_n * Max + k - Min * Min_n;
            if(tmp > ans)   ans = tmp;
        }
    }
    printf("%d\n",ans);
}
