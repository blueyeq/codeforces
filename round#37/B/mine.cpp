#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

int Intall, reg;
int tim[1010];
int vis[1010];
typedef struct MyScoll
{
    int prec;
    int dim;
    int id;
}SCOLL;

SCOLL sco[1010], tmp[1010];

int main()
{
    int n;
    cin>>n>>Intall>>reg;

    for(int i = 0; i < n; ++i)
    {
        cin>>sco[i].prec>>sco[i].dim;
        sco[i].id = i;
    }

    memset(vis,0,sizeof(vis));
    int remain = Intall;
    int len(0), now(0), t(0), i(0), t_hurt(0), pre;
    bool ok(true);
    for(;;++t)
    {
         i = -1;
         t_hurt = -1;
         pre = remain;
         remain -= now;
         remain += reg;
         if(remain > Intall)  remain = Intall;
         else if(remain <= 0) break;
         for(int j = 0; j < n; ++j)
         {
             if(vis[j]) continue;
             if(remain*100 > sco[j].prec * Intall) continue;
             if(sco[j].dim > t_hurt)
             {
                 t_hurt = sco[j].dim;
                 i = j;
             }
         }
         if(i == -1 && remain >= pre)
         {
             ok = false;
             break;
         }
         if(i != -1)
         {
             tmp[len].id = i;
             tmp[len++].prec = t;
             now += sco[i].dim;
             vis[i] = true;
         }
    }
    if(!ok)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("%d %d\n",t,len);
    for(int k = 0; k < len; ++k)
    {
        printf("%d %d\n",tmp[k].prec,tmp[k].id+1);
    }
    return 0;
}
