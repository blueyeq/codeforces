/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cstring>
#define MAXN 0

using namespace std;

typedef long long LL;
int getInt(string s)
{
    int len(s.size());
    if(len < 3)  return -1;
    if(len >= 4 && s.substr(len - 4) == "lios")  return 1;
    if(len >= 3 && s.substr(len - 3) == "etr")  return 2;
    if(len >= 6 && s.substr(len - 6) == "initis")  return 3;
    if(len >= 5 && s.substr(len - 5) == "liala")  return 4;
    if(len >= 4 && s.substr(len - 4) == "etra")   return 5;
    if(len >= 6 && s.substr(len - 6) == "inites")  return 6;
    return -1;
}
int main()
{

    string str;
    int nState(0), fg(1);
    while(cin>>str)
    {
        int t = getInt(str);
        if(t < nState)  fg = false;
        else if(t > nState)
        {
            if(nState == 0)
            {
                if(t != 3 && t != 6)  nState = t;
                else fg = false;
            }
            else if(nState + 1 != t || t == 4)
                fg = false;
            else nState = t;
        }
        else if(nState == 2 || nState == 5)  fg = false;
    }
    //printf("%d  %d\n", nState, fg);
    if(fg && nState != 1 && nState != 4)  puts("YES");
    else  puts("NO");

	return 0;
}
