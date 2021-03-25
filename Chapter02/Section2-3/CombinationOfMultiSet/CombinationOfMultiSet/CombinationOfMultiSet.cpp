/*
Page 68
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MOD 10000

// input
int n, m;
int a[MAX_N];

int dp[MAX_N][MAX_N];
void solve()
{
	// 一个都不取得方法总是只有一种
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j - 1 - a[i] >= 0)
			{
				/*
				在有取余得情况下, 要避免减法运算得结果出现负数
				*/
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] -
					dp[i][j - 1 - a[i]] + MOD) % MOD;
			}
			else
			{
				dp[i + 1][j] = (dp[i + 1][j - 1]) +
					dp[i][j] % MOD;
			}
		}
	}

	cout << dp[n][m] << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	solve();

	fclose(file);
}

