// Page 243

#include <iostream>
#include <algorithm>
#include "min_cost_flow.h"
using namespace std;

#define MAX_N 16

// input
int N, M;
int Z[MAX_N][MAX_N];

void solve()
{
	int s = N + N * M, t = s + 1;
	V = t + 1;

	for (int i = 0; i < N; i++)
	{
		add_edge(s, i, 1, 0);
	}
	for (int j = 0; j < M; j++)
	{
		for (int k = 0; k < N; k++)
		{
			add_edge(N + j * N + k, t, 1, 0);
			for (int i = 0; i < N; i++)
			{
				add_edge(i, N + j * N + k, 1,
					(k + 1)*Z[i][j]);
			}
		}
	}
	cout << (double)min_cost_flow(s, t, N) / N << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 3;
	while (count > 0)
	{
		cin >> N;
		cin >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> Z[i][j];
			}
		}

		solve();
		clear();
		count--;
	}

	fclose(file);
	return 0;
}
