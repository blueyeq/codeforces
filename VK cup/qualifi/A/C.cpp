#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 100010;

char cmd[20], s[100], cur[MAXN];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(cur, 0, sizeof(cur));
        int len(0);
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", cmd);
            if(cmd[0] == 'p')
            {
                putchar('/');
                for(int i = 0; i < len; ++i)  putchar(cur[i]);
                puts("");
            }
            else
            {
                scanf("%s", s);
                char *p = strtok(s, "/");
                if(s[0] == '/')   len = 0;
                while(p != NULL)
                {
                    if(strcmp(p, "..") == 0)
                    {
                        len -= 2;
                        while(len >= 0 && cur[len] != '/')
                        {
                            --len;
                        }
                        cur[++len] = 0;
                        if(len < 0)  cur[len = 0] = 0;

                        //printf("%d  %s\n", len, cur);
                    }
                    else
                    {
                        int tlen = strlen(p);
                        for(int i = 0; i < tlen; ++i)
                            cur[len++] = p[i];
                        cur[len++] = '/';
                        cur[len] = 0;
                        //printf("%d  %s\n", len, cur);
                    }
                    p = strtok(NULL, "/");
                }
            }
        }
    }
    return 0;
}
