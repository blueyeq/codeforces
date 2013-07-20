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

char s[50], ans[50];

bool dfs(int k, int four, int seven, int mid, int big)
{
    if(k == 2*mid)
    {
        ans[k] = 0;
        return true;
    }
    if(four < mid)
    {
        ans[k] = '4';
        if(big || ans[k] >= s[k])
        {
            if(dfs(k+1, four+1, mid, seven, big|(ans[k] > s[k])))   return true;
        }
    }
    ans[k] = '7';
    if(big || ans[k] >= s[k] && seven < mid)
    {
        if(dfs(k+1, four, mid, seven, big|(ans[k] > s[k])))    return true;
    }
    return false;

}
int main()
{
    while(scanf("%s",s) != EOF)
    {
        int len(strlen(s));
        if(len&1)
        {
            ++len;
            for(int i = 0; i < len; ++i)
            {
                if(i < len/2)   ans[i] = '4';
                else   ans[i] = '7';
            }
            ans[len] = 0;
        }
        else
        {
            if(!dfs(0,  0, 0, len/2, 0))
            {
                len += 2;
                for(int i = 0; i < len; ++i)
                {
                    if(i < len/2)   ans[i] = '4';
                    else  ans[i] = '7';
                }
            }
        }
        printf("%s\n",ans);
    }


	return 0;
}
