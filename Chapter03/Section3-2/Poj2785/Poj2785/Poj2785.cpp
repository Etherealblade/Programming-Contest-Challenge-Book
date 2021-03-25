/*
Page 160
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N 6

int A[] = { -45,-41,-36,-36,26,-32 };
int B[] = { 22, -27,53,30,-38,-54 };
int C[] = { 42,56,-37,-75,-10,-6 };
int D[] = { -16,30,77,-46,62,45 };

int CD[N*N];	// C和D中数字的组合方法

void solve()
{
	// 枚举从C和D中取出数字的所有方法
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			CD[i*N + j] = C[i] + D[j];
		}
	}
	sort(CD, CD + N * N);

	long long res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cd = -(A[i] + B[j]);
			//取出C和D中和为cd的部分
			res += upper_bound(CD, CD + N * N, cd) -
				lower_bound(CD, CD + N * N, cd);
		}
	}
	printf_s("%lld\n", res);
}

int main()
{
	solve();
}
