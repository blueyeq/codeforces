/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

char str[510];

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s",str);
            int len = strlen(str);
            if(len <= 10)   printf("%s\n",str);
            else printf("%c%d%c\n",str[0],len-2,str[len-1]);
        }
    }


	return 0;
}
