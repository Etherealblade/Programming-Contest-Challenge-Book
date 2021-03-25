/*
Page 326

Sample Input:

2
480 540 30
495 540 20

Sample Output:

YES
08:00 08:30
08:40 09:00

*/

#include <iostream>
#include <algorithm>
#include "scc.h"
using namespace std;

// Input:
int N;
int *S, *T, *D;	// S和T是换算成分钟后的时间

void solve()
{
	V = N * 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (min(S[i] + D[i], S[j] + D[j]) >
				max(S[i], S[j]))
			{
				add_edge(i, N + j);
				add_edge(j, N + i);
			}

			if (min(S[i] + D[i], T[j]) >
				max(S[i], T[j] - D[j]))
			{
				add_edge(i, j);
				add_edge(N + j, N + i);
			}

			if (min(T[i], S[j] + D[j]) >
				max(T[i] - D[i], S[j]))
			{
				add_edge(N + i, N + j);
				add_edge(j, i);
			}

			if (min(T[i], T[j]) >
				max(T[i] - D[i], T[j] - D[j]))
			{
				add_edge(N + i, j);
				add_edge(N + j, i);
			}
		}
	}
	scc();

	// 判断是否可满足
	for (int i = 0; i < N; i++)
	{
		if (cmp[i] == cmp[N + i])
		{
			printf_s("\nNo\n");
			return;
		}
	}
	// 如果可满足, 则给出一组解
	printf_s("\nYes\n");
	for (int i = 0; i < N; i++)
	{
		if (cmp[i] > cmp[N + i])
		{
			// x_i为真, 即在结婚仪式开始时举行
			printf_s("%02d:%02d %02d:%02d\n",
				S[i] / 60, S[i] % 60, (S[i] + D[i]) / 60,
				(S[i] + D[i]) % 60);

		}
		else
		{
			// x_i为假, 即在结婚仪式结束时举行
			printf_s("%02d:%02d %02d:%02d\n",
				(T[i] - D[i]) / 60, (T[i] - D[i]) % 60,
				T[i] / 60, T[i] % 60);
		}
	}
}

int main()
{
	scanf_s("%d", &N);
	S = new int[N];
	T = new int[N];
	D = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d%d%d", &S[i], &T[i], &D[i]);
	}

	solve();

	return 0;
}

