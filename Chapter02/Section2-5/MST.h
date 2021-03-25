#include <iostream>
#include "E:\Project\VC\Competitive Programming\Volume1\Chapter02\Section2-4\DisjoinedSet.h"
using namespace std;

const int MAX_V = 128;
const int MAX_E = 1024;
const int INF = 1E9;

struct edge
{
	int u, v, cost;

	edge(){}

	edge(int u, int v, int cost) :u(u), v(v), cost(cost)
	{

	}
};

int cost[MAX_V][MAX_V];
int mincost[MAX_V];	// 从集合X出发的边到每个顶点的最小权值
bool used[MAX_V];	// 顶点i是否包含在集合X中
int V;
int E;
edge es[MAX_E];

int prim()
{
	for (int i = 0; i < V; i++)
	{
		mincost[i] = INF;
		used[i] = false;
	}

	mincost[0] = 0;
	int res = 0;

	while (true)
	{
		int v = -1;

		// 从不属于X的顶点中选取从X到其权值最小的顶点
		for (int u = 0; u < V; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] <
				mincost[v]))
			{
				v = u;
			}
		}

		if (v == -1)
		{
			break;
		}

		used[v] = true;			// 把顶点v加到X
		res += mincost[v];		// 把边的长度加到结果里

		for (int u = 0; u < V; u++)
		{
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}

	return res;
}

bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}

int kruskal()
{
	sort(es, es + E, comp);		// edge.cost从小到大排序
	init_union_find(V);

	int res = 0;
	for (int i = 0; i < E; i++)
	{
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}
	}

	return res;
}