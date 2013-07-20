#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
const int inf = 0x3f3f3f;
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= 2*n ; j++)
            {
                if(j >= n-i && j <= n)
                {
                    printf("%d",i+j-n);
                    continue;
                }
                if(j >= n && j <= n+i)
                {
                    printf("%d",n+i-j);
                    continue;
                }
                printf(" ");
            }
            printf("\n");
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j <= 2*n ; j++)
            {
                if(j >= i+1 && j <= n)
                {
                    printf("%d",j-i-1);
                    continue;
                }
                if(j >= n && j <= 2*n-1-i)
                {
                    printf("%d",2*n-1-i-j);
                    continue;
                }
                printf(" ");
            }
            printf("\n");
        }
    }
}
