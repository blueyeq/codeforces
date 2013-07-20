#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int a[100][2];
int main()
{
    while(cin>>n)
    {
        for(int i = 0; i != n; ++i)
        {
            cin>>a[i][0]>>a[i][1];
        }
        
        bool flag = false;
        for(int i = 0; i != n && !flag; ++i)
        {
            int k = a[i][0] + a[i][1];    
            for(int j = 0; j != n && !flag; ++j)
            {
                if(i == j)  continue;    
                if(k == a[j][0] && (a[j][0] + a[j][1] == a[i][0]))
                   flag = true;
            }
                 
        }
        
        if(flag)  cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
    
    return 0;
}