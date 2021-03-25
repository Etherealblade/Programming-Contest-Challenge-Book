#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
using namespace std;

#define MAX_V 200 * 2 + 16
int V;					// 顶点数
vector<int> G[MAX_V];	// 图的邻接表
int match[MAX_V];		// 所匹配的顶点
bool used[MAX_V];		// DFS中用到的访问标记

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
	for (auto &it : G[v])
	{
		int u = it, w = match[u];
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N, M;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		V = V + M;
		for (int i = 0; i < V; i++)
		{
			G[i].clear();
		}
		for (int i = 0; i < N; i++)
		{
			int S;
			scanf("%d", &S);
			for (int j = 0; j < S; j++)
			{
				int u;
				scanf("%d", &u);
				u = N + u - 1;
				add_edge(i, u);
			}
		}

		printf("%d\n", bipartite_matching());
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
