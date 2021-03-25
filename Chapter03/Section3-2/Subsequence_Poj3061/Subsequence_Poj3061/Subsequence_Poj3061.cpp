/*
挑战程序设计竞赛 Page146.
这个循环要配合Page148的流程图才能理解
此题是下标区间的操作的好例子
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

// input
int N, S;
int arr[MAX_N];

void solve()
{
	int res = N + 1;
	int s = 0, t = 0, sum = 0;
	for (;;)
	{
		while (t < N&&sum < S)
		{
			sum += arr[t++];
		}

		if (sum < S)
		{
			break;
		}

		res = min(res, t - s);
		sum -= arr[s++];
	}

	if (res > N)
	{
		// 解不存在
		res = 0;
	}

	printf_s("%d\n", res);
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> N;
		cin >> S;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

