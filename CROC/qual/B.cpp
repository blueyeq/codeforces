#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 100010;
int pos[MAXN];

int main()
{
    int a, b, mod, r1, r2;
    while(scanf("%d%d%d%d", &a, &b, &mod, &r1) != EOF)
    {
        memset(pos, -1, sizeof(pos));
        pos[r1] = 0;
        int len(0), ans;
        while(++len)
        {
            r2 = (a * r1 + b) % mod;
            if(pos[r2] != -1)
            {
                ans = len - pos[r2];
                break;
            }
            pos[r2] = len;
            r1 = r2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
