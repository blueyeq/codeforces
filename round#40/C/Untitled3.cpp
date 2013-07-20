#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char str[110], ans[110];
int main()
{
    scanf("%s",str);
    int lstr = strlen(str);
    ans[0] = str[0];
    int lans(1);
    bool flag(false);
    for(int i = 1; i < lstr;)
    {
        if(str[i] < 'a' || str[i] > 'z')    continue;
        if(str[i] == 'd' && str[i+1] == 'o' && str[i+2] == 't' && i + 2 < lstr-1)
        {
            ans[lans++] = '.';
            i += 3;
        }
        else if(str[i] == 'a' && str[i+1] == 't' && i + 1 < lstr-1 && !flag)   //  题目中说只有一个@。。看题太粗心
        {
            flag = true;
            ans[lans++] = '@';
            i += 2;
        }
        else
        {
            ans[lans++] = str[i];
            ++i;
        }
    }
    for(int i = 0; i < lans; ++i)
        printf("%c",ans[i]);
    printf("\n");
    return 0;
}
