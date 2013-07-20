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

char trup, s1[10], s2[10];
char id[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int getid(char c)
{
    for(int i = 0; i < 9; ++i)
        if(id[i] == c)  return i;
    return -1;
}
bool cmp()
{
    if(s1[1] == trup)
    {
        if(s2[1] != trup)  return true;
        else if(getid(s1[0]) > getid(s2[0]))  return true;
        else return false;
    }
    else if(s2[1] == trup)  return false;
    else if(s1[1] == s2[1] && getid(s1[0]) > getid(s2[0])) return true;
    return false;
}

int main()
{
    while(cin>>trup)
    {
        cin>>s1>>s2;
        if(cmp())       printf("YES");
        else printf("NO");
    }


	return 0;
}
