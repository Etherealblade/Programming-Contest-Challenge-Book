/*
https://www.cnblogs.com/-Wallace-/p/12670121.html
*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1E3;

typedef vector<int> vec;
typedef vector<vec>	mat;

int n;

mat operator * (mat a, mat b) {
	mat x(2, vec(2, 0));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				(x[i][j] += a[i][k] * b[k][j]) %= MOD;
	return x;
}

inline mat matI()
{
	mat x(2, vec(2, 0));
	x[0][0] = x[1][1] = 1;
	return x;
}

mat pow(mat base, int k) {
	if (!k)
		return matI();

	mat x = pow(base, k >> 1);
	if (k & 1) // 这里是如何推论出来的?
		return (x * x) * base;
	else
		return x * x;
}

int main()
{
	cin >> n;
	mat A(2, vec(2, 0));
	A[0][0] = 3;
	A[0][1] = 5;
	A[1][0] = 1;
	A[1][1] = 3;

	A = pow(A, n);

	printf_s("%03d\n", (A[0][0] * 2 - 1) % MOD);

	return 0;
}

