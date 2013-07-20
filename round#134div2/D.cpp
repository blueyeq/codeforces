#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 5000000;
int n;
int op[MAXN];

bool dfs(int k, int a, int b){
    if(k == 1){
        return a == 1 && b == 1;
    }
    if(k <= 0 || a <= 0 || b <= 0 || a == b)  return 0;

    if(a > b){
        int tmp = a / b;
        if(a % b == 0)  --tmp;
        if(dfs(k - tmp, a - tmp * b, b)){
            for(int i = k; i > k - tmp; --i)  op[i - 1] = 0;
            return 1;
        }
    }else{
        int tmp = b / a;
        if(b % a == 0)  --tmp;
        if(dfs(k - tmp, a, b - tmp * a)){
            for(int i = k; i > k - tmp; --i)  op[i - 1] = 1;
            return 1;
        }
    }
    return 0;
}
char s[] ={'T', 'B'};
int ans[MAXN];

int main(){

    int r;
    while(~scanf("%d%d", &n, &r)){

         int fd(0), res(n + 1);
         for(int i = r; i >= 1; --i){
            if(dfs(n, i, r)){
                fd = 1;
                op[0] = 0; int tmp = 0;
                if(n > 1 && op[1] == 0){
                    for(int i = 1; i < n; ++i)  op[i] = !op[i];
                }
                for(int i = 1; i < n; ++i){
                    if(op[i] == op[i - 1])  ++tmp;
                }
                if(res > tmp){
                    for(int i = 0; i  < n; ++i)  ans[i] = op[i];
                    res = tmp;
                }
            }
         }
         if(fd){

            printf("%d\n", res);
            for(int i = 0; i < n; ++i){
                printf("%c", s[ans[i]]);
            }
            puts("");
         }else puts("IMPOSSIBLE");
    }



    return 0;
}

