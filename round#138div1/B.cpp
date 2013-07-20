#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 410000;
const int INF = 0;

char a[MAXN], b[MAXN];
int pl[MAXN], pr[MAXN];
bool vis1[30], vis2[30];
int sum[210000][26];
int main(){

//    freopen("B.in", "r", stdin);

    while(~scanf("%s%s", a + 1, b + 1)){

        int n1 = strlen(a + 1);
        int n2 = strlen(b + 1);
        a[0] = b[0] = a[++n1] = b[++n2] = '$';
        ++n1, ++n2;
//        printf("%s %s  %d  %d\n", a, b, n1, n2);
        if(n2 > n1){
            puts("No");
            continue;
        }
        memset(pl, 0, sizeof(pl));
		for(int i = 0; i <= n1; ++i)  pr[i] = n1 + 2;  
        for(int i = 0, j = 0; i < n2; ++i){

            while(j < n1 && a[j] != b[i]  ) ++j;
            if(j < n1) pl[j++] = i;
            else  break;
//            printf("%d  -- %d\n", i, j);
        }
        for(int i = n2 - 1, j = n1 - 1; i >= 0; --i){
            while(j >= 0 && a[j] != b[i] ) --j;
            if(j >= 0)  pr[j--] = i;
			else break;
        }
        for(int i = 1; i < n1; ++i)  pl[i] = max(pl[i], pl[i - 1]);
        for(int i = n1 - 2; i >= 0; --i)  pr[i] = min(pr[i], pr[i + 1]);
        for(int i = 0; i < 26; ++i)  sum[0][i] = 0;

        for(int j = 1; j < n2 - 1; ++j){
            for(int i = 0; i < 26; ++i)  sum[j][i] = sum[j - 1][i];
            ++sum[j][b[j] - 'a'];
        }
		bool fg(1);
        for(int i = 1; i < n1 - 1 && fg; ++i){
            //printf("%d  %d %d\n",i, pl[i - 1], pr[i + 1]);
            if(pl[ i - 1] + 2 < pr[ i + 1]) fg = 0 ;
            else {
                int c = a[i] - 'a';
//                if(a[i] == 'c')  printf("%d %d\n", pl[i - 1], pr[i + 1]);
                int tmp = sum[min(n2 - 2, pl[i - 1] + 1)][c] - sum[ max(0, pr[i + 1] - 2) ][c];
                int t1 = sum[min(n2 - 2, pl[i - 1] + 1)][c];
                int t2 = sum[ max(0, pr[i + 1] - 2) ][c];
                if(tmp <= 0)  {
                    fg= 0;
//                    printf("%d %d  %d  %d %d  %d\n",i, pl[i - 1], pr[i + 1], t1, t2, c);
                }
            }

        }
        if(fg)  puts("Yes");
        else  puts("No");


    }



    return 0;
}

