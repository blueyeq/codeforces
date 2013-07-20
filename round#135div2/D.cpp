#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 300000;
const int MAXM = 6000000;
const int INF = 1000000000;


int n, e_cnt;
int head[MAXN];

struct Edg{
    int v, next, typ;
}edg[MAXM];

inline void add(int a, int b, int typ){
    edg[e_cnt].v = b; edg[e_cnt].next = head[a]; edg[e_cnt].typ = typ; head[a] = e_cnt++;
}
int sum[MAXN];

void dfs1(int x, int f){

    sum[x] = 0;
    for(int i = head[x]; i != -1; i = edg[i].next){
        int v = edg[i].v;
        if(v == f)  continue;
        dfs1(v, x);
        sum[x] += sum[v] + (edg[i].typ == 0);
    }
//    printf("s: %d %d\n", x, sum[x]);
}
int val[MAXN], ans;

void dfs2(int x, int f, int typ){
    if(f == -1)  val[x] = sum[x];
    else  {
        val[x] = val[f];
        if(typ == 1)  ++val[x];
        else  --val[x];
    }
    ans = min(ans, val[x]);
    for(int i = head[x]; i != -1; i = edg[i].next){
        int v = edg[i].v;
        if(v != f)  dfs2(v, x, edg[i].typ);
    }
//    printf("v: %d %d\n", x, val[x]);
}


void readin(){
    e_cnt = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b, 1);
        add(b, a, 0);
    }
}
int b[MAXN];
int main(){

//    freopen("D.in", "r", stdin);
    while(~scanf("%d", &n)){
        readin();
        ans = n - 1;
        dfs1(1, -1);
        dfs2(1, -1, 0);
        int cnt = 0;
        for(int i = 1; i <= n; ++i)  if(ans == val[i])  b[cnt++] = i;
        printf("%d\n", ans);
        for(int i = 0; i < cnt; ++i){
            if(i == cnt - 1)  printf("%d\n", b[i]);
            else  printf("%d ", b[i]);
        }
    }



    return 0;
}

