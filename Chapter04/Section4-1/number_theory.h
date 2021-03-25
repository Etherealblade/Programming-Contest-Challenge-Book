#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1024
typedef long long ll;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int extgcd(int a, int b, int& x, int& y)
{
	int d = a;
	if (b != 0)
	{
		d = extgcd(b, a / b, y, x);
		y -= (a / b)*x;
	}
	else
	{
		x = 1;
		y = 0;
	}

	return d;
}

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

int mod_inverse(int a, int m)
{
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;

}

int euler_phi(int n)
{
	int res = n;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			res = res / i * (i - 1);
			for (; n%i == 0; n /= i);
		}
	}
	if (n != 1)
	{
		res = res / n * (n - 1);
	}
	return res;
}

int euler[MAX_N];
void euler_phi2()
{
	for (int i = 0; i < MAX_N; i++)
	{
		euler[i] = i;
	}

	for (int i = 2; i < MAX_N; i++)
	{
		if (euler[i] == i)
		{
			for (int j = i; j < MAX_N; j++)
			{
				euler[j] = euler[j] / i * (i - 1);
			}
		}
	}
}

pair<int, int> linear_congruence(
	const vector<int>& A,
	const vector<int>& B,
	const vector<int>& M)

{
	// 由于最开始没有任何限制, 所以先把解设为表示
	// 所有整数的x=0 (mod 1)
	int x = 0, m = 1;

	for (int i = 0; i < A.size(); i++)
	{
		int a = A[i] * m;
		int b = B[i] - A[i] * x;
		int d = gcd(M[i], a);

		if (b%d != 0)
		{
			return make_pair(0, -1);	// 无解
			int t = b / d * mod_inverse(
				a / d, M[i] / d) % (M[i] / d);
			x = x + m * t;
			m *= M[i] / d;
		}
	}
	return make_pair(x%m, m);
}

int fact[MAX_N];
int mod_fact(int n, int p, int& e)
{
	e = 0;
	if (n == 0)
	{
		return 1;
	}

	// 计算p的倍数的部分
	int res = mod_fact(n / p, p, e);
	e += n / p;

	if (n / p % 2 != 0)
	{
		return res * (p - fact[n%p]) % p;
	}
	return res * fact[n%p] % p;
}

int  mod_comb(int n, int k, int p)
{
	if (n < 0 || k < 0 || n < k)
	{
		return 0;
	}
	int e1, e2, e3;
	int a1 = mod_fact(n, p, e1);
	int a2 = mod_fact(k, p, e2);
	int a3 = mod_fact(n - k, p, e3);

	if (e1 > e2 + e3)
	{
		return 0;
	}

	return a1 * mod_inverse(a2*a3%p, p) % p;
}