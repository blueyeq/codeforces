#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int a[110];

int  main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    int now(1), num(0);
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == now)
        {
            ++now;
            ++num;
        }
    }
    if(num == 0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<num<<endl;
    now = 1;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == now)
        {
            if( now == 1) cout<<i+2001;
            else   cout<<" "<<i+2001;
            ++now;
        }
    }
    cout<<endl;
    return 0;
}

