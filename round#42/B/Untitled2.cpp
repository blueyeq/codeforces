#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char str1[1010], str2[1010];
int org[55];

int main()
{
    bool flag(true);
    memset(org,0,sizeof(org));

    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    //cout<<str1<<endl;
    for(int i = 0; i < len1; ++i)
    {
        if(str1[i] >= 'a' && str1[i] <= 'z')
           ++org[str1[i]-'a'];
        else if(str1[i] >= 'A' && str1[i] <= 'Z')
           ++org[str1[i]-'A'+26];  // +26
    }
    //cout<<str2<<endl;
    int len2 = strlen(str2), tmp;
    for(int i = 0; i < len2; ++i)
    {
        tmp = -1;
        if(str2[i] >= 'a' && str2[i] <= 'z')
           tmp = str2[i] - 'a';
        else if(str2[i] >= 'A' && str2[i] <= 'Z')
           tmp = str2[i] - 'A' + 26;

        if(tmp != -1)
        {
            --org[tmp];
            //if(i == 0)   cout<<tmp<<"  "<<org[tmp]<<"   "<<str2[i]<<endl;
            if(org[tmp] < 0)
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)    printf("YES\n");
    else    printf("NO\n");


    return 0;
}
