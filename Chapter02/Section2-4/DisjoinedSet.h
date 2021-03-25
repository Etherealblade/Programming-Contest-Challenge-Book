#include <iostream>
using namespace std;

#define MAX_N 1000

int par[MAX_N];		// 父亲
int Rank[MAX_N];	// 树的高度

void init_union_find(int n)
{
	// 初始化n个元素

	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x)
{
	// 查询树的根
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}

	if (Rank[x] < Rank[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (Rank[x] == Rank[y])
		{
			Rank[x]++;
		}
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}