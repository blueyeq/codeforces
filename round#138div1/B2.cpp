/*************************************************************************
    > File Name: B2.cpp
    > Author: hnu0314
    > Mail: hnu0314@126.com 
    > Created Time: 2012/9/17 13:13:00
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int MAXN = 210000 
const int INF = 0;

char a[MAXN], b[MAXN];
int pl[MAXN], pr[MAXN];
int sum[MAXN][26];
int n1, n2;
void init(){
	
	n1 = strlen(a + 1);
	n2 = strlen(b + 1);
	a[++n1] = b[++n2] = '$';
	++n1, ++n2;
	
	memset(pl, 0, sizeof(pl));
	memset(pr, 0, sizeof(pr));
	memset(sum, 0, sizeof(sum));
	for(int i = 0, j = 0; i < n1 && j < n2; ++i){
		while(a[j] != b[i]) ++j;
		if(j < n1)  pl[j] = i;
	}
	for(int i = n2 - 1, j = n1 - 1; i >= 0 && j >= 0; --i){
		while(a[j] != b[i]) --j;
		if(j >= 0)  pr[j] = i;
	}
	for(int i = 1; i < n1; ++i)  pl[i] = max(pl[i], pl[i - 1]);
	for(int i = n1 - 2; i >= 0; --i) pr[i] = min(pr[i], pr[i + 1]);


}

int main(){



	return 0;
}
