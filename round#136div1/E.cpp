#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 1010000;
const int INF = 0;

int n;
LL C[MAXN], C2[MAXN];

void add(int p, LL x){
    while(p <= n){
        C[p] += x;
        p += p & (-p);
    }
}

LL get(int p){
    LL res(0);
    while(p){
        res += C[p];
        p -= p & ( -p );
    }
    return res;
}
void add2(int p, LL x){
    while(p <= n){
        C2[p] += x;
        p += p & (-p);
    }
}

LL get2(int p){
    LL res(0);
    while(p){
        res += C2[p];
        p -= p & ( -p );
    }
    return res;
}

LL ele[MAXN], inv[MAXN], b[MAXN];
int cnt;

int getId(LL x){
    return lower_bound(b, b + cnt, x) - b + 1;
}
void slove(LL m){

    cnt = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%I64d", ele + i);
        b[cnt++] = ele[i];
        C[i] = 0;
    }
    sort(b, b + cnt);
    cnt = unique(b, b + cnt) - b;

    LL now(0), ans(0);
    for(int i = n; i >= 1; --i){

        ele[i] = getId( ele[i] ) ;
        add(ele[i], 1);

        inv[i] = get(ele[i] - 1);

        if(i > 1) now += inv[i];
//        printf("%d %d\n", i, inv[i]);
    }

    for(int i = 1; i <= n; ++i)  C[i] = 0;
    memset(C2, 0, sizeof(C2));

    int ptr(2); add2(ele[1], 1);
    for(int i = 1; i < n; ++i){

        now += inv[i] - get2(ele[i] - 1);
        if(ptr == i)  now -= inv[ptr++] - get2(ele[i] - 1);
        if(i != ptr)  now += get(cnt) - get(ele[i]);
        add(ele[i], 1);
        add2(ele[i], -1);

        while(now > m && ptr < n){
            add2(ele[ptr], 1);
            now -= get(cnt)  - get( ele[ptr] );
            now -= inv[ptr++];
        }
        if( ptr <= n && now <= m)  ans += n - ptr + 1;
    }
    printf("%I64d\n", ans);
}



int main(){

//    freopen("std.in", "r", stdin);
    LL m;
    while(~scanf("%d%I64d", &n, &m)){

        slove( m );
    }
    return 0;
}

