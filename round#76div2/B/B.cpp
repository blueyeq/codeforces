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

int g[10][10];

int main()
{
    int m;
    while(scanf("%d",&m) != EOF)
    {
        memset(g, 0, sizeof(g));
        for(int i = 0, a, b; i < m; ++i)
        {
            scanf("%d%d",&a,&b);
            g[a][b] = g[b][a] = true;
        }
        bool flag(false);
        for(int i = 1; i <= 5; ++i)
        for(int j = 1; j <= 5; ++j)
        for(int k = 1; k <= 5; ++k)
        {
            if(i == j || i == k || j == k)  continue;
            if(g[i][j] && g[i][k] && g[j][k])   flag = true;
            if(!g[i][j] && !g[i][k] && !g[j][k])   flag = true;
        }
        if(flag)    printf("WIN\n");
        else  printf("FAIL\n");
    }



	return 0;
}
