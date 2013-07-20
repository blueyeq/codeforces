/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int b[100];
int main()
{
    double k, t;
    int n;
    while(scanf("%d%lf%lf",&n,&k,&t) != EOF)
    {

        double tt = (double)n*k*t/100;
        int a = (int) (tt / k);
        int re = int(tt - a*k);
        for(int i = 1; i <= n; ++i)
        {
            if(i <= a)  b[i] = k;
            else if(i == a+1)    b[i] = re;
            else b[i] = 0;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i != n)
                printf("%d ",b[i]);
            else
                printf("%d\n",b[i]);
        }
    }



	return 0;
}
