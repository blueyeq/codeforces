#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long LL;
const int MAXN = 100;

LL a[MAXN], cost[10];
LL cnt[10];

int main(){
    int n;
    while(~scanf("%d", &n)){
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i){
            scanf("%I64d", a + i);
        }
        for(int i = 0; i < 5; ++i){
            scanf("%I64d", cost + i);
        }

        LL lt(0);
        for(int i = 0; i < n; ++i){
            lt += a[i];
            for(int j = 4; j >= 0; --j){
                cnt[j] += lt / cost[j];
                lt %= cost[j];
            }
        }
        for(int i = 0; i < 4; ++i)  printf("%I64d ", cnt[i]);
        printf("%I64d\n%I64d\n", cnt[4], lt);
    }


    return 0;
}

