#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if(a <= b)  puts("0");
        else printf("%d\n", (c * a + b - 1) / b - c);
    }


    return 0;
}

