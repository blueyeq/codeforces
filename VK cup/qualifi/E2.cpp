#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;
const int MAXN = 200010;

struct Node
{
    int id, len, color;
    bool operator < (const Node &other)  const
    {
        if(color != other.color)   return color < other.color;
        return len > other.len;
    }
}node[MAXN];

LL Max1[MAXN], Max2[MAXN];
int src1[MAXN], src2[MAXN];
int ele1, ele2, cnt1, cnt2;
inline bool ok(int x)
{
    return x != 0;
}
int main()
{
//    freopen("std.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d",&node[i].color, &node[i].len);
            node[i].id = i;
        }

        sort(node + 1, node + n + 1);

        int cnt(0);
        LL sum(0);
        memset(src1, 0, sizeof(src1));
        memset(src2, 0, sizeof(src2));
        memset(Max1, 0, sizeof(Max1));
        memset(Max2, 0, sizeof(Max2));

        for(int i = 1; i <= n; ++i)
        {
//            printf("%d   %d\n", node[i].color, node[i].len);

            if(i != 1 && node[i].color != node[i - 1].color)
            {
                sum = node[i].len;
                cnt = 1;
            }
            else
            {
                sum += node[i].len;
                ++cnt;
            }
            if(sum > Max1[cnt] || sum == Max1[cnt] && src1[cnt] == src2[cnt])
            {
                src2[cnt] =  src1[cnt];
                Max2[cnt] = Max1[cnt];
                Max1[cnt] = sum;
                src1[cnt] = node[i].color;
            }
            else if(sum > Max2[cnt] || sum == Max2[cnt] && src1[cnt] == src2[cnt])
            {
                src2[cnt] = node[i].color;
                Max2[cnt] = sum;
            }
        }
        LL ans(0);
        for(int i = 1; i <= n; ++i)
        {
            if(ans < Max1[i] + Max2[i] && src1[i] != src2[i] && ok(src1[i]) && ok(src2[i]))
            {
                ans = Max1[i] + Max2[i];
                ele1 = src1[i];
                ele2 = src2[i];
                cnt1 = cnt2 = i;
            }
            if(ans < Max1[i] + Max1[i - 1] && src1[i] != src1[i - 1] && ok(src1[i]) && ok(src1[i - 1]))
            {
                ans = Max1[i] + Max1[i - 1];
                ele1 = src1[i];
                ele2 = src1[i - 1];
                cnt1 = i;
                cnt2 = i - 1;
            }
            if(ans < Max1[i] + Max2[i - 1] && src1[i] != src2[i - 1] && ok(src1[i]) && ok(src2[i - 1]))
            {
                ans = Max1[i] + Max2[i - 1];
                ele1 = src1[i];
                ele2 = src2[i - 1];
                cnt1 = i;
                cnt2 = i - 1;
            }
            if(ans < Max2[i] + Max1[i - 1] && src2[i] != src1[i - 1] && ok(src2[i]) && ok(src1[i - 1]))
            {
                ans = Max2[i] + Max2[i - 1];
                ele1 = src2[i];
                ele2 = src1[i - 1];
                cnt1 = i;
                cnt2 = i - 1;
            }
            if(ans < Max2[i] + Max2[i - 1] && src2[i] != src2[i - 1] && ok(src2[i]) && ok(src2[i - 1]))
            {
                ans = Max2[i] + Max2[i - 1];
                ele1 = src2[i];
                ele2 = src2[i - 1];
                cnt1 = i;
                cnt2 = i - 1;
            }
        }
        printf("%I64d\n%d\n", ans, cnt1 + cnt2);
        int ptr1(-1),  ptr2(-1);
        for(int i = 1; i <= n; ++i)
        {
            if(node[i].color == ele1 && ptr1 == -1)  ptr1 = i;
            if(node[i].color == ele2 && ptr2 == -1)  ptr2 = i;
        }

        if(cnt1 < cnt2)
        {
            swap(cnt1, cnt2);
            swap(ele1, ele2);
        }
        if(cnt1 > cnt2)  printf("%d", node[ptr1++].id);

        bool fg = cnt1 > cnt2;
        cnt1 = cnt2 = min(cnt1, cnt2);
        for(int i = 1; i <= cnt1; ++i)
        {
            if(fg)
            {
                printf(" %d", node[ptr2++].id);
                printf(" %d", node[ptr1++].id);
            }
            else
            {
                if(i == 1) printf("%d", node[ptr1++].id);
                else  printf(" %d", node[ptr1++].id);
                printf(" %d", node[ptr2++].id);
            }
        }
        puts("");


    }


    return 0;
}
