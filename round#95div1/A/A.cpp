#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

char ch[200];

int main()
{
    //freopen("in", "r", stdin);
    while(scanf("%s", ch) != EOF)
    {
        int len = strlen(ch);

        int Max(0), Min(0);
        for(int i = 0; i < len; ++i)
        {
            if(ch[i] >= 'a' && ch[i] <= 'z')  Min++;
            else  Max++;
        }

        if(Min == 0 || (ch[0] >= 'a' && ch[0] <= 'z' && Max == len - 1))
        {
            for(int i = 0; i < len; ++i)
            {
                if(ch[i] >= 'A' && ch[i] <= 'Z')   ch[i] = ch[i] - 'A' + 'a';
                else  ch[i] = ch[i] - 'a' + 'A';
            }
        }
        printf("%s\n", ch);

    }


    return 0;
}
