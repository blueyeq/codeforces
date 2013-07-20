#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    bool flag = false;
    for(int i = 0; i * i/2 <= n; ++i)
    {
        if(i * (i+1) / 2 == n)  {flag = true; break;}
        //printf("%d\n",i*(i+1));
    }
    if(flag)  printf("YES\n");
    else   printf("NO\n");

}
