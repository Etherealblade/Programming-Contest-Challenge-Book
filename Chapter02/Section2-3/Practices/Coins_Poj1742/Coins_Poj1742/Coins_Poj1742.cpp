/*
Type: DP Optimization

dp[j] := 在第i次循环时之前表示用前i-1种硬币凑成j时第i种硬币
最多能剩余多少个（-1表示配不出来），循环之后就表示第i次的状态

于是就省了一维数组
*/
#pragma warning(disable: 4996)
#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int dp[100000 + 16]; // dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个
int A[100 + 16];
int C[100 + 16];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[j] >= 0)
				{
					dp[j] = C[i];
				}
				else if (j < A[i] ||
					dp[j - A[i]] <= 0)
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - A[i]] - 1;
					// 用上了第i个硬币
				}
			}
		}

		// 总额0不算在答案内
		int answer = count_if(dp + 1, dp + 1 + m,
			bind2nd(greater_equal<int>(), 0));
		// bind2nd 弃用函数

		cout << answer << endl;
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

