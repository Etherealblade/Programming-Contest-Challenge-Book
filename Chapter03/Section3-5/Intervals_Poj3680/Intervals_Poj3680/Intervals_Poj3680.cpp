// Page 246

#include <iostream>
#include <vector>
#include "min_cost_flow.h"
using namespace std;

#define MAX_N 16

// input
int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];

void solve()
{
	// 预处理顶点集合
	vector<int> x;
	for (int i = 0; i < N; i++)
	{
		x.push_back(a[i]);
		x.push_back(b[i]);

	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	// constructing the graph
	int m = x.size();
	int s = m, t = s + 1;
	V = t + 1;
	int res = 0;
	add_edge(s, 0, K, 0);
	add_edge(m - 1, t, K, 0);
	for (int i = 0; i + 1 < m; i++)
	{
		add_edge(i, i + 1, INF, 0);
	}

	for (int i = 0; i < N; i++)
	{
		int u = find(x.begin(), x.end(), a[i]) - x.begin();
		int v = find(x.begin(), x.end(), b[i]) - x.begin();

		// 从u向v连一条容量为1, 费用为-w[i]的边
		add_edge(v, u, 1, w[i]);
		add_edge(s, v, 1, 0);
		add_edge(u, t, 1, 0);
		res -= w[i];
	}

	res += min_cost_flow(s, t, K + N);
	cout << -res << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 3;
	while (count > 0)
	{
		cin >> N;
		cin >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> w[i];
		}

		solve();
		clear();
		count--;
	}

	fclose(file);
	return 0;
}

