#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;


int w[3000], num[3000];
char s1[MAXN], s2[MAXN];
int ext, cnt, sz;

void dfs(int dep)
{
    if(cnt >= ext)  return;
    int ss = 1;
    if(ext - cnt <= sz)  ss = 0;
    for(int i = ss; i < sz && cnt < ext; ++i)
        w[cnt++] = dep;
    dfs(dep + 1);
}

int main()
{
    while(scanf("%s%s", s1, s2) != -1)
    {
        memset(num, 0, sizeof(num));
        for(int i = 0; s1[i]; ++i)
        {
            ++num[s1[i]];
        }

        sz = strlen(s2);


        ext = cnt = 0;
        for(int i = 0; i < 300; ++i)
            if(num[i] > 0)  ++ext;
        sort(num, num + 300);

        reverse(num, num + 300);

        dfs(1);
        int ans(0);
        for(int i = 0; i < ext; ++i)
        {
            ans += num[i] * w[i];
            printf("%d\n", num[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}
