#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;


int main()
{
    int n, m, r;
    while(scanf("%d%d%d", &n, &m, &r) != EOF)
    {
        if(n >= 2 * r && m >= 2 * r)  puts("First");
        else  puts("Second");
    }



    return 0;
}

