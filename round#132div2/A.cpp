#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 100;

int a[MAXN], b[MAXN];

int main(){

    int n, m;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i)  scanf("%d", a + i);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)  scanf("%d", b + i);
        int Max(0), cnt;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(b[j] % a[i] == 0){
                    int t = b[j] / a[i];
                    if(t > Max){
                        Max = t; cnt = 1;
                    }else if(t == Max){
                        ++cnt;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }


    return 0;
}

