/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 3000000

using namespace std;

typedef long long LL;

char s1[MAXN], s2[MAXN];
bool vis[26];
int main()
{
    while(scanf("%s%s",s1,s2) != EOF)
    {
        int n1(strlen(s1)), n2(strlen(s2));
        bool flag(true);
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n1; ++i)
            vis[s1[i]-'a'] = true;
        for(int i = 0; i < n2; ++i)
            if(!vis[s2[i]-'a']) flag = false;
        int ans(1);
        for(int i = 0, j = 0; i < n2 && flag; ++i)
        {
            if(j == n1)
            {
                ++ans;
                j = 0;
            }
            while(s2[i] != s1[j])
            {
                ++j;
                if(j == n1)
                {
                    ++ans;
                    j = 0;
                }
            }
            ++j;
        }
        if(!flag)   printf("-1\n");
        else printf("%d\n",ans);
    }
	return 0;
}
