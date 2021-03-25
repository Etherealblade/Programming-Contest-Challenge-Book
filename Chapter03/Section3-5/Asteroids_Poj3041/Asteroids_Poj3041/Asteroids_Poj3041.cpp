// Page 228
#include <iostream>
#include <algorithm>
#include "bipartite_matching.h"
using namespace std;

#define MAX_N 100

// input
int N, K;
int R[MAX_N], C[MAX_N];


void solve()
{
	V = N * 2;
	for (int i = 0; i < K; i++)
	{
		add_edge(R[i] - 1, N + C[i] - 1);
	}

	cout << bipartite_matching() << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> R[i];
	}
	for (int i = 0; i < K; i++)
	{
		cin >> C[i];
	}

	solve();

	fclose(file);
	return 0;
}

