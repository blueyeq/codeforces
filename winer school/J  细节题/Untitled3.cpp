#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char str1[1000100], str2[1000010];

int main()
{

    scanf("%s%s",str1,str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2 + 1)
    {
        printf("0\n");
        return 0;
    }

    bool flag(true);
    int now(0), pos(len1-1);
    for(int i = 0,j = 0; i < len1 && j < len2;)
    {
        if(str1[i] == str2[j])
        {
            ++i;
            ++j;
        }
        else if(now == 0)
        {
            pos = i;
            ++i;
            //while(i < len1 && str1[i] == str1[i-1]) ++i;
            now = 1;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {

        now = 1;
        for(int i = pos+1; i < len1; ++i)
        {
            if(str1[i] != str1[i-1]) break;
            ++now;
        }
        for(int i = pos-1; i >= 0; --i)
        {
            if(str1[i] != str1[i+1]) break;
            pos = i;
            ++now;
        }
        printf("%d\n",now);
        for(int i = 0; i < now ; ++i)
        {
            if(i == 0) printf("%d",pos+1);
            else printf(" %d",pos+i+1);
        }
        printf("\n");
    }
    else printf("0\n");

    return 0;


}

