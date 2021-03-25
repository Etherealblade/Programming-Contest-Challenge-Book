/*
Page 192
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10
#define INF 1e9

// input
int n = 5;					// 顶点个数
int Mat[MAX_N][MAX_N] = {
	{INF, 3, INF, 4, INF},
	{INF, INF, 5, INF, INF},
	{4, INF, INF, 5, INF},
	{INF, INF, INF, INF, 3},
	{7, 6, INF, INF,INF}
};
//int n;
//int Mat[MAX_N][MAX_N];

int dp[1 << MAX_N][MAX_N];	// 记忆化搜索使用的数组

int rec(int S, int v)
{
	// 已经访问过的节点集合为S, 当前位置为v
	if (dp[S][v] >= 0)
	{
		return dp[S][v];
	}

	if (S == (1 << n) - 1 && v == 0)
	{
		// 已经访问过所有节点并回到0号点
		return dp[S][v] = 0;
	}

	int res = INF;
	for (int u = 0; u < n; u++)
	{
		if (!(S >> u & 1))
		{
			// 下一步移动到顶点u
			res = min(res, rec(S | 1 << u, u) + Mat[v][u]);
		}
	}

	return dp[S][v] = res;
}

void solve_rec()
{
	memset(dp, -1, sizeof(dp));
	cout << "solve_rec: " << rec(0, 0) << endl;
}

void solve_loop()
{
	// 用足够大的值初始化数组
	for (int S = 0; S < 1 << n; S++)
	{
		fill(dp[S], dp[S] + n, INF);
	}

	dp[(1 << n) - 1][0] = 0;

	// 根据递推式依次计算
	for (int S = (1 << n); S >= 0; S--)
	{
		for (int v = 0; v < n; v++)
		{
			for (int u = 0; u < n; u++)
			{
				if (!(S >> u & 1))
				{
					dp[S][v] = min(dp[S][v],
						dp[S | 1 << u][u] + Mat[v][u]);
				}
			}
		}
	}
	cout << "solve_loop: " << dp[0][0] << endl;
}


int main()
{
	// 此题无法从外部文件读取输入data

	//FILE *file;
	//freopen_s(&file, "input.txt", "r", stdin);
	//
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> Mat[i][j];
	//	}
	//}

	solve_rec();
	solve_loop();

	//fclose(file);
	return 0;
}
