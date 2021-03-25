// Page 108

#include <iostream>
#include <algorithm>
#include <vector>
#include "dijkstra.h"
using namespace std;

// input
int N, R;

int dist[MAX_V];		// 最短距离
int dist2[MAX_V];		// 次短距离

void solve()
{
	priority_queue<P, vector<P>, greater<P>> que;

	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);

	dist[0] = 0;
	que.push(P(0, 0));

	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		int d = p.first;

		if (dist2[v] < d)
		{
			continue;
		}

		for (int i = 0; i < G[v].size(); i++)
		{
			edge &e = G[v][i];
			int d2 = d + e.cost;

			if (dist[e.to] > d2)
			{
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}

			if (dist2[e.to] > d2 && dist[e.to] < d2)
			{
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}

		}
	}

	cout << dist2[N - 1] << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> R;

	for (int i = 0; i < R; i++)
	{
		int s, t, cost;
		cin >> s;
		cin >> t;
		--t;		// 先做章尾的练习, 之前记得输入有坑
		--s;		// 如今在这里终于应验了9:01 9/9/20
		cin >> cost;
		G[s].push_back(edge(t, cost));
	}

	solve();

	fclose(file);
	return 0;
}
