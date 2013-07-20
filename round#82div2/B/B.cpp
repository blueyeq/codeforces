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

bool flag[300];
struct Node
{
    int spd, ram, hd, pric;
}node[300];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &node[i].spd, &node[i].ram, &node[i].hd, &node[i].pric);
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(node[i].ram > node[j].ram
            && node[i].spd > node[j].spd
            && node[i].hd  > node[j].hd)
                flag[j] = 1;
        }
        int ans(1000000000), ans_i;
        for(int i = 0; i < n; ++i)
        {
            if(!flag[i] && ans > node[i].pric)
            {
                ans = node[i].pric;
                ans_i = i;
            }
        }
        printf("%d\n", ans_i + 1);
    }



	return 0;
}
