/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    while(cin>>n)
    {
        string ans, str;
        int Max(-1000000000);
        for(int i = 0; i < n; ++i)
        {
            cin>>str;
            int tmp(0);
            for(int i = 0; i < 7; ++i)
            {
                cin>>a;
                if(i == 0)
                {
                    a = max(a,0);
                    a = min(a,50);
                    tmp += 100 * a;
                }
                else if(i == 1)
                {
                    a = max(a,0);
                    a = min(a,50);
                    tmp -= 50 * a;
                }
                else tmp += a;
            }
            if(tmp > Max)
            {
                ans = str;
                Max = tmp;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
