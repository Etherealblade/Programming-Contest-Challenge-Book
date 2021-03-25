/*
Dijkstra

Sample Input

3 3
1 2 1 2
2 3 2 1
3 1 3 2
5 5
1 2 2 2
2 3 1 1
1 4 1 1
4 5 1 1
5 3 1 1
5 10
1 2 32 10
1 3 43 43
1 4 12 52
1 5 84 23
2 3 58 42
2 4 86 99
2 5 57 83
3 4 11 32
3 5 75 21
4 5 23 43
5 10
1 2 1 53
1 3 1 65
1 4 1 24
1 5 1 76
2 3 1 19
2 4 1 46
2 5 1 25
3 4 1 13
3 5 1 65
4 5 1 34
0 0

Output for the Sample Input

3
5
137
218

*/

#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
#define MAX_V 1024

typedef struct edge
{
	int to, distance, cost;
	edge() {}
	edge(int to, int distance, int cost) :
		to(to), distance(distance), cost(cost) {}
	bool operator > (const edge & b) const
	{
		return distance != b.distance ?
			distance > b.distance : cost > b.cost;
	}
} P;

// 图
vector<edge> G[MAX_V];

// V是顶点数
int V;
bool visited[MAX_V];

// 求解从顶点s出发到所有点的最短花费
int dijkstra(int s)
{
	int result = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	// 此处P是个structure, greater比较的是什么?
	// greater 是ascending

	memset(visited, 0, V * sizeof(bool));
	que.push(P(0, 0, 0));

	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.to;
		if (visited[v])
			continue;

		visited[v] = true;
		result += p.cost;
		for (int i = 0; i < G[v].size(); ++i)
		{
			// 为何在此处未见Relax操作?
			edge e = G[v][i];
			que.push(P(G[v][i].to,
				p.distance + G[v][i].distance,
				G[v][i].cost));
		}
	}

	return result;
}


int main()
{
	int /*N = V,*/ M;
	while (cin >> V >> M && V)
	{
		for (int i = 0; i < V; ++i)
		{
			G[i].clear();	// G[i].size()=0
		}

		for (int i = 0; i < M; ++i)
		{
			int u, v, d, c;
			cin >> u >> v >> d >> c;
			--u, --v;	// 有坑
			G[u].push_back(edge(v, d, c));
			G[v].push_back(edge(u, d, c));
			// 为何要添加"逆路径"?, 若没有"逆路径", 第3个用例有误!
		}

		cout << dijkstra(0) << endl;
	}

	return 0;
}

