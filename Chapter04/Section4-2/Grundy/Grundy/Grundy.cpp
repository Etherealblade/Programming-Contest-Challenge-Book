/*
Page 315

test data 1:
3 3
1 3 4
5 6 7
此处应该输出Alice, 但是代码有误...

test data 2:
3 3
1 3 4
5 6 8
*/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define MAX_N 1024

int N, K;
int A[MAX_N];
int X[MAX_N];
int grundy[MAX_N];	// 利用dp计算grundy值的数组

void solve()
{
	grundy[0] = 0;	// 轮到自己时剩0枚则必败

	// 计算grundy值
	int max_x = *max_element(X, X + N);
	for (int j = 1; j <= max_x; j++)
	{
		set<int> s;

		for (int i = 0; i < K; i++)
		{
			if (A[i] <= j)
			{
				s.insert(grundy[j - A[i]]);
			}
		}

		int g = 0;
		while (s.count(g) != 0)
		{
			g++;
		}

		grundy[j] = g;
	}

	// 判断胜负
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		x ^= grundy[X[i]];
	}

	if (x != 0)
	{
		cout << "Alice" << endl;
	}
	else
	{
		cout << "Bob" << endl;
	}
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> N;
		cin >> K;

		for (int i = 0; i < N; i++)
		{
			cin >> A[i];	// 之前写的代码是: X[i], 导致输出总是Bob
		}

		for (int i = 0; i < K; i++)
		{
			cin >> X[i];	// 之前写的代码是: A[i], 导致输出总是Bob
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}
