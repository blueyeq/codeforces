#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
char s[20];

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        sprintf(s, "%d", b);
        int len(strlen(s));
        reverse(s, s + len);
        long long  c(0);
        for(int i = 0; i < len; ++i)
            c = c * 10LL + s[i] - '0';
        printf("%I64d\n", c + a);
    }


}
