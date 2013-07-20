#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1010;

bool g[MAXN][MAXN];
bool forbid[MAXN][MAXN];
int N, M;
int size[MAXN];

void readin(){

    memset(forbid, 0, sizeof(forbid));
    memset(g, 0, sizeof(g));
    memset(size, 0, sizeof(size));
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        forbid[a][b] = forbid[b][a] = 1;
        ++size[a];
        ++size[b];
    }
}


int main(){

    while(~scanf("%d%d", &N, &M)){
        readin();
        int node(-1);
        for(int i = 1; i<= N; ++i){
            if(node == -1 || size[i] < size[node])  node = i;
        }
        if(size[node] == 0){
            printf("%d\n", N - 1);
            for(int i = 1; i <= N; ++i){
                if(i != node)  printf("%d %d\n", i, node);
            }
        }else{
            printf("%d\n", N);
            int b, a;
            for(int i = 1; i <= N; ++i){
                if(i != node && !forbid[node][i])  printf("%d %d\n", i, node), b = i;
                if(forbid[node][i])  a = i;

            }
            printf("%d %d\n", a, b);

        }

    }


    return 0;
}
