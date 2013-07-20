/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define M 100000

using namespace std;
int  num, prime[50000], a[100005];
bool flag[100005];

void get_prime()
{
    memset(flag,false,sizeof(flag));
    num=0;
    for(int i=2;i<M;i++){
       if(!flag[i])
       prime[num++]=i;
        for(int j=0;j<num&&i*prime[j]<M;j++){
        flag[i*prime[j]]=true;
             if(i%prime[j]==0)
                 break;
         }
     }
}
int main()
{
    int n;
    get_prime();
    while(scanf("%d",&n) != EOF)
    {
        int sum(0);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        if(sum == n)    printf("YES\n");
        else
        {
            bool suc(false);
            for(int i = 2; n / i >= 3; ++i)
            {
                if(n % i)   continue;
                for(int j = 1; j <= i; ++j)
                {
                    int cnt(0);
                    for(int k = j; k <= n; k += i)
                    {
                        if(!a[k])   break;
                        ++cnt;
                    }
                    if(cnt == n/i)
                    {
                        suc = true;
                        break;
                    }
                }
                if(suc) break;
            }
            if(suc)   printf("YES\n");
            else  printf("NO\n");
        }
    }
	return 0;
}
