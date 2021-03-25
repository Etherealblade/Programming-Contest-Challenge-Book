/*
Page 47
Hoffman tree
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MAX_N	1000

// input
int N, L[MAX_N];

void solve()
{
	ll ans = 0;

	// 直到计算到模板为1块时为止
	while (N > 1)
	{
		// 求出最短板mii1和次短板mii2
		int mii1 = 0;
		int mii2 = 1;

		if (L[mii1] > L[mii2])
		{
			swap(mii1, mii2);
		}

		for (int i = 2; i < N; i++)
		{
			if (L[i] < L[mii1])
			{
				mii2 = mii1;
				mii1 = i;
			}
			else if (L[i] < L[mii2])
			{
				mii2 = i;
			}
		}

		// 将两块板拼接
		int t = L[mii1] + L[mii2];
		ans += t;

		if (mii1 == N - 1)
		{
			swap(mii1, mii2);
		}
		L[mii1] = t;
		L[mii2] = L[N - 1];
		N--;
	}

	cout << ans << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}

	solve();

	fclose(file);
}