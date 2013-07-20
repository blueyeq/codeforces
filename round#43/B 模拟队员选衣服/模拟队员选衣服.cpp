#include <stdio.h>
#include <cstring>

int main()
{
    int n, left[6], slect[1010];
    char str[10];
    while(scanf("%d%d%d%d%d",&left[1],&left[2],&left[3],&left[4],&left[5]) != EOF)
    {
        scanf("%d",&n);
        for(int i = 1, j, d; i <= n; ++i)
        {
            scanf("%s",str);
            if(strlen(str) == 3)  j = 5;
            else if(str[0] == 'S')  j = 1;
            else if(str[0] == 'M')  j = 2;
            else if(str[0] == 'L')  j = 3;
            else if(str[0] == 'X')  j = 4;
            for(d = 0;; ++d)
            {
                if(left[j+d] > 0 && j + d <= 5)
                {
                    --left[j+d];
                    slect[i] = j + d;
                    break;
                }
                else if(left[j-d] > 0 && j - d >= 1)
                {
                    --left[j-d];
                    slect[i] = j - d;
                    break;
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(slect[i] == 1)   printf("S\n");
            if(slect[i] == 2)   printf("M\n");
            if(slect[i] == 3)   printf("L\n");
            if(slect[i] == 4)   printf("XL\n");
            if(slect[i] == 5)   printf("XXL\n");
        }
    }



    return 0;
}
