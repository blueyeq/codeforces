#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 1000100;
const int INF = 1000000010;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int Min(INF), cnt(0), Min_i;
        for(int i = 1, j; i <= n; ++i)
        {
            scanf("%d", &j);
            if(j < Min)
            {
                Min = j; cnt = 1; Min_i = i;
            }
            else  if(j == Min)  ++cnt;
        }
        if(cnt == 1)   printf("%d\n", Min_i);
        else  puts("Still Rozdil");
    }


    return 0;
}

