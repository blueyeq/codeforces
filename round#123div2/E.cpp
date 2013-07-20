#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

const LL mod = 1000000007;
const int MAXN = 1000010;


int fa[MAXN];
LL dis[MAXN];

void up(LL &a, LL b)
{
    a += b;
    if( a >= mod) a -= mod;
    if(a < 0)  a = (a % mod + mod) % mod;
}
int find(int x)
{
    if(fa[x] == x)  return x;
    LL tmp = dis[x];
    int tf = fa[x];
    fa[x] = find(tf);
    dis[x] = (tmp + dis[tf]) % mod;
    return fa[x];
}



int main()
{
//    freopen("E.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {

        LL sum(0);
        for(int i = 1, l; i <= n; ++i)
        {
            dis[i] = 0;
            fa[i] = i;
            scanf("%d", &l);
            int v, x;
            for(int j = 0; j < l; ++j)
            {
                scanf("%d%d", &v, &x);
                int f = find(v);
                while(f == i);   //multi edge

                LL tmp = (mod + (dis[v] + x) % mod) % mod;
                fa[f] = i;
                dis[f] = tmp;
                up(sum, tmp);
            }
        }
        printf("%I64d\n", sum);
    }
    return 0;
}

