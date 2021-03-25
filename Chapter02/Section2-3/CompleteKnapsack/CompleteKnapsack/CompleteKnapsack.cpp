/*
Page 57

*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int dp[MAX_N][MAX_N];	// dp 数组

// input
int n, W;
int w[MAX_N], v[MAX_N];

void solve_trivial()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			for (int k = 0; k*w[i] <= j; k++)
			{
				dp[i + 1][j] = max(dp[i + 1][j],
					dp[i][j - k * w[i]] + k * v[i]);
			}
		}
	}

	cout << "solve_trivial: " << dp[n][W] << endl;
}

void solve_simplified1()
{
	// 减少重复计算
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i])
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j],
					dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << "solve_simplified1: " << dp[n][W] << endl;
}

int dp1[MAX_N];		// dp 数组降维
void solve_simplified2()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = w[i]; j <= W; j++)
		{
			dp1[j] = max(dp1[j], dp1[j - w[i]] + v[i]);
		}
	}

	cout << "solve_simplified2: " << dp1[W] << endl;
}

int dp2[2][MAX_N];	// dp数组
void solve_simplified3()
{
	//一向对2进制运算不感冒

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i])
			{
				dp2[(i + 1) & 1][j] = dp2[i & 1][j];
			}
			else
			{
				dp2[(i + 1) & 1][j] = max(dp2[i & 1][j],
					dp2[(i + 1) & 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << "solve_simplified3: " <<
		dp2[n & 1][W] << endl;
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

	solve_trivial();
	solve_simplified1();
	solve_simplified2();
	solve_simplified3();

	fclose(file);
}
