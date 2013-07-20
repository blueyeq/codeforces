#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 110000;
const int INF = 0;

int main(){

    int n;
    LL m, t, T, x, cost;
    while(~scanf("%d%I64d", &n, &m)){
        LL ans(0);
        for(int i = 0; i < n; ++i){

            scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
            if(T <= t){
                ans += cost + m * x;
            }else {

                LL cnt = T - t;
                if(x * cnt < cost || m <= cnt){
                    ans += cost;
                    if(m > cnt)  ans += m * x;
                }else {
                    LL k = m / cnt;
                    LL lt = m % cnt;
                    ans += cost * k;
                    if(m > cnt && lt) ans += min(cost, (lt + cnt) * x);
                }
            }
//            printf("ans: %I64d\n", ans);
        }
        printf("%I64d\n", ans);
    }



    return 0;
}

