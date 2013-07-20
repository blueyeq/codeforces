#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 800100;
const int INF = 0;

int n, m;
int ansl[MAXN], ansr[MAXN], ll[MAXN], rr[MAXN];


void build(int id, int lt, int rt)
{
    ansl[id] = rr[id] = lt;  ansr[id] = ll[id] = rt;
    if(lt == rt)  return;
    int mid = (lt + rt) >> 1;
    build(id<<1, lt, mid);
    build((id<<1) | 1, mid + 1, rt);
}

inline int getLen(int lt, int rt){
    if(lt > rt)  return -1000;
    int len = rt - lt;
    if(lt == 1 || rt == n)  len <<= 1;
    return len / 2;
}

inline void up(int id, int lc, int rc, int lt, int rt){

    int mid = (lt + rt) >> 1;
    int l1 = getLen(ansl[lc], ansr[lc]);
    int l2 = getLen(ansl[rc], ansr[rc]);
    int l3 = getLen(rr[lc], ll[rc]);
    if(rr[lc] > mid || ll[rc] <= mid )  l3 = -1000;
    if(l1 >= l2 && l1 >= l3 )  {
        ansl[id] = ansl[lc]; ansr[id] = ansr[lc];
    }else  if(l2  > l3 ){
        ansl[id] = ansl[rc]; ansr[id] = ansr[rc];
    }else{
        ansl[id] = rr[lc];  ansr[id] = ll[rc];
    }
    if( l1 >= 0)    ll[id] = ll[lc] == mid ? ll[rc] : ll[lc];
    else  ll[id] = lt - 1;
    if(l2 >= 0)  rr[id] = rr[rc] == mid + 1 ? rr[lc] : rr[rc];
    else  rr[id] = rt + 1;
}

void ins(int id, int lt, int rt, int p, int e){

    if(p < lt || p > rt)  return;
    if(lt == rt){
        ansl[id] = rr[id] = lt + e;
        ansr[id] = ll[id] = lt - e;
        return;
    }
    int lc(id<<1), rc((id<<1) | 1), mid = (lt + rt) >> 1;

    ins(lc, lt, mid, p, e);
    ins(rc, mid + 1, rt, p, e);
    up(id, lc, rc, lt, rt);
}

int pos[MAXN * 10];

int main(){

//    freopen("E.in", "r", stdin);
    while(~scanf("%d%d", &n, &m)){

        build( 1, 1, n );
        for(int i = 0; i < m; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            int id = b ;

            if(a == 1){
                int p = (ansr[1] - ansl[1] ) / 2 + ansl[1];

                if(ansr[1] == n)  p = n;
                if(ansl[1] == 1)  p = 1;
                pos[id] = p;
                ins( 1, 1, n, p, 1);
                printf("%d\n", p);
            }else{
                ins( 1, 1, n, pos[id], 0);
            }
        }
    }
    return 0;
}

