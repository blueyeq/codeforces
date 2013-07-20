#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 400010;
const int INF = 1000000000;

int mp[300];
LL sum[2][MAXN][26];
char s1[MAXN], s2[MAXN];
int n;

void init(int e)
{
    for(int i = 0; i < n; ++i)
    {
//        if(e)sum[1][2][mp[s1[i]]]++;
//        else  sum[0][1][mp[s1[i]]]++;
        ++sum[e][1][mp[s1[i]]];
        sum[e][i + 2][mp[s1[i]]]--;
//        printf("%I64d  %d\n", sum[1][mp[s1[i]]]);
    }
    for(int i = 0; i < 26; ++i)
    for(int j = 2; j <= n; ++j)
        sum[e][j][i] += sum[e][j - 1][i];
//    printf("%I64d\n", sum[1][0]);

    for(int i = 0; i < 26; ++i)
    for(int j = 2; j <= n; ++j)
        sum[e][j][i] += sum[e][j - 1][i];
//    printf("%I64d\n", sum[1][1]);

}
int main()
{
    freopen("E.in", "r", stdin);
    while(~scanf("%d", &n))
    {
        scanf("%s%s", s1, s2);
        for(int i = 0; i <= n; ++i)  for(int j = 0; j < 26; ++j)   sum[0][i][j] = sum[1][i][j] = 0;
        for(int i = 0; i < 26; ++i)  mp[i + 'A'] = i;
        init(0);
        reverse(s1, s1 + n);
        init(1);
        LL res(0);
        for(int i = 0; i < n; ++i)
        {
            res += sum[0][i + 1][mp[s2[i]]] * sum[1][n - i][mp[s2[i]]];
//            printf(">>%I64d\n", sum[i + 1][mp[s2[i]]]);
        }
        LL tmp = (LL) n * (n + 1) * (2 * n + 1) / 6;
        printf("%.6lf\n", (double) res / tmp);
    }


    return 0;
}

