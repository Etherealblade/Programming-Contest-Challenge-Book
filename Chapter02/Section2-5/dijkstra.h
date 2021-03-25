#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 128;
const int INF = 1E9;

int cost[MAX_V][MAX_V];
int d[MAX_V];		// 顶点s出发的最短路径
bool used[MAX_V];	// 已经使用过的点
int V;				// 顶点数


void dijkstra(int s)
{
	/*
	求从起点s出发到各个顶点的最短距离
	*/

	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true)
	{
		int v = -1;

		// 从尚未使用过的顶点中选择一个距离最小的顶点
		for (int u = 0; u < V; u++)
		{
			if (!used[u] && (v == -1 || d[u] < d[v]))
			{
				v = u;
			}
		}

		if (v == -1)
		{
			break;
		}

		used[v] = true;
		for (int u = 0; u < V; u++)
		{
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}

// priority_queue 版dijkstra
struct edge
{
	int to, cost;
	edge(){}
	edge(int to, int cost) :to(to), cost(cost)
	{

	}
};

typedef pair<int, int> P;	// first 是最短距离, second 是顶点编号
vector<edge> G[MAX_V];		// 图的邻接表表示

void dijkstra_queue(int s)
{
	/*
	通过指定greater<P>参数, 堆按照first从小到大的顺序取出值
	*/
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second;

		if (d[v] < p.first)
		{
			continue;
		}

		for (int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];

			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}