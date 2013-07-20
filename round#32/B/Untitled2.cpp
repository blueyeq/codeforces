#include <iostream>
#include <cstring>
#include <stdio.h>

int main()
{

    char str[300];
    int num[300];
    while(scanf("%s",str) != EOF)
    {
        int n(0);
        int len = strlen(str);
        for(int i = 0; i < len; )
        {
            if(str[i] == '.')
            {
                ++i;
                num[n++] = 0;
            }
            else if(str[i] == '-' && str[i+1] == '.')
            {
                num[n++] = 1;
                i += 2;
            }
            else if(str[i] == '-' && str[i+1] == '-')
            {
                num[n++] = 2;
                i += 2;
            }
        }
        for(int i = 0; i < n; ++i)
            printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}
