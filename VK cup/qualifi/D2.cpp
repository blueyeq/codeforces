#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long LL;
const int MAXN = 2010;

int lt[MAXN], mid[MAXN], c[MAXN];
char s[MAXN];
int len;

void update(int x, int val)
{
    while(x <= len)
    {
        c[x] += val;
        x += x & (-x);
    }
}
int get(int x)
{
    int res(0);
    while(x > 0)
    {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}

LL sum[MAXN];
int main()
{
    while(scanf("%s", s + 1) != EOF)
    {
        s[0] = '$';
        memset(c, 0, sizeof(c));
        len = strlen(s);
        for(int i = 1; i < len; ++i)
        {
            mid[i] = 1;
            update(i, 1);
            lt[i] = 0;
            for(int j = 1; i - j >= 1 && i + j < len && s[i - j] == s[i + j]; ++j)
            {
                mid[i] = j + 1;
                update(i - j, 1);
            }
            for(int j = 1; i - j + 1 >= 1 && i + j < len && s[i - j + 1] == s[i + j]; ++j)
            {
                lt[i] = j;
                update(i - j + 1, 1);
            }
        }
        sum[0] = 0;
        for(int i = 1; i < len; ++i)
        {
            sum[i] = get(i);
        }

        LL ans(0);
        for(int i = 1; i < len; ++i)
        {
            for(int j = 1; i + j < len && j <= mid[i]; ++j)
            {
                ans += sum[len - 1] - sum[i + j - 1];
            }
            for(int j = 1; j <= lt[i] && i + j + 1 < len; ++j)
            {
                ans += sum[len - 1] - sum[i + j];
            }
        }
        printf("%I64d\n", ans);
    }


    return 0;
}
