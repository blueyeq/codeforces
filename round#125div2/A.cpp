
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int INF = 1000000000;
int cnt;
int a[1000];

bool dfs(int n, int dep, int b[])
{
    if(dep == 3)
    {
        printf("%d %d %d\n", b[0], b[1], b[2]);
        if(n == 0)  return 1;
        else  return 0;
    }
    int id = lower_bound(a, a + cnt, n) - a;
    for(; id >= 0; --id)
    {
        b[dep] = a[id];
        if(dfs(n - a[id], dep + 1, b))  return 1;
    }
    return 0;
}

int main()
{
//    freopen("A.in", "r", stdin);
    int n;
    a[0] = 0;
    a[1] = 1;
    while(scanf("%d", &n) != EOF)
    {
        cnt = 2;
        while(1)
        {
            a[cnt] = a[cnt - 1] + a[cnt -2];
            if(a[cnt] >= INF)  break;
            cnt++;
        }
        int b[4];
        if(!dfs(n, 0, b))  puts("I'm too stupid to solve this problem");


    }



    return 0;
}
