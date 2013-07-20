/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXN 0

using namespace std;

typedef long long LL;

string org, num[10];

int main()
{
    while(cin>>org)
    {
        for(int i = 0; i < 10; ++i)
            cin>>num[i];
        for(int i = 0, j; i < 80; i += 10)
        {
            j = 0;
            for(; j < 10; ++j)
            {
                if(org.substr(i, 10) == num[j])
                    break;
            }
            cout<<j;
        }
        printf("\n");
    }



	return 0;
}
