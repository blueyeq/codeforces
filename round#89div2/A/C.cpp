#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string s, ans;
int num[10], chg[10];

int ss(int &gg, int &lft, int have, int d)
{
    gg = min(lft, have);
    lft -= gg;
    return gg * d;
}
int main()
{
    int sam, n;
    while(cin>>n>>sam)
    {
        cin>>s;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; ++i)
        {
            ++num[s[i] - '0'];
        }
        int Min = 10 * n;
        ans = "";
        for(int i = 0; i < n; ++i)  ans += '9';

        for(int i = 0; i < 10; ++i)
        {
            int lft = max(0, sam - num[i]);
            memset(chg, 0, sizeof(chg));
            int h(0);
            for(int d = 1; d <= 9; ++d)
            {
                if(lft == 0)  break;
                if(d + i < 10)
                    h += ss(chg[d + i], lft, num[i + d], d);
                if(i - d >= 0)
                    h += ss(chg[i - d], lft, num[i - d], d);
            }
            string tmp = s;
            if(h > Min)  continue;
            for(int j = 0; j < n; ++j)
            {
                int t = tmp[j] - '0';
                if(t > i && chg[t])
                {
                    tmp[j] = i + '0';
                    --chg[t];
                }
            }

            for(int j = n - 1; j >= 0; --j)
            {
                int t = tmp[j] - '0';
                if(t < i && chg[t])
                {
                    tmp[j] = i + '0';
                    --chg[t];
                }
            }

            if(Min > h || ans > tmp)
            {
                Min = h;
                ans = tmp;
            }
        }
        cout<<Min<<endl<<ans<<endl;
    }


    return 0;
}
