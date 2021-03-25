/*
MST
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2224


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX_N 10000 + 16
int parent[MAX_N];
int height[MAX_N];

#define MAX_E MAX_N * MAX_N / 2 + 1
struct edge
{
	int u, v;
	double cost;
	edge(int u = 0, int v = 0, double cost = 0) :
		u(u), v(v), cost(cost) {}
	bool operator < (const edge & e2) const
	{
		return cost > e2.cost;
	}
};
edge es[MAX_E];
int V, E;

pair<int, int> pile[MAX_N];

// 并查集相关数据与算法
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

double kruskal()
{
	sort(es, es + E);    // 按照权值从小到大排序
	init(V);
	double res = 0;
	for (int i = 0; i < E; ++i)
	{
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
		}
		else
		{
			res += e.cost;
		}
	}

	return res;
}


int main()
{
	cin >> V >> E;

	for (int i = 0; i < V; ++i)
	{
		cin >> pile[i].first >> pile[i].second;
	}

	for (int i = 0; i < E; ++i)
	{
		cin >> es[i].u >> es[i].v;
		--es[i].u;
		--es[i].v;
		int dx = pile[es[i].u].first -
			pile[es[i].v].first;
		int dy = pile[es[i].u].second -
			pile[es[i].v].second;
		es[i].cost = sqrt(dx * dx + dy * dy);
	}

	cout.setf(ios::showpoint);
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << kruskal() << endl;
	return 0;
}

