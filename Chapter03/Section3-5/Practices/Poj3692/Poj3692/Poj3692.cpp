#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

//----------- 最大流开始 ----------------

#define MAX_V 200 * 2 + 16
int V;                 // 顶点数
vector<int> G[MAX_V];  // 图的邻接表
int match[MAX_V];      // 所匹配的顶点
bool used[MAX_V];      // DFS中用到的访问标记

// 向图中增加一条连接u和v的边
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

// 通过DFS寻找增广路
bool dfs(int v)
{
	used[v] = true;
	for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it)
	{
		int u = *it, w = match[u];
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}

	return false;
}

// 求解二分图的最大匹配
int bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; ++v)
	{
		if (match[v] < 0)
		{
			memset(used, 0, sizeof(used));
			if (dfs(v))
			{
				++res;
			}
		}
	}

	return res;
}

// 初始化
void clear()
{
	for (int i = 0; i < V; ++i)
	{
		G[i].clear();
	}
}
//----------- 最大流结束 ----------------

bool graph[MAX_V][MAX_V];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int G, B, M, id = 0;
	while (scanf("%d%d%d", &G, &B, &M) != EOF && G)
	{
		V = G + B;
		memset(graph, 0, sizeof(graph));
		clear();

		for (int i = 0; i < M; i++)
		{
			int X, Y;
			scanf("%d%d", &X, &Y);
			--X;
			--Y;
			graph[X][Y] = true;
		}
		for (int i = 0; i < G; i++)
		{
			for (int j = 0; j < B; j++)
			{
				if (!graph[i][j])
				{
					add_edge(i, j + G);
				}
			}
		}

		printf("Case %d: %d\n", ++id,
			V - bipartite_matching());
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}

