/*
Page 117
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAX_N 10000
typedef long long ll;

bool is_prime(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}

	return n != 1;	// 1是例外
}

vector<int> divisor(int n)
{
	vector<int> res;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			res.push_back(i);

			if (n != n / i)
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

int prime[MAX_N];		// 第i个素数
bool isPrime[MAX_N];	// isPrime为true 表示i是个素数
int sieve(int n)
{
	int p = 0;
	for (int i = 0; i <= n; i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
		{
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	return p;
}

bool isPrime1[MAX_N];
bool is_prime_small[MAX_N];
void segment_sieve(ll a, ll b)
{
	// 对区间[a, b)内得整数执行筛选,若isPrime1[i-a]=true, 
	// 则i是prime
	for (int i = 0; (ll)i*i < b; i++)
	{
		is_prime_small[i] = true;
	}
	for (int i = 0; i < b - a; i++)
	{
		isPrime1[i] = true;
	}

	for (int i = 2; (ll)i*i < b; i++)
	{
		if (is_prime_small[i])
		{
			for (int j = 2 * i; (ll)j*j < b; j += j)
			{
				// 筛选[2, 根号b)
				is_prime_small[j] = false;
			}
			for (ll j = max(2LL, (a + i - 1) / i)*i;
				j < b; j += i)
			{
				// 筛选[a,b)
				isPrime1[j - a] = false;
			}
		}
	}
}

ll mod_pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res = res * x%mod;	// 若二进制最低位为1, 则乘上x^(2^i)
			x = x * x%mod;		// 将x平方
			n >>= 1;
		}

		return res;
	}
}

ll mod_pow1(ll x, ll n, ll mod)
{
	if (n == 0)
	{
		return 1;
	}
	ll res = mod_pow1(x*x%mod, n / 2, mod);
	if (n & 1)
	{
		res = res * x%mod;
	}

	return res;
}

int main()
{


}
