#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
__int64 sum;   ////  int64 WAÁËn´Î¡£¡£¡£¡£ 
int map[310][310];

void flody()
{
    for(int k = 0; k != n; ++k)
    {
        for(int i = 0; i != n; ++i)
        {
            for(int j = 0; j != n; ++j)
            {
                if(map[i][j] > map[i][k] + map[k][j])
       map[i][j] = map[j][i] = map[i][k] + map[k][j];
            }
        }
    }
}
void getsum()
{
    sum = 0; 
    for(int i = 0; i != n; ++i)
    {
        for(int j = i+1; j != n; ++j)
        {
            sum += map[i][j];    
        }
    } 
}
int main()
{
    int m;
    while(cin>>n)
    {
        for(int i = 0; i != n; ++i)
        for(int j = 0; j != n; ++j)
            scanf("%d",&map[i][j]);
        
        flody();
        int a, b, c;
        scanf("%d",&m); 
        for(int k = 0; k != m; ++k)
        {
            scanf("%d%d%d",&a,&b,&c);
            --a;  --b;
            for(int i = 0; i != n; ++i)
            for(int j = 0; j != n; ++j)
            {
                if(map[i][j] > (map[i][a] + c + map[b][j]))
                {
                   map[i][j] = map[j][i] = map[i][a] + map[b][j] + c;     
                }
            }
            getsum();
            if(k == m-1)
               cout<<sum<<endl;
            else
               cout<<sum<<" ";
        }
    }
    return 0;
}