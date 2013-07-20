#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

char ch[110];
int bit[10];

int main()
{
//    freopen("in", "r", stdin);
    while(gets(ch))
    {
       // printf("%s\n", ch);
        int len(strlen(ch));

        int pre = 0;
        for(int i = 0; i < len; ++i)
        {
            int t = ch[i];
            for(int j = 0; j < 8; ++j, t /= 2)
                bit[j] = t & 1;
            int now(0);
            for(int j = 0; j < 8; ++j)
                now += bit[j] * (1 << (7 - j));

            printf("%d\n", (pre - now + 256) % 256);
            pre = now;
        }
    }



    return 0;
}

