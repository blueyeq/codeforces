#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, m, mod, col;  // r , c
int map[110][110];
int pre[110][10], now[110][10];
int path[110][110][10];
char str[110];
void print(int k ,int c, int left)   //  路径
{
    int tmp = (mod+(left - map[k][c]) % mod) % mod;
    if(k == n-1)  {  col = c;   return;}
    if(path[k][c][left] == 0)      print(k+1,c-1,tmp),  str[k] = 'R';
    else  if(path[k][c][left] == 1)  print(k+1,c+1,tmp),  str[k] = 'L';
}
int main()
{
    while(true){
    char bit[110];
    scanf("%d%d%d",&n,&m,&mod);
    ++mod;
    for(int i = 0; i < n; ++i)  //  读入数据
    {
        scanf("%s",bit);
        for(int j = 0; j < m; ++j)
            map[i][j] = bit[j] - '0';
    }
    //  初始化
    memset(path,-1,sizeof(path));
    memset(pre,-1,sizeof(pre));
    for(int i = 0; i < m; ++i)
        pre[i][0] = 0;

    for(int i = n-1; i >= 0; --i)  //  自底向上dp
    {
        memset(now,-1,sizeof(now));
        for(int j = 0; j < m; ++j)
        {
                for(int k = 0; k < mod; ++k)  //  余数
                {
                    for(int jj = j - 1; jj < j + 2; jj += 2)
                    {
                        if(jj < 0 || jj >= m)  continue;
                        if(pre[jj][k] == -1)   continue;
                        int tmp = (map[i][j] + k) % mod;   //
                        int nn  = (map[i][j] + k) / mod + pre[jj][k];
                        if(now[j][tmp] == -1)
                        {
                            now[j][tmp] = nn;
                            if(jj < j)  path[i][j][tmp] = 0;
                            else    path[i][j][tmp] = 1;
                        }
                        else if(now[j][tmp] < nn)
                        {
                            now[j][tmp] = nn;
                            if(jj < j)   path[i][j][tmp] = 0;
                            else    path[i][j][tmp] = 1;
                        }
                    }

                }
        }
        for(int j = 0; j < m; ++j)
        for(int k = 0; k < mod; ++k)
            pre[j][k] = now[j][k];
    }
    col = 0;
    for(int i = 0; i < m; ++i)
        if(now[i][0] > now[col][0])  col = i;
    cout<<"col0:  "<<col<<endl;
    if(now[col][0] == -1)
    {
        printf("-1\n");   return 0;
    }

    printf("%d\n",now[col][0]*mod);

    print(0,col,0);

    printf("%d\n",col+1);

    for(int i = n-2; i >= 0; --i)
       printf("%c",str[i]);
    printf("\n");
    }
}
