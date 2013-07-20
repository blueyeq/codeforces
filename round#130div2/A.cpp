#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;

const int MAXN = 100000;
const int INF = 1000000000;

char s[1000];
vector<string> ans;
bool vis[1000];
int main(){
//    freopen("A.in", "r",stdin);
    while(~scanf("%s", s)){

        memset(vis, 0, sizeof(vis));
        ans.clear();
        int n = strlen(s);
        for(int i = 0; i < n; ++i){
            if(i + 2 < n && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
                vis[i] = vis[i + 1] = vis[i + 2] = 1;
            }
        }
        for(int i = 0;i < n; ++i){
            string tmp = "";
            while(!vis[i] && i < n){
                tmp += s[i++];
            }
            if(tmp != "")   ans.push_back(tmp);
        }
        for(int i = 0; i < ans.size(); ++i){
            if(i == ans.size() - 1)  cout<<ans[i]<<endl;
            else  cout<<ans[i]<<" ";
        }
    }


    return 0;
}

