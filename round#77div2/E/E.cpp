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
const LL mod = 1000000007;

LL dp[1010][10][2];

//  ni guo lai
void init(int dis)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 10; ++i)
        dp[0][i][0] = 1;
    for(int i = 1; i <= 1000; ++i)
    for(int j = 0; j <= 9; ++j)
    for(int jj = 0; jj <= 9; ++jj)
    {
        if((j==4 || j == 7) && (jj==4 || jj==7))
        {

        }
        else
    }



}

int main()
{




	return 0;
}
