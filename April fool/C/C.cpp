#include <stdio.h>

using namespace std;

typedef long long LL;
char s[] = {13, 238, 112, 112};
char c1 = 13, c2 = 238, c3 = 112;
int main()
{
    printf("<-%d%d%d%d->\n", c1, c2, c2,c3);
    printf("--%s\n", s);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        LL ans(0);
        for(int i = 1; i <= n; ++i)
        {
            int ta;
            scanf("%d", &ta);
            ans += ta * i;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
