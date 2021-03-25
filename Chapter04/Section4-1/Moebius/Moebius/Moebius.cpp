/*
Page 299
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "number_theory.h"
using namespace std;

const int MOD = 10009;
typedef long long ll;

int N;

map<int, int> Moebius(int n)
{
	map<int, int> res;
	vector<int> primes;

	// 枚举n的质因数
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			primes.push_back(i);
			while (n%i == 0)
			{
				n /= i;
			}
		}
	}

	if (n != 1)
	{
		primes.push_back(n);
	}

	int m = primes.size();
	for (int i = 0; i < (1 << m); i++)
	{
		int mu = 1, d = 1;
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				mu *= -1;
				d *= primes[j];
			}
		}

		res[d] = mu;
	}

	return res;
}

void solve()
{
	int res = 0;
	map<int, int> mu = Moebius(N);

	for (auto& i : mu)
	{
		res += i.second * mod_pow(26, N / i.first, MOD);
		res = (res%MOD + MOD) % MOD;
	}

	printf_s("%d\n", res);
}

int main()
{
	cin >> N;

	solve();

	return 0;
}

