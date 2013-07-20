#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define clr(a) memset(a,0,sizeof(a))
#define N 4096

int c[N][N];
int nm;
int n, m;
int lowbit(int x){
    return x&(-x);
}

void Update(int x,int y,int t){
    int i,j;
    i=x;
    while(i<=nm){
        j=y;
        while(j<=nm){
            c[i][j]+=t;
            j+=lowbit(j);
        }
        i+=lowbit(i);
    }
}
int Query(int x,int y){
    int i,j,s=0;
    i=x;
    while(i>0){
        j=y;
        while(j>0){
            s+=c[i][j];
            j-=lowbit(j);
        }
        i-=lowbit(i);
    }
    return s;
}

bool bInBox[N][N];

void Tran(int x, int y, int &rx, int &ry)
{
	rx = 0;
	ry = n;
	rx += x+y;
	ry += y-x;
}

bool check(int iLen, int x, int y)
{
	int rx[4], ry[4];
	Tran(x-iLen, y, rx[0], ry[0]);
	Tran(x+iLen, y, rx[1], ry[1]);
	Tran(x, y-iLen, rx[2], ry[2]);
	Tran(x, y+iLen, rx[3], ry[3]);

	int i, j, k;
	for(i = 0; i < 4; i ++)
	{
		if(rx[i] > n+m)
		{
			rx[i] = n+m;
		}
		if(rx[i] < 1)
		{
			rx[i] = 1;
		}

		if(ry[i] > n+m)
		{
			ry[i] = n+m;
		}
		if(ry[i] < 1)
		{
			ry[i] = 1;
		}
		//printf("(%d, %d) ", rx[i], ry[i]);
	}
	//putchar('\n');
	int Sum = Query(rx[3], ry[3]) + Query(rx[2]-1, ry[2]-1) - Query(rx[2]-1, ry[3]) - Query(rx[3], ry[2]-1);
	//printf("%d %d\n", Sum, (rx[3]-rx[2]+1)*(ry[3]-ry[2]+1));
	if(Sum < (rx[3]-rx[2]+1)*(ry[3]-ry[2]+1))return true;
	return false;
}

int Find(int x, int y)
{
	int left = 0;
	int right = max(n, m);
	int mid;
	int ret = right;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(check(mid, x, y))
		{
			ret = min(ret, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ret;
}

bool used[2048][2048];

int main()
{
    int i, j, k;


	while(scanf("%d%d%d", &n, &m, &k)!=EOF)
	{
		int x, y, rx, ry;

		for(i = 1; i <= n; i ++)
		{
			for(j = 1; j <= m; j ++)
			{
				Tran(i, j, rx, ry);
				//printf("%d %d\n", rx, ry);
				bInBox[rx][ry] = true;

			}
		}
		nm = n+m;
		for(i = 1; i <= n+m; i ++)
		{
			for(j = 1; j <= n+m; j ++)
			if(!bInBox[i][j])
			{
				Update(i, j, 1);
			}
		}

		//printf("%d\n", Query(nm, nm));

		for(i = 0; i < k; i ++)
		{
			scanf("%d %d", &x, &y);

			int Len = Find(x, y);

			rx = x - Len;
			int ry1 = y;
			int ry2 = y;
			bool flag = false;

			while(true)
			{
				if(rx >= 1 && rx <= n
				&& ry1 >= 1 && ry1 <= m && !used[rx][ry1])
				{
					flag = true;
					ry = ry1;
					break;
				}

				if(rx >= 1 && rx <= n
				&& ry2 >= 1 && ry2 <= m && !used[rx][ry2])
				{
					flag = true;
					ry = ry2;
					break;
				}
				if(rx < x)
				{
					ry1 --;
					ry2 ++;
				}
				else
				{
					ry1 ++;
					ry2 --;
				}
				rx ++;

			}
			used[rx][ry] = true;
			printf("%d %d\n", rx, ry);
			Tran(rx, ry, x, y);
			Update(x, y, 1);
		}
	}

    return 0;
}
