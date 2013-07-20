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
    int n, pc, ps;
    char str[300];
    while(scanf("%d%d%d",&n,&ps,&pc) != EOF)
    {
        getchar();
        gets(str);
        int dir(1), a, t;
        if(str[3] == 'h')   dir = -1;
        bool cath(false);
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 1; i <= len && !cath; ++i)
        {
            if(str[i-1] == '0')
            {
                if(dir == 1)
                {
                    if(pc == n-1 && ps == n)
                    {
                        cath = true;
                        t = i;
                    }
                    if(++pc == n)   dir = -1;
                    if(ps != n) ++ps;
                }
                else
                {
                    if(pc == 2 && ps == 1)
                    {
                        cath = true;
                        t = i;
                    }
                    if(--pc == 1)   dir = 1;
                    if(ps != 1)   --ps;
                }
            }
            else
            {
                if(dir == 1)
                {
                    if(++pc == n)   dir = -1;
                    if(pc != 1)  ps = 1;
                    else  ps = n;
                }
                else
                {
                    if(--pc == 1)   dir = 1;
                    if(pc != n) ps = n;
                    else  ps = 1;
                }
            }
        }
        if(cath)    printf("Controller %d\n",t);
        else  printf("Stowaway\n");
    }
	return 0;
}
