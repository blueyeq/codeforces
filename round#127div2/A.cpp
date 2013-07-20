#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
char str[15], ans[15], tmp[15];

int main()
{
    while(scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        int lans(0);
        ans[0] = 0;
        for(int i = 1; i < (1<<len); ++i)
        {
            int cnt(0);
            for(int j = 0; j < len; ++j)
            {
                if(i & (1<<j))  tmp[cnt++] = str[j];
            }
            tmp[cnt] = 0;
            int lt(0), rt(cnt - 1);
            while(lt < rt)
            {
                if(tmp[lt] != tmp[rt])  break;
                ++lt; --rt;
            }
//            printf("%s  %d %d\n", tmp, lt, rt);
            if(lt >= rt && strcmp(ans, tmp) == -1)
            {
                lans = cnt;
                memcpy(ans, tmp, 10);
            }

        }
        printf("%s\n", ans);
    }


    return 0;
}

