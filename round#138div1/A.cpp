#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 110000;
const int INF = 0;

char s[MAXN], ans[MAXN], tmp[MAXN];
inline int get(char c){

    if(c == '(') return 1;
    if(c == ')') return 2;
    if(c == '[') return 3;
    if(c == ']') return 4;
}
int st[MAXN], sz[5];
int  top, id[MAXN];
bool flag[MAXN];

int main(){

//    freopen("A.in", "r", stdin);
    while(~scanf("%s", s)){

        int res(0);
        int n = strlen(s);
        int top(0), tmp(0), ansl(100), ansr(-1), tl, tr;
        id[top] = 0; st[top] = -1;
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < n; ++i){

            int c = get(s[i]);

            if(c == 1 || c == 3) {
//                ++sz[c];
                st[++top] = c;
                id[top] = i;
            }
            else{
//                printf("%d %d\n", c, st[top]);
                if(c == 2 && top > 0 &&  st[top] == 1)   {
                    flag[id[top]] = flag[i] = 1;
                    --top;
                }
                else if(c == 4 && top > 0 && st[top] == 3)  {
                    flag[id[top]] = flag[i] = 1;
                    --top;
                }
                else {
                    tmp = top = 0;
                    id[top] = i + 1;
//                    memset(sz, 0, sizeof(sz));
                }

//                printf("%d  %d %d  %d  %d\n",i, top, tmp, ansl, ansr);
            }
        }
        for(int i = 0; i < n; ++i){

            int j = i;  tmp = 0;
            while(flag[j] && j < n){
                if(s[j] == '[') ++tmp;
                ++j;
            }
            if(tmp > res){
                ansl = i;  ansr = j - 1;
                res = tmp;
            }
            i = j;
        }
        printf("%d\n", res);
        for(int i = ansl; i <= ansr; ++i)
            printf("%c", s[i]);
        puts("");


    }



    return 0;
}

