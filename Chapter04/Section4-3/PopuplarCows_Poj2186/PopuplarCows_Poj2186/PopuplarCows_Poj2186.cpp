/*
Page 322

test data:
3 3
1 2 2
2 1 3

only cow 3
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_V 100

// Input:
int N, M;
int *A, *B;

// Cite:
int  V;	// 顶点数
vector<int> G[MAX_V];	// 图的邻接表表示
vector<int> rG[MAX_V];	// 把边反向后的图
vector<int> vs;			// 后续遍历顺序的顶点列表
bool used[MAX_V];		// 访问标记
int cmp[MAX_V];			// 所属强连通分量的拓扑序

void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (!used[G[v][i]])
		{
			dfs(G[v][i]);
		}
	}
	vs.push_back(v);
}

void rdfs(int v, int k)
{
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); i++)
	{
		if (!used[rG[v][i]])
		{
			rdfs(rG[v][i], k);
		}
	}
}

int scc()
{
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++)
	{
		if (!used[v])
		{
			dfs(v);
		}
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--)
	{
		if (!used[vs[i]])
		{
			rdfs(vs[i], k++);
		}
	}

	return k;
}

void solve()
{
	V = N;
	for (int i = 0; i < M; i++)
	{
		add_edge(A[i] - 1, B[i] - 1);
	}
	int n = scc();

	// 统计备选解的个数
	int u = 0, num = 0;
	for (int v = 0; v < V; v++)
	{
		if (cmp[v] == n - 1)
		{
			u = v;
			num++;
		}
	}

	// 检查是否从所有点可达
	memset(used, 0, sizeof(used));
	rdfs(u, 0);	// 重用强连通分量分解的代码
	for (int v = 0; v < V; v++)
	{
		if (!used[v])
		{
			// 从该点不可达
			num = 0;
			break;
		}
	}

	printf_s("%d\n", num);
}

int main()
{
	scanf_s("%d%d", &N, &M);
	A = new int[M];
	B = new int[M];
	//memset(A, 0, sizeof(A));	// 此处只把A[0]初始化为0
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}

	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", &B[i]);
	}

	solve();

	return 0;
}
