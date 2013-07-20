#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

LL pa[2], pb[2], pc[2];
LL turn[4][2];
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool able(LL x1, LL y1, LL x2, LL y2, LL dx, LL dy)
{
    LL t1 = dx * y2 - dy * x2;
    LL t2 = x1 * y2 - y1 * x2;
    if(x1 * y2 == y1 * x2)
    {
        LL g = gcd(x1, x2);
        if(g == 0)  return dx == 0;
        else return dx % g == 0;
    }
    bool fg1(0), fg2(0);
    if(t2 == 0)  fg1 = t1 == 0;
    else fg1 = (t1 % t2 == 0 && t1 / t2 >= 0);

    LL t3 = dx * y1 - dy * x1;
    LL t4 = x2 * y1 - y2 * x1;
    if(t4 == 0)  fg2 = t3 == 0;
    else fg2 = (t3 % t4 == 0 && t3 / t4 >= 0);

    return fg1 && fg2;
}

int main()
{
//    freopen("in", "r", stdin);
    while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &pa[0], &pa[1], &pb[0], &pb[1], &pc[0], &pc[1]) != EOF)
    {
        LL dy = pb[1] - pa[1];
        LL dx = pb[0] - pa[0];
        turn[0][0] = pc[0];
        turn[0][1] = pc[1];
        for(int i = 1; i < 4; ++i)
        {
            turn[i][0] = turn[i - 1][1];
            turn[i][1] = turn[i - 1][0] * -1;
        }
        bool fg(0);
        for(int i = 0; i < 4 && !fg; ++i)
        for(int j = i; j < 4 && !fg; ++j)
        {
            if(able(turn[i][0], turn[i][1], turn[j][0], turn[j][1], dx, dy))
            {
                fg = 1;
            }
        }
        if(fg)  puts("YES");
        else puts("NO");
    }

    return 0;
}
