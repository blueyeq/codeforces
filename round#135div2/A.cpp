#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 10000;
const int INF = 0;

int num[300];
char s[MAXN];

int main(){

//    freopen("A.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){

        scanf("%s", s);
        memset(num, 0, sizeof(num));
        int len = strlen(s);
        for(int i = 0; i < len; ++i){
            ++num[s[i]];
        }
        int fg(1);
        for(int i = 'a'; i <= 'z'; ++i){
            if(num[i] == 0)  continue;
            if(num[i] % n)  fg = 0;

        }
        if(!fg){
            puts("-1") ; continue;
        }
        for(int j = 0; j < n; ++j)
        for(int i = 'a'; i <= 'z'; ++i){
//            printf("\n%c %d\n", i, num[i]);
            if(num[i] <= 0) continue;
            for(int k = 0; k < num[i] / n; ++k) printf("%c", i);
        }
        puts("");
    }




    return 0;
}

