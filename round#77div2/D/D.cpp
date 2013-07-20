/*
	author:  hnu0314
	type :  C/C++
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1010

using namespace std;

typedef long long LL;

int head[MAXN], vis[MAXN][MAXN];
LL cost[MAXN], dis[MAXN];
int s, t, cnt, n;

struct Edg
{
    int v, next;
    LL len;
}edg[3000];

struct Node
{
    int id, start;
    LL money, left;
    Node(int a, LL b, LL c, int d)
    {
        id = a;  left = b;  money = c;   start = d;
    }
    bool operator < (const Node b)  const
    {
        return money > b.money;
    }
};

void add(int a, int b, LL c)
{
    edg[cnt].v = b;  edg[cnt].len = c;   edg[cnt].next = head[a];  head[a] = cnt++;
}

LL spfa()
{
    priority_queue<Node> pq;
    pq.push(Node(s, dis[s], cost[s], -1));
    memset(vis, 0, sizeof(vis));
    while(!pq.empty())
    {
        Node tt = pq.top();
        pq.pop();
        int v = tt.id;
        int start = tt.start;
        LL left = tt.left;
        LL money = tt.money;
        if(v == t)  return money;

        for(int i = head[v]; i != -1; i = edg[i].next)
        {
            if(edg[i].v == v)   continue;
            if(dis[v] >= edg[i].len && !vis[v][edg[i].v])
            {
                pq.push(Node(edg[i].v, dis[v]-edg[i].len, money+cost[v], v));
                vis[v][edg[i].v] = true;
            }
            if(left >= edg[i].len)// && !vis[start][edg[i].v])
            {
                pq.push(Node(edg[i].v, left-edg[i].len, money, start));
                vis[start][edg[i].v] = true;
            }
        }
    }
    return -1;
}



int main()
{
    int m, a, b, c;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        scanf("%d%d",&s,&t);
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a, b, c);
            add(b, a, c);
        }
        for(int i = 1; i <= n; ++i)
            scanf("%I64d%I64d",&dis[i], &cost[i]);
        printf("%I64d\n",spfa());
    }

	return 0;
}
