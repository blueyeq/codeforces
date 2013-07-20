/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int f[4000005];

int find(int x)
{
    if(f[x] == x)   return x;
    return f[x] = find(f[x]);
}
int main()
{
    int n, m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        if(n > m)   swap(n,m);
        int k = 2*(n+m) - 4;

        for(int i = 1; i <= k+1; ++i)
            f[i] = i;
        for(int i = 1; i <= m; ++i)
        {
            int f1 = find(i);
            int f2 = find(m+i-1);
            if(i != 1)  f[f2] = f1;
            if(i == m)  break;
            f2 = find(k-(m-1-i));
            f[f2] = f1;
           // printf("%d  %d   %d>>\n",i,m+i-1,k-(m-1-i));
        }
        for(int i = n+m-1; i <= n+m+m-2; ++i)
        {
            int f1 = find(i);
            int t(2*(n+m-1)-i);
            if(t <= m) t = 1 + m - t;
            int tt1 = t;
            f[find(t)] = f1;
            t = 2*(2*m+n-2)-i;
           // cout<<"ttt: "<<t<<endl;
            if(t > k)   t = m - (t-k-1);
            f[find(t)] = f1;
           // printf("%d  %d   %d<<<\n",i,tt1,t);
        }
        int ans(0);
        for(int i = 1; i <= k; ++i)
            if(f[i] == i)   ++ans;
        printf("%d\n",ans);
    }
	return 0;
}
