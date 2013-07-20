#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;
const int move = 500002;

struct Node
{
    int id, val;
    Node(int a, int b) : id(a), val(b){}
    bool operator < (const Node &bb)  const
    {
        return val < bb.val;
    }
};

vector<Node> row[MAXN], col[MAXN], raddc[MAXN], rsubc[MAXN];

int attack[MAXN], num[10];

int main()
{
    //freopen("in","r", stdin);

    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            row[i].clear();
            col[i].clear();
        }
        for(int i = 1; i < MAXN; ++i)
        {
            raddc[i].clear();
            rsubc[i].clear();
        }
        for(int i = 1; i <= m; ++i)
        {
            int r, c;
            scanf("%d%d", &r, &c);
            row[r].push_back(Node(i, c));
            col[c].push_back(Node(i, r));
            raddc[r + c].push_back(Node(i, r));
            raddc[r - c + move].push_back(Node(i, r));
        }
       //printf("readin %d\n", m);
        memset(attack, 0, sizeof(attack));
        memset(num, 0, sizeof(num));

        for(int i = 1; i <= n; ++i)
        {
            if(row[i].size() > 1)
            {
                sort(row[i].begin(), row[i].end());
                int sz = row[i].size();
                for(int j = 0; j < sz; ++j)
                {
                    int add = 1;
                    if(j > 0 && j  + 1 < sz)   add = 2;
                    attack[row[i][j].id] += add;
                }
            }
            if(col[i].size() > 1)
            {
                sort(col[i].begin(), col[i].end());
                int sz = col[i].size();
                for(int j = 0; j < sz; ++j)
                {
                    int add = 1;
                    if(j > 0 && j  + 1 < sz)   add = 2;
                    attack[col[i][j].id] += add;
                }
            }
        }
        for(int i = 1; i < MAXN; ++i)
        {
            if(raddc[i].size() > 1)
            {
                sort(raddc[i].begin(), raddc[i].end());
                int sz = raddc[i].size();
                for(int j = 0; j < sz; ++j)
                {
                    int add(1);
                    if(j > 0 && j + 1 < sz) add = 2;
                    attack[raddc[i][j].id] += add;
                }
            }
            if(rsubc[i].size() > 1)
            {
                sort(rsubc[i].begin(), rsubc[i].end());
                int sz = rsubc[i].size();
                for(int j = 0; j < sz; ++j)
                {
                    int add(1);
                    if(j > 0 && j + 1 < sz) add = 2;
                    attack[rsubc[i][j].id] += add;
                }
            }
        }
        for(int i = 1; i <= m; ++i)
        {
            ++num[attack[i]];
           // if(attack[i] > 8)   puts("error");
        }
        for(int i = 0; i <= 8; ++i)
        {
            if(i == 8)  printf("%d\n", num[i]);
            else printf("%d ", num[i]);
        }
    }

    return 0;
}
