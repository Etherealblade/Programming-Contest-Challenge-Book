/*
Page 133
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
typedef long long ll;

// input
int M, X;
double P;

double dp[2][(1 << MAX_N) + 1];

void solve()
{
	int n = 1 << M;

	double *prev = dp[0], *next = dp[1];
	memset(prev, 0, sizeof(double)*(n + 1));
	prev[n] = 1.0;

	for (int r = 0; r < M; r++)
	{
		for (int i = 0; i <= n; i++)
		{
			int jub = min(i, n - i);
			double t = 0.0;
			for (int j = 0; j <= jub; j++)
			{
				t = max(t, P*prev[i + j] +
					(1 - P)*prev[i - j]);
			}
			next[i] = t;
		}

		swap(prev, next);
	}

	int i = (ll)X*n / 1000000;
	cout << prev[i] << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> M;
		cin >> P;
		cin >> X;

		solve();
		count--;
	}

	fclose(file);
	return 0;
}
