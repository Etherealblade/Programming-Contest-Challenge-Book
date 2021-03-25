#include <iostream>
using namespace std;

const int MAX_E = 1024;
const int MAX_V = 128;
const int INF = 1E9;

struct edge
{
	int from, to, cost;
};

edge es[MAX_E];		// 边
int d[MAX_V];		// 最短距离
int V, E;			// V是顶点, E是边数

void bellman_ford(int s)
{
	/*
	求解从顶点s出发到所有点得最短距离
	*/
	for (int i = 0; i < V; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;

	while (true)
	{
		bool update = false;
		for (int i = 0; i < E; i++)
		{
			edge e = es[i];

			if (d[e.from] != INF &&
				d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;	// relax
				update = true;
			}
		}

		if (!update)
		{
			break;
		}
	}
}

bool find_negative_cycle()
{
	/*
	若返回true, 则存在负环
	*/
	memset(d, 0, sizeof(d));

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < E; j++)
		{
			edge e = es[j];

			if (d[e.to]>d[e.from]+e.cost)
			{
				d[e.to] = d[e.from] + e.cost;

				// 若第n次仍然更新了, 则存在负环
				if (i==V-1)
				{
					return true;
				}
			}
		}
	}

	return false;
}

