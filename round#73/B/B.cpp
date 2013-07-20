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

int n, m, d, q;
int pos[50][900][2], num[50];
bool recite[30];
char s[50];

int sqr(int r1, int c1, int r2, int c2)
{
    return (r1-r2) * (r1-r2) + (c1-c2) * (c1-c2);
}
bool ok(int x)
{
    for(int i = 0; i < num[x]; ++i)
    for(int j = 0; j < num[30]; ++j)
    {
        int  t = sqr(pos[x][i][0], pos[x][i][1], pos[30][j][0], pos[30][j][1]);
        if(t <= d)  return true;
    }
    return false;
}

int main()
{

    scanf("%d%d%d",&n,&m,&d);
    memset(num,0,sizeof(num));
    d = d * d;
    for(int i = 0; i < n; ++i)
    {
        scanf("%s",s);
        for(int j = 0; j < m; ++j)
        {
            if(s[j] == 'S')
            {
                pos[30][num[30]][0] = i;
                pos[30][num[30]][1] = j;
                ++num[30];
            }
            else
            {
                int t = s[j] - 'a';
                pos[t][num[t]][0] = i;
                pos[t][num[t]][1] = j;
                ++num[t];
            }
        }
    }
    scanf("%d",&q);
    getchar();
    char c;
    bool flag(true);
    int ans(0), t;
    memset(recite, 0, sizeof(recite));

    for(int i = 0; i < 26; ++i)
        if(ok(i))   recite[i] = true;

    for(int i = 0; i < q; ++i)
    {
        c = getchar();
        if(c >= 'a' && c <= 'z')    t = c - 'a';
        else t = c - 'A';
        if(num[t] == 0)   flag = false;
        if(c >= 'a' && c <= 'z')    continue;
        else  if(!num[30])  flag = false;
        if(!recite[t])  ++ans;
    }
    if(!flag)    printf("-1\n");
    else   printf("%d\n",ans);
	return 0;
}
