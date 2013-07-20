#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;
const int MAXN = 710;
const LL mod = 1000000007LL;

char blacket[MAXN];
int pir[MAXN], st[MAXN], dp[MAXN][MAXN][4][4];

void init(int n )
{
    memset(pir, -1, sizeof(pir));
    int ptr = -1;
    for(int i = 0; i < n; ++i)
    {
        if(blacket[i] == ')')
            pir[st[ptr--]] = i;
        else  st[++ptr] = i;
    }
}
int dfs(int lt, int rt, int sl, int sr)
{
    if(lt >= rt)  return 1;
    if(dp[lt][rt][sl][sr] != -1)  return dp[lt][rt][sl][sr];
    LL ret = 0;
    if((sr & 1) != 1 || pir[lt] + 1 < rt)
        ret = (LL)(ret + (LL)dfs(lt + 1, pir[lt] - 1, 0, 1) * dfs(pir[lt] + 1, rt, 1, sr) % mod) % mod;
    if((sr & 2) != 2 || pir[lt] + 1 < rt)
        ret = (LL)(ret + (LL)dfs(lt + 1, pir[lt] - 1, 0, 2) * dfs(pir[lt] + 1, rt, 2, sr) % mod) % mod;
    if((sl & 1) != 1)
        ret = (LL)(ret + (LL)dfs(lt + 1, pir[lt] - 1, 1, 0) * dfs(pir[lt] + 1, rt, 0, sr) % mod) % mod;
    if((sl & 2) != 2)
        ret = (LL)(ret + (LL)dfs(lt + 1, pir[lt] - 1, 2, 0) * dfs(pir[lt] + 1, rt, 0, sr) % mod) % mod;
    dp[lt][rt][sl][sr] = (int)ret;
    return (int) ret;
}
int main()
{
//    freopen("in", "r", stdin);
    while(scanf("%s", blacket) != EOF)
    {
        int n = strlen(blacket);
        init(n);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, n - 1, 0, 0));
    }
    return 0;
}
