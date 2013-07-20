/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 0

using namespace std;

typedef long long LL;

char s[1000];

int main()
{
    while(scanf("%s",s) != EOF)
    {
        int len = strlen(s);
        int one(0), zero(0);
        bool flag(false);
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '1')
            {
                ++one;
                zero = 0;
            }
            else
            {
                ++zero;
                one = 0;
            }
            if(zero >= 7 || one >= 7)   flag = true;
        }
        if(flag)    printf("YES\n");
        else  printf("NO\n");
    }



	return 0;
}
