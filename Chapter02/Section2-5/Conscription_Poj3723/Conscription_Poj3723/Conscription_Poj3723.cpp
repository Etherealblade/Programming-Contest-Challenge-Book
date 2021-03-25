/* 
Page 109, 这题若是事先不懂"最大权森林问题"就根本没法做
*/
#include <iostream>
#include <algorithm>
#include "MST.h"
using namespace std;

// input
int N, M, R;
int x[MAX_V], y[MAX_V], d[MAX_V];

void solve()
{
	V = N + R;
	E = R;

	for (int i = 0; i < R; i++)
	{
		es[i] = edge(x[i], N + y[i], -d[i]);
	}

	cout << 10000 * (N + M) + kruskal() << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> M;
	cin >> R;
	for (int i = 0; i < R; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> y[i];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> d[i];
	}

	solve();

	fclose(file);
	return 0;
}