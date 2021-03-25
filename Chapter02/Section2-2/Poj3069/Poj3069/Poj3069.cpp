/*
Page 45
若没有从理解题目到自己独立完整地写出代码,抄再多没用...
再次陷入深深的无助之中...

*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

// input
int N, R;
int X[MAX_N];

void solve()
{
	sort(X, X + N);

	int i = 0, ans = 0;

	while (i < N)
	{
		// s 是没有被覆盖的最左的点的位置
		int s = X[i++];

		// 一直向右前进直到距s的距离大于R的点
		while (i < N && X[i] <= s + R)
		{
			i++;
		}

		// p 是新加上标记的点的位置
		int p = X[i - 1];
		// 一直向右前进直到距p的距离大于R的点
		while (i < N && X[i] <= p + R)
		{
			i++;
		}

		ans++;
	}

	cout << ans << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> R;

	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
	}

	solve();

	fclose(file);
}
