/*
Page 64
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define INF	1e9

// input
int n;
int a[MAX_N];

int dp[MAX_N];
void solve_trivial()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}

	cout << "solve_trivial: " << res << endl;
}

int dp1[MAX_N];
void solve_simplified()
{
	fill(dp1, dp1 + n, INF);

	// 水过鸭背
	for (int i = 0; i < n; i++)
	{
		*lower_bound(dp1, dp1 + n, a[i]) = a[i];
	}

	cout << "solve_simplified: " <<
		lower_bound(dp1, dp1 + n, INF) - dp1 << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	solve_trivial();
	solve_simplified();

	fclose(file);
}
