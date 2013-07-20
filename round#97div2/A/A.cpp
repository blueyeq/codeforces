#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int f[1000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            int ta;
            scanf("%d", &ta);
            f[ta] = i;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == n) printf("%d\n", f[i]);
            else  printf("%d ",f[i]);
        }
    }

    return 0;
}
