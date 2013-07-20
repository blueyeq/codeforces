#include <stdio.h>
#include <cstring>

int main()
{
    int len, T, H, ans, cnt;
    char str[1010];
    while(scanf("%d",&len) != EOF)
    {
        H = T = 0;
        scanf("%s",str);
        for(int i = 0;i < len; ++i)
        {
            if(str[i] == 'H')  ++H;
            else if(str[i] == 'T') ++T;
        }


        for(int i = 0; i < len; ++i)
        {
            if(str[i] == 'H')
            {
                cnt = 1;
                for(int j = 1; j < H; ++j)
                {
                    if(str[(i+j)%len] == 'H')   ++cnt;
                }
                if(ans > H - cnt)   ans = H - cnt;
            }
            if(str[i] == 'T')
            {
                cnt = 1;
                for(int j = 1; j < T; ++j)
                {
                    if(str[(i+j)%len] == 'T')   ++cnt;
                }
                if(ans > T - cnt)   ans = T - cnt;
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
