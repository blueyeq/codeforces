#include <stdio.h>

int main()
{
    int n, num[110];

    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0, j = 1, d = 2; i < n-1; ++i, ++d)
        {
            num[i] = j;
            j = (j+d) % n;
        }
        for(int i = 0; i < n-1; ++i)
        {
            if(i == n-2)    printf("%d\n",num[i]+1);
            else   printf("%d ",num[i]+1);
        }
    }
    return 0;
}
