#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 1100;
const int INF = 0;

int a[MAXN], b[MAXN];

int main(){

    int n, m;
    while(~scanf("%d%d", &n, &m)){
        int i;
        for(  i = 0; i < m; ++i)  scanf("%d", a + i), b[i] = a[i];

        int Max(0), Min(0);
        for(int k = 0; k < n; ++k){

            int Min_i(-1), Max_i(-1);
            for(int i = 0; i < m; ++i){
                if(a[i] > 0){
                    if(Max_i == -1 || a[i] > a[Max_i])  Max_i = i;
                }
                if(b[i] > 0){
                    if(Min_i == -1 || b[i] < b[Min_i])  Min_i = i;
                }
            }
            Max += a[Max_i]--;
            Min += b[Min_i]--;
        }
        printf("%d %d\n", Max, Min);
    }


    return 0;
}

