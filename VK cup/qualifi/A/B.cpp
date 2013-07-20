#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[50];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i)
        {
            int num;
            scanf("%d", &num);
            ++cnt[num];
        }
        int ans(cnt[4]);
        ans += cnt[3];
        cnt[1] = cnt[1] - min(cnt[1], cnt[3]);
        ans += cnt[2] / 2;
        cnt[2] %= 2;
        if(cnt[2])
        {
            ans++;
            cnt[1] -= min(cnt[1], 2);
        }
        ans += (cnt[1] + 3) / 4;
        printf("%d\n", ans);
    }


    return 0;
}
