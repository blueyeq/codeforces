#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

bool dele[MAXN];
int prim[30000], cntPri;

void init()
{
    memset(dele, 0, sizeof(dele));
    cntPri = 0;
    for(int i = 2; i < MAXN; ++i)
    {
        if(!dele[i])  prim[cntPri++] = i;
        for(int j = 0; j < cntPri && prim[j] * i < MAXN; ++j)
        {
            dele[prim[j] * i] = 1;
            if(i % prim[j] == 0)   break;
        }
    }
}
char s[10];
int mp[6][6];
int dp[5][10][10][10][10][10][10];
int digit[6];
int fact[6] = {1, 10, 100, 1000, 10000, 100000};

int dfs(int x, int n)
{
    if(x == n)  return 1;
    int cnt(0);
    memset(digit, 0, sizeof(digit));
    for(int i = x; i < n; ++i)
    for(int j = 0; j < x; ++j)
        digit[cnt++] = mp[i][j];
    int &ret = dp[x][digit[0]][digit[1]][digit[2]][digit[3]][digit[4]][digit[5]];

    if(ret != -1)  return ret;
    ret = 0;
    int pre(0);
    for(int j = 0; j < x; ++j)
        pre = pre * 10 + mp[x][j];
    int indexLeft = upper_bound(prim, prim + cntPri, pre * fact[n - x]) - prim;
    int indexRight = lower_bound(prim, prim + cntPri, (pre + 1) * fact[n - x]) - prim;

    for(int k = indexLeft; k < indexRight; ++k)
    {
        int tmp = prim[k];

        sprintf(s, "%d", tmp);
        int len(strlen(s));
        int j = n - 1;
        for(int i = len - 1; i >= 0; --i, --j)
            mp[x][j] = mp[j][x] = s[i] - '0';
        for(; j >= x; --j)
            mp[x][j] = mp[j][x] = 0;
        ret += dfs(x + 1, n);
    }
    return ret;
}

int main()
{
//    freopen("std.in", "r", stdin);
    init();
    int test;
    scanf("%d", &test);

    while(test--)
    {
        int n;
        scanf("%d", &n);
        sprintf(s, "%d", n);
        n = strlen(s);
        for(int i = 0; i < n; ++i)
            mp[0][i] = mp[i][0] = s[i] - '0';
        memset(dp, -1, sizeof(dp));
        printf("%d\n",dfs(1, n));
    }

    return 0;
}
