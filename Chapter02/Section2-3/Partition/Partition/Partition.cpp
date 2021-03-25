/*
Page 66
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 10000
#define MAX_N 1000

// input
int n, m;

int dp[MAX_N][MAX_N];
void solve()
{
	dp[0][0] = 1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j - i >= 0)
			{
				dp[i][j] = (dp[i - 1][j] +
					dp[i][j - i]) % MOD;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[m][n] << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> m;

	solve();

	fclose(file);
}
