#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 510000;
const int INF = 1000000000;

int n, m;
int dp[MAXN][26];
int mp[300];
int Min1[MAXN], Min2[MAXN], src1[MAXN], src2[MAXN];

char s[MAXN];

void init(){
    for(int i = 0; i < 26; ++i)  mp[i + 'A'] = i;
}
void check(int &a, int b){
    if(a > b) a = b;
}

void slove(){
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < m; ++j)
            dp[i][j] = INF;
        Min1[i] = Min2[i] = INF;
    }

    Min1[0] = Min2[0] = 0;  src1[0] = 0; src2[0] = 1;
    for(int i = 1; i <= n; ++i){

        for(int j = 0; j < m; ++j){
            int d = ( mp[ s[i] ] != j);
            if(src1[i - 1] != j)
                check(dp[i][j], Min1[i - 1] + d);
            else
                check(dp[i][j], Min2[i - 1] + d);
//            if(i == 3 && j == 1){

//                printf("%d  %d  %d  %d  %d  %c  %d\n", i, j, dp[i][j], d, mp[s[i]], s[i], Min2[i - 1] );
//            }
        }

        for(int j = 0; j < m; ++j){

            if(Min1[i] > dp[i][j]){
                Min2[i] = Min1[i];
                src2[i] = src1[i];
                Min1[i] = dp[i][j];
                src1[i] = j;

            }else if(Min2[i] > dp[i][j]){
                Min2[i] = dp[i][j];
                src2[i] = j;
            }
        }
    }
    printf("%d\n", Min1[n]);
    int now = src1[n];
    for(int i = n; i >= 1; --i){
        int d = (mp[s[i]] != now);
        if(src1[i - 1] != now && dp[i][now] == Min1[i - 1] + d){
            s[i] = now + 'A';
            now = src1[i - 1];
        }else {
            s[i] = now + 'A';
            now = src2[i - 1];
        }
    }
    printf("%s\n", s + 1);
}

int main(){

//    freopen("C.in", "r", stdin);
    init();
    while(~scanf("%d%d", &n, &m)){

        scanf("%s", s + 1);
        slove();

    }



    return 0;
}

