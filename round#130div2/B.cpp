#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 100;
const int INF = 1000000000;

char s[100][2];
bool vis[MAXN][MAXN][MAXN], dp[MAXN][MAXN][MAXN];

bool dfs(int x, int k1, int k2){
    if(x == 1)  return 1;

    if(vis[x][k1][k2])  return dp[x][k1][k2];
    vis[x][k1][k2] = 1;
    if(s[k1][0] == s[k2][0] || s[k1][1] == s[k2][1]){
        if(dfs(x - 1, k1, x - 2))  return dp[x][k1][k2] = 1;
    }
    if(k1 > 2 && (s[k1][0] == s[x - 2][0] || s[k1][1] == s[x - 2][1])){
        if(dfs(x - 1, k2, k1))  return dp[x][k1][k2] = 1;
    }
    if(k1 > 2 && (s[k1][0] == s[k2][0] || s[k1][1] == s[k2][1]) && (s[k2][0] == s[x - 2][0] || s[k2][1] == s[x - 2][1])){
        if(dfs(x - 2, k1, x - 3))  return dp[x][k1][k2] = 1;
    }
    return dp[x][k1][k2] = 0;
}


int main(){
//    freopen("B.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++i) scanf("%s", s[i]);
        if(dfs(n, n, n - 1))  puts("YES");
        else puts("NO");
    }


    return 0;
}

