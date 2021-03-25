/*
Page 295
*/

#include <iostream>
#include <algorithm>
#include "number_theory.h"
using namespace std;

#define MAX_M 1024

typedef long long ll;

// Input
int arr[MAX_M];
int N, M;

void solve()
{
	ll res = 0;
	for (int i = 1; i < (1 << M); i++)
	{
		int num = 0;
		for (int j = i; j != 0; j >>= 1)
		{
			num += j & 1;	// i的二进制表示中1的数量
		}
		ll lcm = 1;
		for (int j = 0; j < M; j++)
		{
			if (i >> j & 1)
			{
				lcm = lcm / gcd(lcm, arr[j])*arr[j];
				// 如果lcm大于n, 则n/lcm=0. 因此在溢出之前break
				if (lcm > N)
				{
					break;
				}
			}
		}
		if (num % 2 == 0)
		{
			res -= N / lcm;
		}
		else
		{
			res += N / lcm;
		}
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
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> arr[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

