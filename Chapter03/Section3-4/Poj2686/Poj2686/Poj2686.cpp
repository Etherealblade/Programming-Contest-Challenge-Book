/*
Page 194
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 8
#define INF 1e9

// input
int n, m, a, b;
int t[MAX_N];
int Mat[MAX_N][MAX_N];	// -1表示没边

double dp[1 << MAX_N][MAX_N];
// dp[S][v]: 到达剩下的车票集合为S并且现在在城市
// v 的状态所需要的mini cost

void solve()
{
	for (int i = 0; i < 1 << n; i++)
	{
		fill(dp[i], dp[i] + m, INF);	// 用足够大的值初始化
	}

	dp[(1 << n) - 1][a - 1] = 0;
	double res = INF;

	for (int S = (1 << n) - 1; S >= 0; S--)
	{
		res = min(res, dp[S][b - 1]);

		for (int v = 0; v < m; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if (S >> i & 1)
				{
					for (int u = 0; u < m; u++)
					{
						if (Mat[v][u] >= 0)
						{
							// 使用车票i, 从v移动到u
							dp[S&~(1 << i)][u] = min(
								dp[S&~(1 << i)][u],
								dp[S][v] + 
								(double)Mat[v][u] / t[i]);
						}
					}
				}
			}
		}
	}
	if (res == INF)
	{
		// 无法到达
		cout << "Impossible" << endl;
	}
	else
	{
		cout << res << endl;
	}
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> m;
	cin >> a;
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Mat[i][j];
		}
	}

	solve();

	fclose(file);
	return 0;
}

