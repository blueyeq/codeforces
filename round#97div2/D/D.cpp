#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int p[8][2];
int p1[4], p2[4];

int get(int a[])
{
    int x1 = p[a[1]][0] - p[a[0]][0];
    int y1 = p[a[1]][1] - p[a[0]][1];
    int x2 = p[a[2]][0] - p[a[1]][0];
    int y2 = p[a[2]][1] - p[a[1]][1];
    if(x1 * y2 + y1 * x2 == 0)
    {
        int x3 = p[a[2]][0] - p[a[3]][0];
        int y3 = p[a[2]][1] - p[a[3]][1];
        if(x3 == x1 && y3 == y1)
        {
            if(x1 * x1 + y1 * y1 == x2 * x2 + y2 * y2)
            {
                for(int i = 0; i < 4; ++i)
                    printf("%d ", a[i]);
                puts("");
                return 0;
            }
            return 1;
        }
    }
    return 2;
}

bool ok(int a[], int b[])
{
    if(get(a) == 0 && get(b) != 2)  return 1;
    return 0;
}
bool have[10], vis[10];

int main()
{
    freopen("in", "r", stdin);
    while(scanf("%d%d", &p[0][0], &p[0][1]) != EOF)
    {
        for(int i = 1; i < 8; ++i)
            scanf("%d%d", &p[i][0], &p[i][1]);

        bool fg(0);
        memset(have, 0, sizeof(have));
        memset(vis, 0, sizeof(vis));
        vector<int>  vi;
        for(int i = 0; i < 8; ++i)
            vi.push_back(i);
        while(next_permutation(vi.begin(), vi.end() ) )
        {
            for(int i = 0; i < 8; ++i)
            {
                if(i < 4)  p1[i] = vi[i];
                else p2[i - 4] = vi[i];
            }
            if(ok(p1, p2))
            {
                fg = 1;
                break;
            }
        }
        if(!fg)  puts("NO");
        else
        {
            printf("YES");
            for(int i = 0; i < 4; ++i)
            {
                if(i == 3)  printf("%d\n", p1[i]);
                else printf("%d ",p1[i]);

            }

            for(int i = 0; i < 8; ++i)
            {
                if(i == 3)  printf("%d\n", p2[i]);
                else  printf("%d\n", p2[i]);
            }
        }
    }
    return 0;
}
