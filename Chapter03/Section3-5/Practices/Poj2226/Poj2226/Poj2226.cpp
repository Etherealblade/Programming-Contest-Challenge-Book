#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 50 + 16

//------------- 最大流开始 ------------
#define MAX_V 2500 * 2
int V;					// 顶点数
vector<int> G[MAX_V];	// 图的邻接表
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
	for (vector<int>::iterator it = G[v].begin();
		it != G[v].end(); ++it)
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

void clear()
{
	for (int i = 0; i < V; ++i)
	{
		G[i].clear();
	}
}

//------------- 最大流结束 ------------

char grid[MAX_N][MAX_N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; ++i)
	{
		scanf("%s", grid[i]);
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (grid[i][j] == '*')
			{
				int y = i, x = j;
				while (y > 0 && grid[y - 1][j] == '*')
				{
					--y;
				}
				while (x > 0 && grid[i][x - 1] == '*')
				{
					--x;
				}
				add_edge(y * 50 + j,
					i * 50 + x + 2500);
			}
		}
	}

	V = MAX_V;
	printf("%d", bipartite_matching());

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
