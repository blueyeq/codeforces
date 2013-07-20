#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 100010;
char s[MAXN];
int ele[MAXN], num[MAXN];
bool g[30][30];

int main()
{
//    freopen("in.c", "r", stdin);
    int m;
    char op[20];
    while(scanf("%s", s) != EOF)
    {
        cin>>m;
        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; ++i)
        {
            cin>>op;
            g[op[0] - 'a'][op[1] - 'a'] = g[op[1] - 'a'][op[0] - 'a'] = 1;
//            cout<<op[0] - 'a'<<"  "<<op[1] - 'a'<<endl;
        }
        int n = strlen(s);
        int b = 1, cnt = 0;

        for(int i = 1; i < n; ++i)
        {
            if(s[i] != s[i - 1])
            {
                ele[cnt] = s[i - 1] - 'a';
                num[cnt++] = b;
                b = 1;
            }
            else  ++b;
        }
        ele[cnt] = s[n - 1] - 'a';
        num[cnt++] = b;

//        printf("%d\n", cnt);
//        for(int i = 0; i < cnt; ++i)
//        {
//            printf("%d  %d\n", ele[i], num[i]);
//        }
        int ans(0);
        for(int i = 1; i < cnt; ++i)
        {
            int odd(0), even(0);
            int j = i;
            while(g[ele[i]][ele[i - 1]] && i < cnt)
            {
                if((i - 1) % 2 == 0)  even += num[i - 1];
                else  odd += num[i - 1];
                ++i;
            }
            if(j < i)
            {
                if((i - 1) % 2 == 0)  even += num[i - 1];
                else odd += num[i - 1];
            }
            ans += min(odd, even);
        }
        printf("%d\n", ans);

    }



    return 0;
}
