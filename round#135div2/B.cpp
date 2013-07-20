#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 30;
const int INF = 0;

LL fact[MAXN];

void init(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i)  fact[i] = fact[i - 1] * 10;
}

int dig[MAXN];
void slove(LL x, LL d){
    int len(0);
    while(x){
        dig[len++] = x % 10;
        x /= 10;
    }
    LL ans(0);
    int fg(0);
    for(int i = 0; i < len; ++i){
        if(d >= ( 9 - dig[i])  * fact[i]){
            d -= (9 - dig[i]) * fact[i];
            ans += 9 * fact[i];
            if(dig[i] != 9)  fg = 1;
        }else{
            if(dig[i])  {
                if(fg)  --dig[i], fg = 0;
                ans += dig[i] * fact[i];
            }
        }
    }
    printf("%I64d\n", ans);
}
int main(){

//    freopen("B.in", "r", stdin);
    init();
    LL a, b;
    while(~scanf("%I64d%I64d", &a, &b)){

        LL ans(a);
        for(int i = 1; fact[i] <= a && i <= 18; ++i){
            LL hig = (a / fact[i])* fact[i];
            LL low = fact[i] - 1;
            while(hig + low > a && hig > 0)  hig -= fact[i];
            if(hig + low <= a &&  a - hig - low <= b)  ans = hig + low;
//            printf("%d :%I64d  %I64d\n", i, hig + low, a - hig - low);
        }
        printf("%I64d\n", ans);
//        slove(a, b);

    }



    return 0;
}

