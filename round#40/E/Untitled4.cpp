#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a = n / 2, b = n - n / 2;
    printf("%d\n",a*b);
    for (int i = 1; i <= a; i++)
        for (int j = a + 1; j <= n; ++j)
            printf("%d %d\n",i,j);
}
