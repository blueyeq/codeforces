#include<iostream>
#include<stdio.h>
#include<queue>
#include <algorithm>
#include<string.h>
using namespace std;
#define N 200000
char s1[N],s2[N];
long long w[N];
int main()
{
    while(gets(s1))
    {
        int n=0;
        gets(s2);
        for(long long i=0;i<1000;i++) w[i]=0;
        for(long long i=0;s1[i];i++)
            w[s1[i]]++;
        priority_queue <long long, vector<long long> , greater<long long> > q;
        sort(w, w + 300);
        for(long long i=0;i<1000;i++)
            if(w[i]!=0)
            {
                q.push(w[i]);n++;
//                cout<<w[i]<<' ';
            }
//        puts("");
//        cout<<q.top()<<endl;
        long long l=strlen(s2);
        int h=n;
        while(h>l)
        {
            h-=(l-1);
        }
        long long ans=0,ww;
        while(1)
        {
            bool flag=0;
            ww=0;
            for(long long i=0;i<h;i++)
            {
                if(q.empty())
                {
                    flag=1;
                    break;
                }
                ww+=q.top();
                q.pop();
            }
            h=l;
            ans+=ww;
//            cout<<"w="<<ww<<endl;
            if(q.empty()||flag) break;
            q.push(ww);
        }
        cout<<ans<<endl;
    }
    return 0;
}
