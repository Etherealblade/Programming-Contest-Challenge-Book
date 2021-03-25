// Page 239

#include <iostream>
#include <algorithm>
#include "min_cost_flow.h"
using namespace std;

#define MAX_M 16

// input
int N, M;
int a[MAX_M], b[MAX_M], c[MAX_M];

void solve()
{
	int s = 0, t = N - 1;
	V = N;

	for (int i = 0; i < M; i++)
	{
		add_edge(a[i] - 1, b[i] - 1, 1, c[i]);
		add_edge(b[i] - 1, a[i] - 1, 1, c[i]);
	}

	cout << min_cost_flow(s, t, 2) << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> M;
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
		cin >> c[i];
	}

	solve();

	fclose(file);
	return 0;
}

