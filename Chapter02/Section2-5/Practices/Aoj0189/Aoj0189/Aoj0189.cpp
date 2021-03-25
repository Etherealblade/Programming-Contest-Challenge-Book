/*
Type: Graph

Sample Input

6
0 1 80
1 2 20
0 2 60
2 3 50
3 4 60
1 4 90
2
0 1 1
1 2 1
0

Output for the Sample Input

2 240
1 2

*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 11
int d[MAX_V][MAX_V];
// d[u][v]表示边e=(u,v)的权值，不存在的时候等于无穷大或者d[i][i] = 0
int V;	// 顶点数

int x[MAX_V];	// x[i]表示以i为起点时的最短路线之和

void warshall_floyd()
{
	for (int k = 0; k < V; ++k)
	{
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main()
{
	int E;
	while (cin >> E, E)
	{
		memset(d, 0x3f, MAX_V * MAX_V * sizeof(int));

		for (int i = 0; i < MAX_V; ++i)
		{
			d[i][i] = 0;
		}

		V = 0;
		for (int i = 0; i < E; i++)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			d[u][v] = cost;
			d[v][u] = cost;
			V = max(V, max(v, u) + 1);	// 此行何意?
		}

		warshall_floyd();
		memset(x, 0, V * sizeof(int));

		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; ++j)
			{
				x[i] += d[i][j];
			}
		}

		int ans = min_element(x, x + V) - x;
		cout << ans << ' ' << x[ans] << endl;
	}

	return 0;
}

