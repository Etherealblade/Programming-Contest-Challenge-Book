/*
Type: Basic DP
总结:
1. 不懂得数学规律:
定义dp[i]为i的分解方案数. dp[0] = 2 ^ 0 = 1，递推到N.
若i为偶数, 则dp[i] = dp[i / 2] + dp[i – 1] + 1，
否则dp[i] = dp[i – 1] + 1
*/
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

const int MAXX = 1E6 + 1;
int dp[MAXX]; // 数字i的分解数

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	dp[0] = 1; // 2^0

	for (int i = 1; i <= N; ++i)
	{
		if ((i & 0x1) == 0)
		{
			dp[i] = dp[i / 2]; // 将i / 2的每个构成数乘以2，得到i
		}
		dp[i] += dp[i - 1]; // 将i - 1的构成数拿过来加一
		dp[i] %= 1000000000;
	}

	cout << dp[N] << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
