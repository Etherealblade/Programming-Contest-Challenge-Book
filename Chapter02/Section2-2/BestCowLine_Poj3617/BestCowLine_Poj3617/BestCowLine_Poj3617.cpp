/*
Page 43. 要多练才能把思路快速转化成代码

test date:
6
ACDBCB
*/

#include <iostream>
using namespace std;

#define MAX_N 100

int N;
char S[MAX_N + 1];

void solve()
{
	// 剩余的字符串为S[a], S[a+1], ... , S[b]
	int a = 0, b = N - 1;

	while (a <= b)
	{
		// 将从左起和从右起的字符串比较
		bool left = false;

		for (int i = 0; i + a < b; i++)
		{
			if (S[a + i] < S[b - i])
			{
				left = true;
				break;
			}
			else if (S[a + i] > S[b - i])
			{
				left = false;
				break;
			}

		}

		if (left)
		{
			cout << S[a++];
		}
		else
		{
			cout << S[b--];
		}
	}

	cout << endl;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}

	solve();
}