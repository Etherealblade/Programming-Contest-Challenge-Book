// Page 237

#include <iostream>
#include <algorithm>
#include "max_flow.h"
using namespace std;

#define MAX_N 100

// input
int N, M;
int A[MAX_N], B[MAX_N];
int a[MAX_N], b[MAX_N], w[MAX_N];

void solve()
{
	int s = N, t = s + 1;

	// 在各个核上执行所产生的费用
	for (int i = 0; i < N; i++)
	{
		add_edge(i, t, A[i]);
		add_edge(s, i, B[i]);
	}

	// 在不同的核上执行所产生的费用
	for (int i = 0; i < M; i++)
	{
		add_edge(a[i] - 1, b[i] - 1, w[i]);
		add_edge(b[i] - 1, a[i] - 1, w[i]);
	}

	cout << max_flow(s, t) << endl;
}



int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	// input
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> w[i];
	}

	solve();

	fclose(file);
	return 0;
}

