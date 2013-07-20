#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, m;
LL pp;
LL dp[55][55][110][2];

struct Node
{
    LL a, b;
    int  rank, id;
    bool operator < (const Node &aa) const
    {
        return rank < aa.rank;
    }
}node[55];
bool rng(LL c, LL a, LL b)
{
    return c >= a && c <= b;
}
void tomax(LL &a, LL b) {if(a < b) a = b;}
void myYY()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j <= node[i].b - node[i].a; ++j)
        {
            dp[i][1][j][0] = 1;
            dp[i][1][j][1] = node[i].a + j;
        }
    }
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(node[j].rank >= node[i].rank)  continue;

            for(int rk = 2; rk <= n; ++rk)
            for(int k1 = 0; k1 <= node[i].b - node[i].a; ++k1)
            {
                LL t1 = node[i].a + k1;

                if(rng(t1 - pp, node[j].a, node[j].b) && dp[j][rk - 1][t1 - pp - node[j].a][0])
                {
                    dp[i][rk][k1][0] = 1;
                  //  printf("1-->%d  %d  %d  %I64d\n",i, rk, j, node[i].a + k1);
                    tomax(dp[i][rk][k1][1], dp[j][rk - 1][t1 - pp - node[j].a][1] + t1);
                }
                if(t1 % pp == 0)
                {
                    LL g = t1 / pp;
                    if(rng(g, node[j].a, node[j].b) && dp[j][rk - 1][g - node[j].a][0] )
                    {

                      // printf("2-->%d  %d  %d %I64d %I64d\n",i, rk, j, g, node[i].a + k1);
                        dp[i][rk][k1][0] = 1;
                        tomax(dp[i][rk][k1][1], dp[j][rk - 1][g - node[j].a][1] + t1);
                    }
                }
            }
        }
    }
}

void print(int k, int rk, LL pre, LL sum)
{
    if(rk <= 0)  return;
    for(int i = 0; i <= k; ++i)
    {
        for(LL j = 0; j <= node[i].b - node[i].a; ++j)
        {
            if(!dp[i][rk][j][0])  continue;
            LL t1 = node[i].a + j + pp;
            LL t2 = (node[i].a + j) * pp;
            if((pre == t1 || pre == t2)&& dp[i][rk][j][1] + pre == sum )
            {
                print(i - 1, rk - 1, node[i].a + j, dp[i][rk][j][1]);
                printf("%d %I64d\n", node[i].id, node[i].a + j);
                return;
            }
        }
    }
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &pp) != EOF)
    {
        for(int i = 0; i < m; ++i)
        {
            scanf("%I64d%I64d%d", &node[i].a, &node[i].b, &node[i].rank);
            node[i].id = i + 1;
        }
        sort(node, node + m);

        myYY();
        bool fg(0);
        LL Max(0), pa3;
        int pa1, pa2;
        for(int i = 0; i < m ; ++i)
        for(int j = 0; j <= node[i].b - node[i].a; ++j)
        {
            if(dp[i][n][j][0])
            {
                fg = 1;
                if(Max < dp[i][n][j][1])
                {
                    Max = dp[i][n][j][1];
                    pa1 = i;  pa2 = n;
                    pa3 = node[i].a + j;
                }
            }
        }
        if(fg)
        {
            puts("YES");
            print(pa1 - 1, n - 1, pa3, Max);
            printf("%d %I64d\n", node[pa1].id, pa3);
        }
        if(!fg)  puts("NO");
    }
    return 0;
}
