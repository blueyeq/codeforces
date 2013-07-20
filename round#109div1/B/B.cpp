#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 101000;
bool dele[MAXN];
int prim[10010], nPri;
int id[MAXN];

void getPrim()
{
    nPri = 0;
    memset(dele, 0, sizeof(dele));
    for(int i = 2; i < MAXN; ++i)
    {
        if(!dele[i])
        {
            prim[nPri++] = i;
            id[i] = nPri - 1;
        }
        for(int j = 0; j < nPri && i * prim[j] < MAXN; ++j)
        {
            dele[i * prim[j]] = 1;
            if(i % prim[j] == 0)  break;
        }
    }
}

int sz[MAXN];
int value[MAXN][10];   // if > 10
bool isIn[MAXN];
char op[15];
int num[10100];
int src[10010];

int main()
{
//    freopen("in.c", "r", stdin);
    getPrim();
    int n, m, u;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(sz, 0, sizeof(sz));
        for(int i = 2; i <= n; ++i)
        {
            int t = i;
            for(int j = 0; ; ++j)
            {
                if(t % prim[j] == 0)
                {
                    value[i][sz[i]] = j;
                    while(t % prim[j] == 0)     t /= prim[j];
                    ++sz[i];
                }
                if(t == 1)  break;
                if(!dele[t])
                {
                    value[i][sz[i]++] = id[t];
                    break;
                }
            }
//            if(i < 20)
//            {
//                printf("%d  -->%d  >>>", i, sz[i]);
//                for(int j = 0; j < sz[i]; ++j)
//                {
//                    printf("%d   ", value[i][j]);
//                }
//                puts("");
//            }
        }
        memset(isIn, 0, sizeof(isIn));
        memset(num, 0, sizeof(num));

        for(int i = 1; i <= m; ++i)
        {
            scanf("%s%d",op, &u);
            if(u == 1)
            {
                if(op[0] == '+')
                {
                    if(isIn[1])  puts("Already on");
                    else  puts("Success");
                    isIn[1] = 1;
                }
                else
                {
                    if(isIn[1])  puts("Success");
                    else  puts("Already off");
                    isIn[1] = 0;
                }
            }
            else if(op[0] == '+')
            {
                if(isIn[u])  puts("Already on");
                else
                {
                    int ans(-1), fg(1);
                    for(int j = 0; j < sz[u]; ++j)
                    {
                        int priId = value[u][j];
                        if(num[priId] != 0)
                        {
                            ans = src[priId];
                            fg = 0;
                            break;
                        }
                    }
                    if(!fg)    printf("Conflict with %d\n", ans);
                    else
                    {
                        puts("Success");
                        for(int j = 0; j < sz[u]; ++j)
                        {
                            int priId = value[u][j];
                            num[priId] = 1;
                            src[priId] = u;
                        }
                        isIn[u] = 1;
                    }
                }
            }
            else
            {
                if(!isIn[u])  puts("Already off");
                else
                {
                    puts("Success");
                    for(int j = 0; j < sz[u]; ++j)
                    {
                        int priId = value[u][j];
                        num[priId] = 0;
                    }
                    isIn[u] = 0;
                }
            }
        }
    }

}
