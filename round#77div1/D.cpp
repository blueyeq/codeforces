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
int mode;
LL dfs(int k, int need, int fg1, int fg2){

    if(need < 0)  need = 0;
    if(k == -1){
        return fg2;
    }

    if(!fg1 && f[k][need][fg2] != -1)
        return f[k][need][fg2];
    if(fg1 && dp[k][fg2][need] != -1)  return dp[k][fg2][need];

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
    }

    ret %= mod;
    if(!fg1)  f[k][need][fg2] = ret;
    else dp[k][fg2][need] = ret;
    return ret;
}

char A[MAXN], B[MAXN];
int ok(char *s){

    int n = strlen(s), pre(-100000);
    for(int i = 0; i < n; ++i)  {
        if(s[i] == '4' || s[i] == '7')  {
            if(i - pre <= dis)  return 1;
            pre = i;
        }
    }
    return 0;
}
LL get(char *s){

    strcpy(dig, s);
    int n = strlen(s);
    reverse(dig, dig + n );
    LL ret(0);

    int pre(0), fg(0);

    for(int k = n - 1; k >= 1; --k){

        for(int i = '0'; i < dig[k]; ++i){
            if(fg)  {
                ret += f[k - 1][dis + 1][1];
            }else if(i == '4' || i == '7'){

                if(pre > 0)  ret += f[k - 1][dis + 1][1];
                else  ret += f[k - 1][dis][0];
            }else{

                ret += f[k - 1][pre][0];
            }
//            if(k >= 0)  printf("ret: %d %c  %c %I64d\n", k, i, dig[k], ret);
        }
        if(!fg){

            if(dig[k] == '4' || dig[k] == '7') {
                if(pre > 0)  fg = 1;
                else  pre = dis - 1;
            }
            else pre = max(0, pre - 1);
        }
        else pre = dis + 1;
        ret %= mod;
//        printf("%d %I64d\n", k, ret);
    }
//    --dig[0];
//    while(dig[0] >= '0') {
//        ret += ok(dig);
//        --dig[0];
//    }
    return ret  % mod;
}

void init(){

    memset(f, -1, sizeof(f));
    for(int i = 0; i <MAXN; ++i)  dig[i] = '9';
    dfs(1001, 0, 0, 0);
}
int main(){

    freopen("D.in", "r", stdin);
    int test;

    scanf("%d%d", &test, &dis);
    init();
    while( test-- ){

        scanf("%s%s", A, B);

        printf("%I64d\n", (  get(B) - get(A) + ok(B)  + mod) % mod );

    }
    return 0;
}

