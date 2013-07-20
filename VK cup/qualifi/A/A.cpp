#include <stdio.h>

using namespace std;

const int MAXN = 1000;
int score[MAXN];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        --m;
        for(int i = 0; i < n; ++i)
            scanf("%d", &score[i]);
        int ans(0);
        for(int i = 0; i < n; ++i)
            if(score[i] > 0 && score[i] >= score[m])  ++ans;
        printf("%d\n", ans);
    }

    return 0;
}
