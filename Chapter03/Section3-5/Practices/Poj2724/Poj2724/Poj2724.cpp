#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

#define MAX_N 10 + 16
#define MAX_M 2000 + 16

//------------ 最大流结束 ---------------
#define MAX_V MAX_M * 2
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
//------------ 最大流结束 ---------------

vector<int> operations;
char buffer[MAX_N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N, M;
	while (scanf("%d %d", &N, &M) != EOF && N && M)
	{
		operations.clear();
		for (int _ = 0; _ < M; _++)
		{
			scanf(" %s ", buffer);
			int t = 0;

			for (int i = 0; i < N; i++)
			{
				if (buffer[i] == '1')
				{
					t += 1 << (N - i - 1);
				}
			}

			operations.push_back(t);
			for (int i = 0; i < N; i++)
			{
				if (buffer[i] == '*')
				{
					t += 1 << (N - i - 1);
				}
			}
			operations.push_back(t);
		}

		sort(operations.begin(), operations.end());
		operations.erase(unique(operations.begin(),
			operations.end()), operations.end());
		V = operations.size();
		clear();

		for (int i = 0; i < V; i++)
		{
			for (int j = i + 1; j < V; j++)
			{
				bitset<32> diff = operations[i] ^
					operations[j];
				if (diff.count() == 1)
				{
					add_edge(i, j);
				}
			}
		}
		printf("%d\n", V - bipartite_matching());
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}

