#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        double res(0), j;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf", &j);
            res += j;
        }
        printf("%.5lf\n", res / n);
    }



    return 0;
}

