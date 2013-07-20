#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

struct Node
{
    int id, len;
    bool operator < (const Node &other)  const
    {
        if(len != other.len)  return len < other.len;
        return id < other.id;
    }
}soldier[MAXN], vest[MAXN];

int ans[MAXN][2];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m, x, y;
    while(scanf("%d%d%d%d", &n, &m, &x, &y) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &soldier[i].len);
            soldier[i].id = i;
        }
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", &vest[i].len);
            vest[i].id = i;
        }
        sort(soldier, soldier + n);
        sort(vest, vest + m);
        int ptr1(0),  ptr2(0);
        int cnt(0);
        for(; ptr1 < m && ptr2 < n;)
        {
            if(vest[ptr1].len >= soldier[ptr2].len - x && vest[ptr1].len <= soldier[ptr2].len + y)
            {
                ans[cnt][0] = soldier[ptr2++].id + 1;
                ans[cnt++][1] = vest[ptr1++].id + 1;
            }
            else  if(vest[ptr1].len > soldier[ptr2].len + y) ++ptr2;
            else  ++ptr1;
        }
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; ++i)
            printf("%d %d\n", ans[i][0], ans[i][1]);
    }


    return 0;
}
