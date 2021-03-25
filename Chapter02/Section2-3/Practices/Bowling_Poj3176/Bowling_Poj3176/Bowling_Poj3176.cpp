/*
Type: Basic DP

*/
#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_CASES 300

int score[MAX_CASES][MAX_CASES];
int dp[MAX_CASES][MAX_CASES];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> score[i][j];
		}
	}

	dp[0][0] = score[0][0];

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1],
				dp[i][j] + score[i + 1][j + 1]);
			dp[i + 1][j] = max(dp[i + 1][j],
				dp[i][j] + score[i + 1][j]);
		}
	}

	cout << *max_element(dp[N - 1],
		dp[N - 1] + N) << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
