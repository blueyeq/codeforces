#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;

const int MAXN = 5100;

double r1[MAXN], p1[MAXN], p2[MAXN];
double A, B;

int main(){

    int n, m, np;
    while(~scanf("%d", &n)){

        for(int i = 0; i < n; ++i)  scanf("%lf", r1 + i);
        scanf("%d", &m);
        double P2(1e20), P1(0);
        for(int i = 0; i < m; ++i)  {
            scanf("%lf", p1 + i);
            P1 = max(P1, p1[i]);
        }
        scanf("%d", &np);
        for(int i = 0; i < np; ++i) {
            scanf("%lf", p2 + i);
            P2 = min(P2, p2[i]);
        }
        scanf("%lf%lf", &A, &B);
        double ans(0.0);
        for(int i = 0; i < n; ++i){
//            for(int j = 0; j < m; ++j){
//                for(int k = 0; k < np; ++k){
                    double C = A / B * P2 / P1;
                    double tmp = sqrt(r1[i] * r1[i] / (1 + C));
                    ans = max(ans, tmp);
//                    printf("%lf  %lf  %lf\n", tmp, P2, P1);
//                }
//            }
        }
        printf("%.7lf\n", ans);
    }



    return 0;
}

