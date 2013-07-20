#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int d[110], hill[110];
int num[110];
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i < m; ++i)
    {
        cin>>d[i];
    }
    for(int i = 0; i < m; ++i)
    {
        cin>>hill[i];
    }

    for(int i = 0; i < k; ++i)
    {
        for(int i = 0; i < m; ++i)
        {
            if(hill[i] % d[i] == 0)
               ++num[i];
        }
    }
    int Min = 1000;
    for(int i = 0; i < m; ++i)
    {
        if(num[i] < Min)  Min = num[i];
    }
    int t = 0;
    for(int i = 0; i < m; ++i)
    {
        if(num[i] == Min)
           ++t;
    }
    printf("%d\n",t);
    for(int i = 0; i < m; ++i)
    {
        if(num[i] == Min)
            printf("%d ",i+1);
    }

    return 0;
}
