#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    char str1[110], str2[110];
    scanf("%s%s",str1,str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    bool flag(true);
    if(len1 != len2) flag = false;
    for(int i = 0; i < len1 && flag; ++i)
        if(str1[i] != str2[len1-1-i])  flag = false;
    if(flag)  printf("YES\n");
    else    printf("NO\n");
    return 0;
}
