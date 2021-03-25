/*
DP
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <bitset>
using namespace std;
#define MAX_N 20
#define MAX_M 20

int dp[1 << MAX_M];
// dp[S]表示已分配场地构成的集合S时的情况种数
bool like[MAX_N][MAX_M];
// like[i][j]表示球队i喜欢场地j


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int P; cin >> P;
		for (int j = 0; j < P; ++j)
		{
			int b;
			cin >> b; --b;
			like[i][b] = true;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		if (like[0][i])
		{
			dp[1 << i] = 1;	// 将i场地分配给0号球队
		}
	}

	for (int i = 1; i < N; ++i)
	{
		for (int comb = (1 << i) - 1, x, y;
			comb < (1 << M);
			x = comb & -comb, y = comb + x,
			comb = ((comb & ~y) / x >> 1) | y)
		{
			// comb表示集合{0, 1, ... , M - 1}的大小为i的子集，
			// 也就是分配了i个场地，满足了i个球队
			if (dp[comb])
			{
				for (int j = 0; j < M; ++j)
				{
					if (like[i][j] && !((comb >> j) & 1))
					{
						// i 需要j 并且j没有被分配, 此时将j分配掉
						dp[comb | (1 << j)] += dp[comb];
					}
				}
			}

		}

	}

	int result = 0;
	for (int bit = 0; bit < (1 << M); ++bit)
	{
		if (bitset<32>(bit).count() == N)
		{
			result += dp[bit];
		}
	}
	cout << result << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

