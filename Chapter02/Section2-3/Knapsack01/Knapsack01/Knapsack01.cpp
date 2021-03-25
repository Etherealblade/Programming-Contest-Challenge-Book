/*
Page 52
01背包
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
int dp[MAX_N + 1][MAX_N + 1];	// 记忆化数组

// input
int n, W;
int w[MAX_N], v[MAX_N];

int rec(int i, int j)
{
	if (dp[i][j] >= 0)
	{
		// 已经计算过的话直接使用之前的结果
		return dp[i][j];
	}

	int res;
	if (i == n)
	{
		res = 0;
	}
	else if (j < w[i])
	{
		res = rec(i + 1, j);
	}
	else
	{
		res = max(rec(i + 1, j),
			rec(i + 1, j - w[i]) + v[i]);
	}

	//将结果记录在数组中
	return dp[i][j] = res;
}

void solve_rec()
{
	// 用-1表示尚未计算过, 初始化整个数组
	memset(dp, -1, sizeof(dp));
	cout << "solve_rec: " << rec(0, W) << endl;
}

void solve_loop()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i])
			{
				// 无法选择这件物品
				dp[i][j] = dp[i + 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j],
					dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << "solve_loop: " << dp[0][W] << endl;
}

int dp1[MAX_N];	//dp 数组降维
void solve_simplified()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = W; j >= w[i]; j--)
		{
			dp1[j] = max(dp1[j], dp1[j - w[i]] + v[i]);
		}
	}

	cout << "solve_simplified: " << dp1[W] << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> W;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	solve_rec();
	solve_loop();
	solve_simplified();

	fclose(file);
	return 0;
}
