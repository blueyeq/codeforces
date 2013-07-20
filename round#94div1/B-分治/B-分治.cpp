#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
const int MAXN = 100010;

int len, cnt;
char ch[MAXN], res[MAXN];
LL num[26];
int pos[2][MAXN], siz[2];

bool dfs(int now, LL n)
{
    memset(num, 0, sizeof(num));
    for(int i = 0; i < siz[now]; ++i)
        num[ch[pos[now][i]] - 'a'] += len - pos[now][i];

    for(int i = 0; i < 26; ++i)
    {
        if(num[i] >= n)
        {
            res[cnt++] = i + 'a';

            int newn(0);  siz[!now] = 0;
            for(int j = 0; j < siz[now]; ++j)
            {
                if(ch[pos[now][j]] - 'a' == i)
                {
                    if(pos[now][j] + 1 < len)    pos[!now][siz[!now]++] = pos[now][j] + 1;
                    ++newn;
                }
            }
            if(newn >= n)
            {
                res[cnt++] = 0;
                return 1;
            }
            n -= newn;
            return dfs(!now, n);
        }
        else  n -= num[i];
    }
    return 0;
}
int main()
{
  //  freopen("in", "r", stdin);

    int n;
    while(scanf("%s%I64d", ch, &n) != EOF)
    {
        len = strlen(ch);
        siz[0] = siz[1] = 0;

        for(int i = 0; i < len; ++i)
            pos[0][siz[0]++] = i;

        cnt = 0;
        if(!dfs(0, n))  puts("No such line.");
        else printf("%s\n", res);
    }
    return 0;
}
