#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> vs[1010];
int len[1010], n, len0[1010];
int k, num[1010];
bool suc;

void dfs(string str, int l)
{
    if(suc)   return;
    if(l == len[k-1])
    {
        vs[len[k-1]].push_back(str);
        if(k == n)   suc = true;
        ++k;
        return;
    }
    // cout<<"k:  "<<k<<endl;
    dfs(str + "0", l + 1);
    dfs(str + "1", l + 1);
}

int main()
{
    while(cin>>n)
    {
        for(int i = 0; i < n; ++i)
        {
            cin>>len[i];
            len0[i] = len[i];
        }
        sort(len,len+n);
        for(int i = 0; i < n; ++i)
        {
            vs[len0[i]].clear();
        }
        suc = false;
        k = 1;
        dfs("0",1);
        dfs("1",1);
        memset(num,0,sizeof(num));
        if(!suc)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i = 0; i < n; ++i)
            {
                cout<<vs[len0[i]][num[len0[i]]++]<<endl;
            }
        }
    }
    return 0;
}
