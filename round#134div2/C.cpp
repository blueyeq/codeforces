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

int fa[MAXN];

int find(int x){
    if(fa[x] == x)  return x;
    return fa[x] = find(fa[x]);
}
int px[MAXN], py[MAXN];

int main(){

    int n;
    while(~scanf("%d", &n)){

        for(int i = 0; i < n; ++i)  fa[i] = i;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", px + i, py + i);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(px[i] == px[j] || py[i] == py[j]) {
                    fa[find(i)] = find(j);
                }
            }
        }
        int cnt(0);
        for(int i = 0; i < n; ++i)  cnt += fa[i] == i;
        printf("%d\n", cnt - 1);
    }



    return 0;
}

