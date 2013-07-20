#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int ptr1, ptr2, len;
char str[10000];

typedef struct MyAdd
{
    int n;
    bool flag;
}ADD;
ADD add[1100];

bool cmp1  (const ADD a, const ADD b)
{
    if(a.n != b.n) return a.n < b.n;
    return a.flag == true;
}
typedef struct MySub
{
    int n;
    bool flag;
}SUB;
SUB sub[1100];

bool cmp2 (const SUB a, const SUB b)
{
    if(a.n != b.n)  return a.n > b.n;
    return a.flag == false;
}

int get_unit_a(int k)
{
    if(str[k] >= '0' && str[k] <= '9')
    {
        int t = str[k++] - '0';
        while(str[k] != '*' && k < len)   t = t * 10 + str[k++] - '0';
        ++k;
        add[ptr1].n = t;
        if(str[k] == '+')
        {
            add[ptr1++].flag = true;
        }
        else  add[ptr1++].flag = false;
        return k + 3;
    }
    else if(str[k] == 'a')
        add[ptr1].flag = false;
    else
        add[ptr1].flag = true;
    add[ptr1++].n = 1;
    return k + 3;
}

int get_unit_b(int k)
{
    if(str[k] >= '0' && str[k] <= '9')
    {
        int t = str[k++] - '0';
        while(str[k] !=  '*' && k < len)    t = t * 10 - str[k++] - '0';
        ++k;
        sub[ptr2].n = t;
        if(str[k] == 'a')   sub[ptr2++].flag = false;
        else   sub[ptr2++].flag = true;
        return  k + 3;
    }
    else if(str[k] == 'a')
        sub[ptr2].flag = false;
    else sub[ptr2].flag = true;

    sub[ptr2++].n = 1;
    return k + 3;
}
int main()
{
    long long now;
    scanf("%lld",&now);
    scanf("%s",str);
    len = strlen(str);
    ptr1 = 0;  ptr2 = 0;

    for(int i = 0; i < len;)
    {
        if(i == 0)
            i = get_unit_a(0);
        else if(str[i] == '+')
            i = get_unit_a(i+1);
        else
            i = get_unit_b(i+1);
    }

    sort(add,add+ptr1,cmp1);
    sort(sub,sub+ptr2,cmp2);

    long long res(0);
    for(int i = 0; i < ptr2; ++i, now++)
    {
        if(sub[i].flag)   res -= sub[i].n * (now+1);
        else  res -= sub[i].n * now;
       // cout<<sub[i].n<<"  "<<sub[i].flag<<"  "<<now<<endl;
    }

    for(int i = 0; i < ptr1; ++i, now++)
    {
        if(add[i].flag) res += add[i].n * (now+1);
        else  res += add[i].n * now;
       // cout<<add[i].n<<"  "<<add[i].flag<<"  "<<now<<endl;
    }
    printf("%lld\n",res);
    return 0;
}
