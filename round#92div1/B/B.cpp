#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
typedef long long LL;
LL abs(LL x) {return x >= 0 ? x : -x;}
LL max(LL a, LL b) {return a > b ? a : b;}
int main()
{
    LL a, b, px1, py1, px2, py2;
    while(cin>>a>>b>>px1>>py1>>px2>>py2)
    {
        LL t = px1 + py1;
        if(t >= 0)  t += 2 * a - 1;
        LL ppx1 = t / (2 * a);

        t = px2 + py2 ;
        if(t >= 0) t += 2 * a - 1;
        LL ppx2 = t / (2 * a);
        t = px1 - py1;
        if(t >= 0)  t += 2 * b - 1;
        LL ppy1 = t / (2 * b);
        t = px2 - py2;
        if(t >= 0)  t += 2 * b - 1;
        LL ppy2 = t / (2 * b);

        LL t1 = abs(ppx1 - ppx2);
        LL t2 = abs(ppy1 - ppy2);
        //printf("%I64d  %I64d  %I64d  %I64d  \n", ppx1, ppy1, ppx2, ppy2);
        LL ans = t1 + t2 - min(t1, t2);
        cout<<max(t1, t2)<<endl;
    }
    return 0;
}
