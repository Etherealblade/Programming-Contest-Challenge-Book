/*
Page 303
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

// Input
int N, M;

ll mod_pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res = res * x%mod;
		}
		x = x * x%mod;
		n >>= 1;
	}

	return res;
}

vector<int> divisor(int n)
{
	vector<int> res;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			res.push_back(i);
			if (i != n / i)
			{
				res.push_back(n / i);
			}
		}
	}
	return res;
}

map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for (int i = 2; i*i <= n; i++)
	{
		while (n%i == 0)
		{
			++res[i];
			n /= i;

		}
	}

	if (n != 1)
	{
		res[n] = 1;
	}

	return res;
}

void solve()
{
	map<int, int> primes = prime_factor(N);
	vector<int> divs = divisor(N);
	ll res = 0;

	for (int i = 0; i < divs.size(); i++)
	{
		// 求divs[i]的欧拉函数值
		ll euler = divs[i];
		for (auto& it : primes)
		{
			int p = it.first;
			if (divs[i] % p == 0)
			{
				euler = euler / p * (p - 1);
			}
		}

		res += euler * mod_pow(M, N / divs[i], MOD) % MOD;
		res %= MOD;
	}

	printf_s("%lld\n", res*mod_pow(N, MOD - 2, MOD) % MOD);
}

int main()
{
	cin >> N;
	cin >> M;

	solve();

	return 0;
}
