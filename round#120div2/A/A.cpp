#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;


int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(n == 0 && m > 0)
        {
            puts("Impossible");
            continue;
        }
        printf("%d %d\n", n + max(0, m - n), n + max(0, m - 1));
    }


    return 0;
}
