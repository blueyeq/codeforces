#include <stdio.h>
#include <cstring>
#include <string>

using namespace  std;

const int MAXN = 40000;

char phone[MAXN][30];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s", phone[i]);
        int len = strlen(phone[0]), ptr(-1);
        while(ptr++ < len)
        {
            int i;
            for(i = 1; i < n; ++i)
                if(phone[i][ptr] != phone[0][ptr])  break;
            if(i < n)  break;
        }
        printf("%d\n", min(ptr, len));
    }


    return 0;
}
