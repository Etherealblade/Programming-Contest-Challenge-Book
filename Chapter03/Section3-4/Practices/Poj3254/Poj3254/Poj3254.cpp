/*
状态压缩DP
*/
#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
using namespace std;

int dp[12][1 << 12];
// dp[i][S] := 第i行的状态为S时的方法总数
int bad[12];	// 荒地的mask
int MOD = 100000000;
int m, n;

void dfs(int row, int line, int S,
	int except_S, int pre_dp)
{
	if (line == n)
	{
		// 这一行种完了, 统计结果
		dp[row][S] = (dp[row][S] + pre_dp) % MOD;
		return;
	}

	// 这一行还没有种完, 继续尝试往下种
	dfs(row, line + 1, S, except_S, pre_dp);
	if (!(except_S & (1 << line)))	// 重叠
	{
		// 这里的S | 1 << line将line加入集合，
		// except_S | (1 << (line + 1))表示排除相邻的一个
		dfs(row, line + 1,
			S | 1 << line, except_S | (1 << (line + 1)),
			pre_dp);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int t;
			cin >> t;
			bad[i] |= (!t) << j;
		}
	}

	dfs(0, 0, 0, bad[0], 1);

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
		{
			// bad[i] | j 表示上一行的状态j和这一行的荒地合
			// 并加入到排除集合中
			dfs(i, 0, 0, bad[i] | j,
				dp[i - 1][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		ans = (ans + dp[m - 1][i]) % MOD;
	}
	cout << ans << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}

