#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 1010;
const LL mod = 1000000007;
const int INF = 0;

char dig[MAXN];

LL dp[MAXN][2][MAXN], f[MAXN][MAXN][2];
int dis;

LL dfs(int k, int need, int fg1, int fg2){

    if(need < 0)  need = 0;
    if(k == -1){
        return fg2;
    }

    if(!fg1 && f[k][need][fg2] != -1)  return f[k][need][fg2];
//    if(fg1 && dp[k][fg2][need] != -1)  return dp[k][fg2][need];

    LL ret = 0;
    int Max = fg1 ? dig[k] - '0' : 9;

    for(int i = 0; i <= Max; ++i){

        int nf = fg2;
        int nn = need - 1;

        if(i == 4 || i == 7){
            if(need > 0)  nf = 1 ;
            if(!nf)  nn = dis;
        }
        if(nf)  nn = dis + 1;

        ret += dfs(k - 1, nn, fg1 && (i == Max),  nf) ;
//        ret %= mod;
//        if(ret < 0)  puts("error");
    }

    ret %= mod;
    if(!fg1)  f[k][need][fg2] = ret;
//    else dp[k][fg2][need] = ret;
    return ret;
}

char A[MAXN], B[MAXN];

LL get(char *s){

//    memset(dp, -1, sizeof(dp));
    strcpy(dig, s);
    reverse(dig, dig + strlen(dig));
    LL ret = dfs(strlen(dig) - 1, 0, 1, 0);
//    printf("%s  %I64d\n", s, ret);
    return ret;
}
int ok(char *s){

    int n = strlen(s), pre(-100000);
//    printf("%s %d\n", s, n);
    for(int i = 0; i < n; ++i)  {
        if(s[i] == '4' || s[i] == '7')  {
            if(i - pre <= dis)  return 1;
            pre = i;
        }
    }
    return 0;
}
void init(){

    memset(f, -1, sizeof(f));
    for(int i = 0; i <MAXN; ++i)  dig[i] = '9';
    dfs(1001, 0, 0, 0);
}
int main(){
    int test;
    scanf("%d%d", &test, &dis);
    init();
    while( test-- ){

        scanf("%s%s", A, B);

        printf("%I64d\n", (  get(B) - get(A) + ok(A) + mod) % mod );

    }
    return 0;
}
