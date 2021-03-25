/*
Flow

总结: 不知所云. 此题被归类为Max Flow, 但似乎毫不相干
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 512

vector<int> G[MAXN];
int V;
bool is_cut_vertex[MAXN];       //  是否是割点
int status[MAXN];               //  0:没有访问 1:正在访问 2:已经访问
int lowlink[MAXN];              //  从i出发经有向边可到达的所有结点中最小的index
int index[MAXN];                //  表示i节点在树中的深度
int root;                       //  根节点
bool has_cut_vertex;            //  是否存在割点

void init(const int &v)
{
	V = v;
	has_cut_vertex = false;
	for (int i = 0; i <= V; i++)
	{
		G[i].clear();
	}
}

void tarjan_dfs(int current, int from, int depth)
{
	status[current] = 1;	// 正在访问
	lowlink[current] = index[current] = depth;
	int sub_tree = 0;	// 子树个数
	int v;

	for (auto& it : G[current])
	{
		v = it;
		if (v != from && status[v] == 1)
		{
			lowlink[current] = min(lowlink[current],
				index[v]);
		}

		if (status[v] == 0)
		{
			tarjan_dfs(v, current, depth + 1);
			++sub_tree;
			lowlink[current] = min(lowlink[current],
				lowlink[v]);

			// 求割点
			if ((current == root && sub_tree > 1) ||
				(current != root &&
					lowlink[v] >= index[current]))
			{
				is_cut_vertex[current] = 1;
				has_cut_vertex = true;
			}
		}
	}

	status[current] = 2;
}

void calc(int del)
{
	memset(is_cut_vertex, 0, sizeof(is_cut_vertex));
	memset(status, 0, sizeof(status));
	memset(lowlink, 0, sizeof(lowlink));
	memset(index, 0, sizeof(index));

	status[del] = 2;
	root = 0;
	if (del == 0)
	{
		root = 1;
	}

	tarjan_dfs(root, -1, 1);
}

bool solve()
{
	for (int i = 0; i < V; ++i)
	{
		calc(i);

		// 判断图是否联通
		for (int j = 0; j < V; j++)
		{
			if (status[j] == 0)
			{
				has_cut_vertex = true;
				break;
			}
		}

		if (has_cut_vertex)
		{
			break;
		}
	}

	return !has_cut_vertex;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N, M;
	while (scanf("%d%d", &N, &M) && N)
	{
		init(N);
		for (int i = 0; i < M; ++i)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			G[from].push_back(to);
			G[to].push_back(from);
		}
		puts(solve() ? "YES" : "NO");
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}

