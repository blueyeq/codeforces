/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 5010

using namespace std;

typedef long long LL;

char s[MAXN], map[MAXN];

int n, m, Max, tmp;
int U[MAXN], D[MAXN], L[MAXN], R[MAXN];

int id(int i, int j)
{
    return (i-1) * m + j - 1;
}

void init()
{
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
    {
        L[id(i, j)] = L[id(i, j-1)];
        U[id(i, j)] = U[id(i-1, j)];
        if(i == 1)  L[id(i, j)] = 0;
        if(j == 1)  U[id(i, j)] = 0;
        if(j != 1 && map[id(i, j-1)] != '.')  L[id(i, j)] = j - 1;
        if(i != 1 && map[id(i-1, j)] != '.')  U[id(i, j)] = i - 1;
    }
    for(int i = n; i >= 1; --i)
    for(int j = m; j >= 1; --j)
    {
        R[id(i, j)] = R[id(i, j+1)];
        D[id(i, j)] = D[id(i+1, j)];
        if(j == m)  R[id(i, j)] = m + 1;
        if(i == n)  D[id(i, j)] = n + 1;
        if(j != m && map[id(i, j+1)] != '.')  R[id(i, j)] = j + 1;
        if(i != n && map[id(i+1, j)] != '.')  D[id(i, j)] = i + 1;
    }
}
bool ok(int r, int c)
{
    if(r < 1 || r > n || c < 1 || c > m || map[id(r, c)] == '.')    return false;
    return true;
}
void dfs(int r, int c, int step)
{
    if(!ok(r, c))
    {
        tmp = max(tmp, step);
        return;
    }
    char cc = map[id(r, c)];
    map[id(r, c)] = '.';
    int t, tr, tc;
    if(cc == 'U')
    {
        for(tr = r; tr >= 1 && map[id(tr, c)] == '.'; tr = U[id(tr, c)]){;}

        t = U[id(r, c)];
        U[id(r, c)] = U[id(tr, c)];
        dfs(tr, c, step + 1);
        U[id(r, c)] = t;
    }
    if(cc == 'D')
    {
        for(tr = r; tr <= n && map[id(tr, c)] == '.'; tr = D[id(tr, c)]){;}

        t = D[id(r, c)];
        D[id(r, c)] = D[id(tr, c)];
        dfs(tr, c, step + 1);
        D[id(r, c)] = t;
    }
    if(cc == 'R')
    {
        for(tc = c; tc <= m && map[id(r, tc)] == '.'; tc = R[id(r, tc)]){;}

        t = R[id(r, c)];
        R[id(r, c)] = R[id(r, tc)];
        dfs(r, tc, step + 1);
        R[id(r, c)] = t;
    }
    if(cc == 'L')
    {
        for(tc = c; tc >= 1 && map[id(r, tc)] == '.'; tc = L[id(r, tc)]){;}

        t = L[id(r, c)];
        L[id(r, c)] = L[id(r, tc)];
        dfs(r, tc, step + 1);
        L[id(r, c)] = t;
    }
    map[id(r, c)] = cc;

}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%s",s);
            for(int j = 1; j <= m; ++j)
                map[id(i,j)] = s[j-1];
        }
        Max = 0;
        int cnt(0);
        init();
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(map[id(i, j)] == '.')    continue;
            tmp = 0;
            dfs(i, j, 0);
            if(tmp > Max)
            {
                Max = tmp;
                cnt = 1;
            }
            else if(tmp == Max)  ++cnt;
        }
        printf("%d %d\n",Max, cnt);
    }
	return 0;
}
