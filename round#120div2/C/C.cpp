#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
typedef long long LL;

 struct Node
{
    int l, r, typ;
    Node(int a = 0, int b = 0, int c = 0)
    {
        l = a; r = b; typ = c;
    }
};
Node st[1000000];

char str[1000000];

int ele[1000000];
vector<int> add[1000000];

int main()
{
//    freopen("C.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        char cc[] = ",<>";
        getchar();
        gets(str);
        int cnt(0);
//        printf("%s\n", str);
        char *p = strtok(str, " ");
        while(p)
        {
            if(p[0] == 'p') ele[cnt++] = 1;
            else ele[cnt++] = 0;
            p = strtok(NULL, " ");
//            printf("%d  %d\n",cnt, ele[cnt - 1]);
        }
        for(int i = 0; i < cnt; ++i)
            add[i].clear();

        int top = -1;
        for(int i = 0; i < cnt ; ++i)
        {
            Node tmp(i, i, ele[i]);
            st[++top] = tmp;
            while(top >= 2 && st[top].typ == 0 && st[top - 1].typ == 0 && st[top - 2].typ == 1)
            {
                 int l0 = st[top - 2].l;
                 int r0 = st[top - 2].r;
                 int l1 = st[top - 1].l;
                 int r1 = st[top - 1].r;
                 int l2 = st[top].l;
                 int r2 = st[top].r;
                 add[r0].push_back(1);
                 add[r1].push_back(0);
                 add[r2].push_back(2);
                 top -= 3;
                 Node tt(l0, r2, 0);
                 st[++top] = tt;
//                 printf("cut: %d\n", top);
            }
//            printf("%d\n", top);
        }
        if(top != 0 || st[top].typ != 0) puts("Error occurred");
        else
        {
            for(int i = 0; i < cnt; ++i)
            {
                if(ele[i] == 1)  printf("pair");
                else  printf("int");
                for(int j = 0; j < add[i].size(); ++j)
                    printf("%c", cc[add[i][j]]);
            }puts("");
        }

    }


    return 0;
}

