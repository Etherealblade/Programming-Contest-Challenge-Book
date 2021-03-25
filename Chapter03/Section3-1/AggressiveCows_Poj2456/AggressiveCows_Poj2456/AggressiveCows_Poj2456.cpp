/*
Page 142
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

// input
int N, M;
int x[MAX_N];

bool judge(int d)
{
	int last = 0;
	for (int i = 1; i < M; i++)
	{
		int crt = last + 1;
		while (crt < N && x[crt] - x[last] < d)
		{
			crt++;
		}
		if (crt == N)
		{
			return false;
		}
		last = crt;
	}

	return true;
}

void solve()
{
	// 最开始时对x数组排序
	sort(x, x + N);

	// initialize
	int lb = 0, ub = MAX_N;

	while (ub - lb > 1)
	{
		int mid = (lb + ub) / 2;
		if (judge(mid))
		{
			lb = mid;
		}
		else
		{
			ub = mid;
		}
	}

	cout << lb << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	solve();

	fclose(file);
}
