#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == j && j != n-1) printf("0 ");
                else if(i == j)     printf("0\n");
                else if(j != n-1)   printf("1 ");
                else    printf("1\n");
            }
        }
    }



    return 0;
}
