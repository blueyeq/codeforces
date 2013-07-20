#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 110;
const int INF = 1000000000;

int n, m;
vector<int> g[MAXN];

void readin(){
    for(int i = 1; i <= n;++i)  g[i].clear();
    for(int j = 0; j < m; ++j){
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        g[ta].push_back(tb);
        g[tb].push_back(ta);
    }
}
void bfs(int s, int dis[], double path[]){

    queue<int> q;
    q.push(s);
    dis[s] = 0;
    path[s] = 1.0;
    while(!q.empty()){
        int u = q.front();  q.pop();
        for(int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                path[v] = path[u];
                q.push(v);
            }else if(dis[v] == dis[u] + 1){
                path[v] += path[u];
            }
        }
    }
}
double paths[MAXN], patht[MAXN];
int ds[MAXN], dt[MAXN];

void slove(){
    memset(ds, -1, sizeof(ds));
    memset(dt, -1, sizeof(dt));
    memset(paths, 0, sizeof(paths));
    memset(patht, 0, sizeof(patht));
    bfs(1, ds, paths);
    bfs(n, dt, patht);
    double sum = ds[n];
    double Max = max(paths[n], patht[1]);

//    printf("%lf  %lf\n", paths[n], patht[1]);
    for(int i = 1; i <= n; ++i)
    {
        if(ds[i] + dt[i] != ds[n] || i == 1 )  continue;
        double tmp(0.0);
        for(int j1 = 0; j1 < g[i].size(); ++j1){
            for(int j2 = 0; j2 < g[i].size(); ++j2){
                int u = g[i][j1], v = g[i][j2];
                if(ds[u] + dt[v] + 2 == ds[n]){
                    tmp += 2.0 * paths[u] * patht[v];
                }
            }
        }
//        double tmp(0.0);
//        for(int j1 = 0; j1 < g[i].size(); ++j1){
//            int u = g[i][j1];
//            if(ds[u] + dt[i] + 1 == ds[n])  tmp += 1.0 * paths[u] * patht[i];
//        }
        if(tmp > Max) Max = tmp;
//        printf("%d  %lf  %lf\n", i, tmp, Max);
    }
//    printf("%d  %lf  %lf\n", ds[n], paths[n], Max);
    printf("%.6lf\n", Max / paths[n]);
}
int main(){
//    freopen("C.in" , "r", stdin);
    while(~scanf("%d%d", &n, &m)){
        readin();
        slove();
    }


    return 0;
}

