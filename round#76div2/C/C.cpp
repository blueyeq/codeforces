#include<iostream>
using namespace std;
int main()
{
int n,m,a,b;
cin>>n>>m>>a>>b;
if((b-1)/m-(a-1)/m==0)
{
cout<<1;
}
else if((b-1)/m-(a-1)/m==1)
{
if((a-1)%m==0 && (b%m==0 || b==n)) cout<<1;
else cout<<2;
}
else
{
if(a!=1 && (a-1)%m==b%m) cout<<2;
else cout<<1+bool((a-1)%m)+(bool(b%m) && b!=n);
}
return 0;
}
