#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN = 100010;

vector< pair<int, int> > ans, a;
int h[MAXN], typ[MAXN];

int main()
{
//    freopen("C.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int Min(10000000);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &h[i]);
            Min = min(Min, h[i]);
        }
        ans.clear();
        for(int i = 1; i <= Min; ++i)
            ans.PB(MP(1, n));
        for(int i = 1; i <= n; ++i)
            h[i] -= Min;
        for(int i = 1; i <= n; ++i)
        {
            while(h[i] == 0 && i <= n) ++i;
            if(i > n)  break;

            a.clear();
            a.PB(MP(h[i], i));

            int Max(h[i]), lt(i);
            typ[i] = 1;
            while(h[i] <= h[i + 1] && i + 1 <= n)
            {
               // printf("---%d   %d   %d\n", i, h[i], h[i + 1]);
                a.PB(MP(h[i + 1], i + 1));
                Max = h[i + 1];
                typ[i + 1] = 1;
                ++i;
            }
//            printf("%d **  %d\n", lt, i);
            int rt = min(n, i);

            while(h[i] >= h[i + 1] && i + 1 <= n && h[i + 1] > 0)
            {
                a.PB(MP(Max - h[i + 1], i + 1));
                typ[i + 1] = -1;
                ++i;
            }
            sort(a.begin(), a.end());
            vector< pair<int, int> > ::iterator it;
            int hh = 0;
            for(it = a.begin(); it != a.end(); ++it)
            {
                for(; hh < it->first; ++hh)
                    ans.PB(MP(lt, rt));
//                printf("++%d  %d\n", it->first, it->second);
                int id = it->second;
                if(typ[id] == -1)  ++rt;
                if(typ[id] == 1) ++lt;
            }
        }

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d  %d\n", ans[i].first, ans[i].second);
    }


    return 0;
}
