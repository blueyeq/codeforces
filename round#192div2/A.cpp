#include <stdio.h>
#include <cstring>

using namespace std;

const int MAXN=100;
int N, M;
char mp[MAXN][MAXN];
int vis[MAXN][MAXN];

int main(){
    while(~scanf("%d%d", &N, &M)){
        for(int i = 0; i < N; ++i){
            scanf("%s", mp[i]);
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; ++i){
            int flag = 0;
            for(int j = 0; j < M; ++j){
                if(mp[i][j] == 'S'){
                    flag = 1;
                }
            }
            if(!flag){
//                printf("row %d\n", i);
                for(int j = 0; j < M; ++j) vis[i][j] = 1;
            }
        }
        for(int j = 0; j < M; ++j){
            int flag = 0;
            for(int i = 0; i < N; ++i){
                if(mp[i][j] == 'S')  flag = 1;
            }
            if(!flag)  {
//                printf("col %d\n", j);
                for(int i = 0; i < N; ++i)  vis[i][j] = 1;
            }
        }
        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(vis[i][j])   ++res;
            }
        }
        printf("%d\n", res);
    }



	return 0;
}
