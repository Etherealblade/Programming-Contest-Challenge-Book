#include <iostream>
#include "Auxiliary_MaxFlow.h"
using namespace std;

const int MAX_N = 100;
const int MAX_K = 25;

int N, K, P[MAX_N][MAX_K];

void solve()
{
	V = N * 2;

	clear();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}

			bool f = true;

			for (int k = 0; k < K; k++)
			{
				if (P[j][k] >= P[i][k])
				{
					f = false;
				}
			}

			if (f)
			{
				add_edge(i, N + j);
			}
		}

	}

	int ans = N - bipartite_matching();
	printf_s("%d\n", ans);
}



int main()
{
	FILE *stream;
	freopen_s(&stream, "in.txt", "r", stdin);

	scanf_s("%d%d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			scanf_s("%d", &P[i][j]);
		}
	}

	solve();
	fclose(stream);

	return 0;
}
