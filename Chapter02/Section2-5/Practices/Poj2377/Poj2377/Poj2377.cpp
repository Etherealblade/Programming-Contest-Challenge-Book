/*
MST
*/

#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_E 20000 + 16

struct edge
{
	int u, v, cost;
	edge(int u = 0, int v = 0, int cost = 0) :
		u(u), v(v), cost(cost) {}
	bool operator < (const edge & e2) const
	{
		return cost > e2.cost;
	}
};
edge es[MAX_E];
int V, E;
int in_tree;	// 在树中的节点个数

// 并查集相关数据与算法
#define MAX_N 1000 + 16
int parent[MAX_N];
int height[MAX_N];

void init(const int& n)
{
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
		height[i] = 0;
	}
}

int find(const int& x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}

	if (height[x] < height[y])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
		if (height[x] == height[y])
		{
			++height[x];
		}
	}
}

bool same(const int& x, const int& y)
{
	return find(x) == find(y);
}
// End Of 并查集

int kruskal()
{
	sort(es, es + E);	// 按照权值从小到大排序
	init(V);
	int res = 0;
	in_tree = 1;
	for (int i = 0; i < E && in_tree <= V; ++i)
	{
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
			++in_tree;
		}
	}

	return res;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		cin >> es[i].u >> es[i].v >> es[i].cost;
		--es[i].u; // 为何顶点编号要--?
		--es[i].v;
	}

	int ans = kruskal();
	if (in_tree < V)
	{
		ans = -1;
	}
	cout << ans << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;

}
