#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
bool vis1[MAXN], vis2[MAXN];
struct Node
{
    int id;
    double val;
    bool operator < (const Node &other)  const
    {
        return val < other.val;
    }
}stool[MAXN], pencil[MAXN];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        double sum(0);
        int cnt1(0), cnt2(0);
        for(int i = 0; i < n; ++i)
        {
            int ta;  double tb;
            scanf("%lf%d",&tb, &ta);
            sum += tb;
            if(ta == 1)
            {
                stool[cnt1].val = tb;
                stool[cnt1++].id = i + 1;
            }
            else
            {
                pencil[cnt2].val = tb;
                pencil[cnt2++].id = i + 1;
            }
        }
        sort(stool, stool + cnt1);
        sort(pencil, pencil + cnt2);

        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
//        for(int i = 0; i < cnt2; ++i)
//            printf("%d  %lf\n", pencil[i].id, pencil[i].val);

        if(cnt1 >= m)
        {
            for(int i = cnt1 - 1, j = m - 1; i >= 1, j >= 1; --i, --j)
                sum -= stool[i].val / 2.0;
            if(cnt2 < 1)  pencil[0].val = 1e20;
            sum -= min(pencil[0].val, stool[0].val) / 2.0;
            printf("%.1lf\n", sum);
            for(int i = 0, j = cnt1 - 1; i < m - 1 && j >= 0; ++i, --j)
            {
                printf("1 %d\n", stool[j].id);
                vis1[j] = 1;
            }
            printf("%d", n - m + 1);
            for(int i = 0; i < cnt1 || i < cnt2; ++i)
            {
                if(!vis1[i] && i < cnt1)
                    printf(" %d", stool[i].id);
                if(i < cnt2)
                    printf(" %d", pencil[i].id);
            }
            puts("");
        }
        else
        {
            for(int i = cnt1 - 1; i >= 0; --i)
                sum -= stool[i].val / 2.0;

            printf("%.1lf\n", sum);
            for(int i = 0; i < cnt1; ++i)
                printf("1 %d\n", stool[i].id);

            int j(0);
            for(int i = cnt1; i < m - 1; ++i, ++j)
                printf("1 %d\n", pencil[j].id);

            printf("%d", cnt2 - j);
            for(; j < cnt2; ++j)
            {
                printf(" %d", pencil[j].id);
            }
            puts("");
        }
    }
    return 0;
}
