#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

const int MAXN = 1100;
int n, m, q;

struct P
{
    int nam, num;
    int typ[5];
    void out()
    {
        printf("%d %d  ", nam, num);
        for(int i = 0; i < num; ++i)  printf("%d ", typ[i]);
        puts("");
    }
}pgm[MAXN];

int getTyp(string s)
{
    if(s == "int")  return 0;
    if(s == "double")  return 1;
    if(s == "string")  return 2;
    if(s == "T")  return 3;
    return -1;
}

int ID;
map<string, int> mp, vvar;

void init()
{
    ID = 0;
    mp.clear();
    vvar.clear();
}
int getIndex(string s)
{
    if(mp.find(s) == mp.end())  mp[s] = ID++;
    return mp[s];
}

char ps[10000];
int pps(char *s)
{
    int cnt(0), len = strlen(s), par(1);
    for(; *s; ++s)
    {
        if(*s == ',' || *s == '(' || *s == ')')  ps[cnt++] = ' ';
        else  ps[cnt++] = *s;

        if(*s == ',') ++par;
    }
    ps[cnt] = 0;
//    printf("%s\n", ps);
    return par;
}
void makepg(char *s, int id)
{
    istringstream in(s);
    string str;
    in>>str;
    in>>str;
    pgm[id].nam = getIndex(str);
    pgm[id].num = 0;
    while(in>>str)
    {
        pgm[id].typ[pgm[id].num++] = getTyp(str);
    }
}
void makecall(char *s)
{
    istringstream in(s);
    string str;
    in>>str;
    pgm[n].nam = getIndex(str);
    pgm[n].num = 0;
    while(in>>str)
        pgm[n].typ[pgm[n].num++] = vvar[str];
}
bool equ(int id1, int id2)
{
    if(pgm[id1].nam != pgm[id2].nam) return 0;
    if(pgm[id1].num != pgm[id2].num) return 0;
    for(int i = 0; i < pgm[id1].num; ++i)
        if(pgm[id1].typ[i] != 3 && pgm[id2].typ[i] != 3
           && pgm[id1].typ[i] != pgm[id2].typ[i])  return 0;
    return 1;
}
char  str[10000];
int main()
{
//    freopen("D.in", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        init();
        getchar();
        for(int i = 0; i < n; ++i)
        {
            gets(str);
            pps(str);
            makepg(ps, i);
//            pgm[i].out();
        }
        scanf("%d", &m);  getchar();
        for(int i = 0; i < m; ++i)
        {
            gets(str);
            istringstream in(str);
            string s1, s2;
            in>>s1>>s2;
            vvar[s2] = getTyp(s1);
        }
        scanf("%d", &q);  getchar();
        for(int i = 0; i < q; ++i)
        {
            gets(str);
            pps(str);
            makecall(ps);
            int res(0);
//            pgm[n].out();
            for(int i = 0; i < n; ++i)
                res += equ(i, n);
            printf("%d\n", res);
        }
    }
    return 0;
}

