#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    char str[110];
    while(cin>>n)
    {
        getchar();
        gets(str);
        if(n % 3 == 0)
        {
           for(int i = 1; i < n+1; ++i)
           {
               cout<<str[i-1];
               if(i % 3 == 0 && i != n) cout<<"-";
           }
        }
        else if(n % 3 == 1)
        {
           for(int i = 1; i < n-3; ++i)
           {
               cout<<str[i-1];
               if(i % 3 == 0 && i != n-4) cout<<"-"; 
           }
           if(n != 4)  cout<<"-";
           cout<<str[n-4]<<str[n-3]<<"-"<<str[n-2]<<str[n-1];
        }
        else if(n % 3 == 2)
        {
             for(int i = 1; i < n - 1; ++i)
             {
                 cout<<str[i-1];
                 if(i % 3 == 0 && i != n-2)  cout<<"-";
             }
             if(n != 4 && n != 2) cout<<"-";
             cout<<str[n-2]<<str[n-1];
        } 
    }
    return 0;
}