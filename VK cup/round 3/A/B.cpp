#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1000000;

vector<string> ans;

char str[MAXN];
int pos[MAXN];

int main()
{
    while(scanf("%s", str) != EOF)
    {
        int len(strlen(str));
        int cnt(0);
        for(int i = 0; i < len; ++i)
            if(str[i] == '.')  pos[cnt++] = i;
        bool flag(1);
        if(cnt < 1 || pos[0] > 8 || len - pos[cnt - 1] - 1 > 3 || pos[0] == 0 || pos[cnt - 1] == len - 1)  flag = 0;
        ans.clear();
        string  tmp[3];
        int now(0);
        tmp[now] = "";
        for(int i = 0; i < pos[0] && flag; ++i)
            tmp[0] += str[i];
        for(int i = 0; i < cnt - 1 && flag; ++i)
        {
            if(pos[i + 1] - pos[i] - 1 <= 1 || pos[i + 1] - pos[i] - 1 >= 12)  flag = 0;
            if(!flag)  break;
            int j(1), tl(pos[i + 1] - pos[i] - 1);
            for(; ; ++j)
            {
                if(tl - j <= 8)  break;
            }
            int u = (now + 1) % 3, v = (now + 2) % 3;
            tmp[u] = tmp[v] = "";
            for(int k = pos[i] + 1, ll(1); k < pos[i + 1] ; ++k, ++ll)
            {
                if(ll <= j)  tmp[u] += str[k];
                else  tmp[v] += str[k];
            }
            ans.push_back(tmp[now] + "." + tmp[u]);
            now = (now + 2) % 3;
        }
        if(flag)
        {
            string ts = "";
            for(int i = pos[cnt - 1] + 1; i < len; ++i)   ts += str[i];
            ans.push_back(tmp[now] + "." + ts);
        }
        if(!flag)   puts("NO");
        else
        {
            puts("YES");
            for(int i = 0; i < ans.size(); ++i)
                cout<<ans[i]<<endl;
        }
    }

    return 0;
}
