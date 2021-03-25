// Page 277, 未得到预期结果

#include <iostream>
#include <algorithm>
#include "DisjoinedSet.h"
using namespace std;
typedef long long ll;

int prime[1000000];	// 不超过1000000的第i个素数
int p;				// 素数的个数

// input
ll A, B, P;

void solve()
{
	int len = B - A + 1;
	init(len);

	for (int i = 0; i < p; i++)
	{
		// 对不小于p的素数进行处理
		if (prime[i] >= p)
		{
			// 不小于A的最小的prime[i]的倍数
			ll start = (A + prime[i] - 1) /
				prime[i] * prime[i];

			// 不大于B的最大的prime[i]的倍数
			ll end = B / prime[i] * prime[i];

			for (ll j = start; j <= end; j += prime[i])
			{
				// start 和j 属于同一个集合
				unite(start - A, j - A);
			}
		}

	}
	int res = 0;
	for (ll i = A; i <= B; i++)
	{
		// find(i)==i时, i就是并查集的根
		// 集合的个数等于根的个数
		if (find(i - A) == i - A)
		{
			res++;
		}
	}

	cout << res << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> A;
		cin >> B;
		cin >> P;

		solve();
		count--;
	}

	fclose(file);
	return 0;
}
