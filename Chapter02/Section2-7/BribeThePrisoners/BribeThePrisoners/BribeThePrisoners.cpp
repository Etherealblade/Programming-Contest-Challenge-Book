/*
page 130
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

// input
int P, Q, A[MAX_N];		// A 中保持输入数据, 下标从1开始
int dp[MAX_N][MAX_N];	// dp[i][j], 释放(i,j)所需得金币

void solve()
{
	// 为了处理方便, 将两端加入A中
	A[0] = 0;
	A[Q + 1] = P + 1;

	// initialize
	for (int q = 0; q <= Q; q++)
	{
		dp[q][q + 1] = 0;
	}

	// 从短得区间开始填充dp
	for (int w = 2; w <= Q + 1; w++)
	{
		for (int i = 0; i + w <= Q + 1; i++)
		{
			// 计算dp[i][j]
			int j = i + w, t = INT_MAX;
			// 枚举最初释放得囚犯, 计算最小费用
			for (int k = i + 1; k < j; k++)
			{
				t = min(t, dp[i][k] + dp[k][j]);
			}

			// 最初地释放还需要与所释放囚犯无关地A[j]-A[i]-2枚金币
			dp[i][j] = t + A[j] - A[i] - 2;
		}
	}

	cout << dp[0][Q + 1] << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> P;
		cin >> Q;
		for (int i = 1; i <= Q; i++)
		{
			cin >> A[i];
		}

		solve();
		count--;
	}

	fclose(file);
}
