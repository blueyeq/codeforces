#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 210;
const int INF = 1000000000;

int next[4];


int g[MAXN][MAXN], org[MAXN][MAXN];
int c[MAXN], in[MAXN], n;

int cal(int s)
{
    queue<int> q[4];
    memset(in, 0, sizeof(in));
    memset(g, 0, sizeof(g));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            g[i][j] = org[i][j];
            if(g[i][j]) {
                ++in[j];
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!in[i])q[c[i]].push(i);
    }
    int res(0);
    while(1){
        if(q[1].empty() && q[2].empty() && q[3].empty())  break;

        while(!q[s].empty()){

            int u = q[s].front();  q[s].pop();



            for(int i = 1; i <= n; ++i){
                if(g[u][i]) {
                    --in[i];
                    if(!in[i])  q[c[i]].push(i);
                }
            }
        }
        s = next[s];  ++res;
    }
    return res - 1;
}
void readin(){
    for(int i = 1; i <= n; ++i){
        scanf("%d", &c[i]);
    }
    memset(org, 0, sizeof(org));
    for(int i = 1; i <= n; ++i){
        int l;  scanf("%d", &l);
        for(int j = 0; j < l; ++j){
            int a; scanf("%d", &a);
            org[a][i] = 1;
        }
    }
}
void slove(){
    int res = INF;
    for(int i = 1; i <= 3; ++i){
        res = min(res, cal(i));
    }
    printf("%d\n", res + n);
}
int main(){

//    freopen("A.in", "r", stdin);
    next[1] = 2; next[2] = 3; next[3] = 1;
    while(~scanf("%d", &n)){
        readin();
        slove();
    }



    return 0;
}

