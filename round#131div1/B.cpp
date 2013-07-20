#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const LL mod = 1000000007LL;

LL fact[2000], C[300][300];
int n, sum;
int num[30];

void readin(){

    sum = 0;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &num[i]);
        sum += num[i];
    }
//    printf(":%d  %d\n", n,  sum);
    for(int i = 0; i < 200; ++i){
        fact[i] = i ? fact[i - 1] * 10 : 1;
        fact[i] %= mod;
    }
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= 200; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}
LL p[20];
LL get(int len){

    for(int i = 0; i <= 10; ++i){

        p[i] = 0;
        for(int j = 0; j < num[i]; ++j){
            p[i] += C[len][j] * fact[len - j] % mod;
            p[i] %= mod;
        }
    }
    LL res = fact[len];
    for(int i = 1; i < (1<<10); ++i){

        int cnt(0);
        LL tmp(1);
        for(int j = 0; j < 10; ++j){
            if(i & (1<<j)){
                tmp *= p[j];
                tmp %= mod;
                ++cnt;
            }
        }
        if(cnt & 1)  res -= mod;
        else res += mod;
        res = (res % mod + mod) % mod;
    }
    res = (res % mod + mod) % mod;
//    printf("res: %I64d\n", res);
    return res;
}

LL slove(){

    LL res(0);
//    printf("%d  %d\n", n, sum);
    for(int i = n; i >= sum && i > num[0]; --i){
        for(int j = 1; j < 10; ++j){
            --num[j];
            res += get(i);
            ++num[j];
        }
    }
    return res;
}

int main(){

    freopen("B.in", "r", stdin);
    while(~scanf("%d", &n)){
//        printf("%d\n", n);
        readin();
//        printf("n: %d\n", n);
        printf("%I64d\n", slove());
    }



    return 0;
}

