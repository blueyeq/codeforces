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

string s[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};\

int get(string ts)
{
    for(int i = 0; i < 12; ++i)
        if(ts == s[i]) return i;
    return -1;
}
string s1, s2, s3, str[3];
int judge()
{
    int t1 = get(s1);
    int t2 = get(s2);
    int t3 = get(s3);
    int d1 = (t2+12-t1) % 12;
    int d2 = (t3+12-t2) % 12;
    int d3 = (t3+12-t1) % 12;
    if(d1 == 4 && d2 == 3 && d3 == 7)
        return 2;
    else if(d1 == 3 && d2 == 4)
        return 1;
    return -1;
}
int solve()
{
    int res(-1);
    bool flag[3];
    flag[0] = flag[1] = flag[2] = 0;
    for(int i = 0; i < 3; ++i)
    {
        flag[i] = true;
        s1 = str[i];
        for(int j = 0; j < 3; ++j)
        {
            if(flag[j] == true) continue;
            flag[j] = true;
            s2 = str[j];
            for(int k = 0; k < 3; ++k)
            {
                if(flag[k] == true) continue;
                s3 = str[k];
                int t = judge();
                if(t == 2)  return 2;
                if(t == 1)  res = 1;
            }
            flag[j] = false;
        }
        flag[i] = false;
    }
    return res;
}
int main()
{
    cin>>str[0]>>str[1]>>str[2];
    int ans = solve();
    if(ans == 2)    printf("major\n");
    else if(ans == 1)    printf("minor\n");
    else printf("strange\n");
	return 0;
}
