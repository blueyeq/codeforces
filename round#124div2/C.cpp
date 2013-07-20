#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;

const int INF = 1000000000;
const int MAXN = 100010;

int Max[MAXN];
char str[MAXN];

int main()
{
    while(scanf("%s", str) != EOF)
    {
        int len(strlen(str));
        Max[len - 1] = len - 1;
        for(int i = len - 2; i >= 0; --i)
        {
            Max[i] = i;
            if(str[Max[i]] < str[Max[i + 1]])
            {
                Max[i] = Max[i + 1];
            }
        }
        int j(Max[0]);
        while(j != len - 1)
        {
            printf("%c", str[j]);
            ++j;
            j = Max[j];
//            printf("%d\n", j);
        }
        printf("%c\n", str[len - 1]);
    }



    return 0;
}

