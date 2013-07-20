#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

int score[110], n;
map<string, int>  ms;

int main()
{
    int cnt(0), Max(0), k;
    string str, Max_str;
    scanf("%d",&n);
    ms.clear();
    memset(score,0,sizeof(score));
    for(int i = 0; i < n; ++i)
    {
        cin>>str;
        if(ms.find(str) == ms.end())  ms[str] = cnt++;
        k = ms[str];
        ++score[k];
        if(Max < score[k])
        {
            Max = score[k];
            Max_str = str;
        }
    }
    cout<<Max_str<<endl;
}
