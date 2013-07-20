/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 5000000

using namespace std;

typedef long long LL;

char s[MAXN];

int main()
{
    while(scanf("%s",s) != EOF)
    {
        int len(strlen(s));

        reverse(s, s+len);
        int ans(len);
        int one(0);
        int i(0);
        while(s[i] == '0' && i < len)  ++i;
        bool flag(false);
        if(i == len - 1)
        {
            --ans;
            flag = true;
        }
        for(; i < len && !flag; ++i)
        {
            if(s[i] == '1') ++one;
            while(s[i] == '1' && i < len)
               ++i;
            //printf("i----> %d\n",i);
            ++ans;
        }
        printf("%d\n",ans);

    }
// 1111


	return 0;
}
