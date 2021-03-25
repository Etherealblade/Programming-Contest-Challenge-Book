/*
MST
*/

#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX_V 1024

int mincost[MAX_V];		// 从集合X出发的边到每个顶点的最小权值
bool used[MAX_V];		// 顶点i是否包含在集合X中
int V;					// 顶点数
// first 最短路径，second顶点编号
typedef pair<int, int> P;
struct edge
{
	int to, cost;
	edge(int to = 0, int cost = 0) :
		cost(cost), to(to)
	{

	}
};

vector<edge> G[MAX_V];
// G[i] 顶点i到G[i].to的权值为G[i].cost

int prim()
{
	int res = 0;
	memset(mincost, 0x3f, V * sizeof(int));
	memset(used, 0, V * sizeof(bool));
	mincost[0] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, 0));

	while (!que.empty())
	{
		P p = que.top(); 
		que.pop();
		int v = p.second;

		if (used[v] || p.first > mincost[v]) 
			continue;

		used[v] = true;
		res += mincost[v];
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			if (mincost[e.to] > e.cost)
			{
				mincost[e.to] = e.cost;
				que.push(P(mincost[e.to], e.to));
			}
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

	while (cin >> V && V)
	{
		for (int i = 0; i < V; ++i)
		{
			G[i].clear();
			for (int j = 0; j < V; ++j)
			{
				int cost;
				cin >> cost;
				G[i].push_back(edge(j, cost));
			}
		}

		cout << prim() << endl;
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;

}

