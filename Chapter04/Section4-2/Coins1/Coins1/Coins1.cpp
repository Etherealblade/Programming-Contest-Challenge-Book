/*
page 305
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_X 100

int X, K, Arr[MAX_X];
// 动态规划所用的数组
bool win[MAX_X + 1];

void solve()
{
	// 轮到自己时没有硬币了, 则失败
	win[0] = false;	// Alice 先手

	for (int j = 1; j <= X; j++)
	{
		// 如果可以让对手到达必败态, 则必胜
		win[j] = false;
		for (int i = 0; i < K; i++)
		{
			win[j] |= Arr[i] <= j && !win[j - Arr[i]];
			// 1. 运算优先级分不清
			// 2. 不知公式的具体含义
		}
	}

	if (win[X])
	{
		puts("Alice");
	}
	else
	{
		puts("Bob");
	}
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> X;
		cin >> K;

		for (int i = 0; i < K; i++)
		{
			cin >> Arr[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

