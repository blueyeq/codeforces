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
const int INF = 0;

int h[MAXN];

int main(){

    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 1;i <= 2 * n + 1; ++i)  scanf("%d", h + i);
        for(int i = 2; i < 2 * n + 1 && m > 0; ++i){
            if(h[i] - 1 > h[i - 1] && h[i] - 1 > h[i + 1])  {
                --h[i]; --m;
            }
        }
        for(int i = 1; i <= 2 * n + 1; ++i) {
            if(i == 2 * n + 1)  printf("%d\n", h[i]);
            else  printf("%d ", h[i]);
        }
    }



    return 0;
}

