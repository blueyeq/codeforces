#include<iostream>
using namespace std;
#include<stdio.h>
#define N 200000
#define LL long long
struct edge
{
    LL v,next;
    edge(){}
    edge(LL v,LL next):v(v),next(next){}
}e[N];
LL first[N],cnt,n,k;
LL opt[1000],ans;
inline void add(LL u,LL v)
{
    e[cnt]=edge(v,first[u]);
    first[u]=cnt++;
}
LL dfs(LL u,LL *best,LL f)
{
    LL cur[1000];
    for(LL i=0;i<=k;i++)
        cur[i]=0;
//    cur[0]=1;
    for(LL i=first[u];i!=-1;i=e[i].next)
    {
        LL v=e[i].v;
        if(v==f) continue;
        dfs(v,cur,u);
    }
//    for(LL i=k;i>=2;i--)
//        ans+=best[k-i];
    if(k>=2)
        ans+=best[k-2];
    for(LL i=1;i<=k;i++)
        best[i]+=cur[i-1];
    best[0]++;
    ans+=best[k];
//    for(LL i=0;i<=k;i++)
//        printf("%I64d i=%I64d %I64d %I64d\n",u,i,cur[i],best[i]);
}
int main()
{
//    freopen("1.txt","r",stdin);
    while(scanf("%I64d%I64d",&n,&k)!=-1)
    {
        LL u,v;
        cnt=0;
        for(LL i=0;i<=n;i++) first[i]=-1;
        for(LL i=1;i<n;i++)
        {
            scanf("%I64d%I64d",&u,&v);
            add(u,v);
            add(v,u);
        }
        //opt[0]=1ll;
        for(LL i=0;i<=k;i++)opt[i]=0ll;
        ans=0;
        dfs(1,opt,-1);
        printf("%I64d\n",ans);
    }
}
