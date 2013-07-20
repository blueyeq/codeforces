#include <stdio.h>
#include <cstring>

using namespace std;
int num[6][3] = {{1,2,3},
               {1,3,2},
               {2,3,1},
               {2,1,3},
               {3,1,2},
               {3,2,1}};
int get(char c)
{
    if(c == 'A')  return 0;
    if(c == 'B')  return 1;
    return 2;
}
int main()
{
    int k;
    char str[3][110];
    bool flag = false;
    for(int i = 0; i < 3; ++i)
    {
        scanf("%s",str[i]);
    }
    for(int i = 0, j; i < 6; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            int a = get(str[j][0]);
            int b = get(str[j][2]);
            if( num[i][a] > num[i][b] && str[j][1] == '<')
            {
                j = 10;
                break;
            }
            if(num[i][a] < num[i][b] && str[j][1] == '>')
            {
                j = 10;
                break;
            }
        }
        if(j != 10)
        {
            flag = true;
            k = i;
            break;
        }
    }
    if(flag)
    {
        for(int i = 0; i < 3; ++i)
        {
            int Min = 1000, Min_i;
            for(int j = 0; j < 3; ++j)
            {
                if(num[k][j] < Min)
                {
                    Min = num[k][j];
                    Min_i = j;
                }
            }
            num[k][Min_i] = 100;
            if(Min_i == 0)   printf("A");
            else if(Min_i == 1)   printf("B");
            else printf("C");
        }
        printf("\n");
    }
    else printf("Impossible");


    return 0;
}
