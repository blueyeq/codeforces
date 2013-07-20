#include <isotream>
#incldue <stdio.h>
#include <cstring>

using namespace std;

int a[1010], d;
int main()
{
    int n;
    while(scanf("%d%d",&n,&d) != EOF)
    {
        for(int i = 0; i != n; ++i)
        {
            scanf("%d",&a[i]);
        }
        int ans(0);
        for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
        {
            if((a[i] + d <= a[j]) ||(a[j] + d <= a[i])) ++ans;
        }
        cout<<ans<<endl;
    }

    return 0;
}
