/*
Type: Graph-Dijkstra

Sample Input

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

Sample Output

10
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX_V 1024

struct edge
{
	int to, cost;
	edge() {}
	edge(int to, int cost) : to(to), cost(cost) {}
};

// first 最短路径，second顶点编号
typedef pair<int, int> P;

// 图
vector<vector<edge> > G(MAX_V);
// 反向图
vector<vector<edge> > RG(MAX_V);

// 最短距离
int d[MAX_V];
int rd[MAX_V];
// V是顶点数，E是边数
int V, E;

// 求解从顶点s出发到所有点的最短距离
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f, sizeof(d));

	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i)
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

int main()
{
	int M, X;
	cin >> V >> M >> X;
	--X;	// 此处有坑, 但是为何?
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		--A;
		--B;
		G[A].push_back(edge(B, T));
		RG[B].push_back(edge(A, T));
	}

	dijkstra(X);
	G = RG;
	memcpy(rd, d, sizeof(d));
	dijkstra(X);
	for (int i = 0; i < V; ++i)
	{
		d[i] += rd[i];
	}

	cout << *max_element(d, d + V) << endl;

	return 0;
}

