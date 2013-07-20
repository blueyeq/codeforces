#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
int n;
map<int, int> mymap1;
map<int, int> mymap2;
map<int,int> cnt;
map<int,int> mymap3;
int main()
{
    int start, x, y;
    int num(0);
    while(cin>>n)
    {
         mymap1.clear();   mymap2.clear();  cnt.clear();        
         for(int i = 0; i != n; ++i)
         {
             cin>>x>>y;
             if(mymap1.find(x) == mymap1.end()) mymap1[x] = y;
             else   mymap2[x] = y;
             
             if(mymap1.find(y) == mymap1.end()) mymap1[y] = x;
             else mymap2[y] = x;
             
             if(cnt.find(x) == cnt.end()) { cnt[x] = 1;   mymap3[num++] = x;} 
             else cnt[x] = 2;
             
             if(cnt.find(y) == cnt.end()) { cnt[y] = 1;   mymap3[num++] = y;}
             else cnt[y] = 2; 
         }
         for(int i = 0; i != n; ++i)
         {
             if(cnt[mymap3[i]] == 1) 
             {
                start = mymap3[i];
                break;
             }
         }
         int vis = 0, now(start), father(-1);
         while(vis < n)
         {
             cout<<now<<" ";
             if(mymap1[now] != father) 
             {
                 father = now;
                 now = mymap1[now];
             }       
             else 
             {
                 father = now;
                 now = mymap2[now];
             }
             ++vis;
         }
         cout<<now<<endl;
    }
    return 0;
}