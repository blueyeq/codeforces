#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int r, c;
    while(scanf("%d%d",&r,&c)!=EOF){

    if(r % 2 == 0 && c != 1 || r == 2 && c == 1)
    {
        printf("0\n");
        for(int i = 1; i <= r; ++i)
            printf("%d 1\n",i);
        for(int k = 1; k <= r; ++k)
        {
            if(k & 1)
            {
                for(int j = 2; j <= c; ++j)
                    printf("%d %d\n",r-k+1,j);
            }
            else
            {
                for(int j = c; j >= 2; --j)
                   printf("%d %d\n",r-k+1,j);
            }
        }
        printf("1 1\n");
    }
    else if(c % 2 == 0 && r != 1 || c == 2 && r == 1)
    {
        printf("0\n");
        for(int j = 1; j <= c; ++j)
            printf("1 %d\n",j);
        for(int k = 1; k <= c; ++k)
        {
            if(k & 1)
            {
                for(int i = 2; i <= r; ++i)
                    printf("%d %d\n",i,c-k+1);
            }
            else
            {
                for(int i = r; i >= 2; --i)
                    printf("%d %d\n",i,c-k+1);
            }
        }
        printf("1 1\n");
    }
    else
    {
        printf("1\n%d %d 1 1\n",r,c);
        for(int i = 1, j, flag; i <= r; ++i)
        {
            if(i & 1)  flag = 1, j = 1;
            else flag = -1, j = c;

            for(int k = 1;k <= c; ++k,j += flag)
                printf("%d %d\n",i,j);
        }
        printf("1 1\n");
    }
    }
    return 0;
}
