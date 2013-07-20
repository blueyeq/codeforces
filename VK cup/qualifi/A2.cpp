#include <stdio.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 2010;
const int INF = -1000000000;

map<string, int> id;
int message[MAXN][3], cnt;
bool firend[MAXN][MAXN];
char name1[100], name2[100];
vector< string > name;

int get(char *s)
{
    if(id.find(s) == id.end())
    {
        id[s] = cnt++;
        name.push_back(s);
    }
    return id[s];
}
int main()
{
//    freopen("std.in", "r", stdin);
    int n, tim;
    while(scanf("%d%d", &n, &tim) != EOF)
    {
        id.clear();
        cnt = 0;
        int m(0);

        memset(firend, 0, sizeof(firend));
        for(int i = 0, j; i < n; ++i)
        {
            scanf("%s%s%d", name1, name2, &j);
            int a = get(name1);
            int b = get(name2);
            message[i][0] = a;  message[i][1] = b;  message[i][2] = j;
            for(int k = 0; k < i && !firend[a][b]; ++k)
            {
                if(message[k][0] == b && message[k][1] == a
                && j - message[k][2] > 0 && j - message[k][2] <= tim)
                    firend[a][b] = firend[b][a] = 1,  ++m;
            }
        }
        cout<<m<<endl;
        for(int i = 0; i < name.size(); ++i)
        {
            for(int j = i + 1; j < name.size(); ++j)
            {
                if(firend[i][j])   cout<<name[i] << " " << name[j]<<endl;
            }
        }
    }


    return 0;
}
