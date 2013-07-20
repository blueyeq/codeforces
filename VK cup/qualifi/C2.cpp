#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 200010;

int c[26][MAXN];
int maxP[26];

void update(int x, int y, int val)
{
    while(y <= maxP[x])
    {
        c[x][y] += val;
        y += y & (-y);
    }
}
int get(int x, int y)
{
    int res(0);
    while(y > 0)
    {
        res += c[x][y];
        y -= y & (-y);
    }
    return res;
}
char s[110], ts[110];
bool dele[MAXN], isAlp[26][MAXN];

int main()
{
//    freopen("std.in", "r", stdin);
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%s", s + 1);
        s[0] = 'a';
        int len(strlen(s)), mr(0);
        memset(c, 0, sizeof(c));
        memset(isAlp, 0, sizeof(isAlp));
        for(int i = 1; i < len; ++i)
            maxP[s[i] - 'a'] = (n - 1) * (len - 1) + i;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j < len; ++j)
            {
                dele[++mr] = 0;
                isAlp[s[j] - 'a'][mr] = 1;
                update(s[j] - 'a', mr, 1);
            }
        }
        strcpy(ts, s );
        scanf("%d", &m);
        for(int i = 0, k; i < m; ++i)
        {
            scanf("%d%s", &k, s);
            int l(0), r(maxP[s[0] - 'a']);
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                int cnt = get(s[0] - 'a', mid);
                if(cnt == k && !dele[mid] && isAlp[s[0] - 'a'][mid])
                {
                    dele[mid] = 1;
                    update(s[0] - 'a', mid, -1);
                    break;
                }
                if(cnt >= k)  r = mid - 1;
                else  l = mid + 1;
            }
        }
        strcpy(s, ts );
        for(int i = 1; i <= mr; ++i)
        {
            if(!dele[i])  putchar(s[(i % (len - 1) == 0) ? len - 1 : i % (len - 1)]);
        }
        puts("");
    }


    return 0;
}
