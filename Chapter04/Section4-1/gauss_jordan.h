#include <iostream>
using namespace std;

const double EPS = 1E-8;

typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(mat A, vec b)
{
	// 求解Ax=b, 其中A是方阵
	// 当方程组无解or有无穷多解时, 返回一个长度为0的数组
	int n = A.size();
	mat B(n, vec(n + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}

	// 把b存放在A的右边方便一起处理
	for (int i = 0; i < n; i++)
	{
		B[i][n] = b[i];
	}

	for (int i = 0; i < n; i++)
	{
		// 把正在处理的未知数系数的绝对值最大的式子换到第i行
		int pivot = i;
		for (int j = i; j < n; j++)
		{
			if (abs(B[j][i]) > abs(B[pivot][i]))
			{
				pivot = j;
			}
		}
		swap(B[i], B[pivot]);

		// 无解or有无穷多解
		if (abs(B[i][i]) < EPS)
		{
			return vec();
		}

		// 把正在处理的未知数的系数变为1
		for (int j = i + 1; j <= n; j++)
		{
			B[i][j] /= B[i][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				// 从第j个式子中消去第i个未知数
				for (int k = i + 1; k <= n; k++)
				{
					B[j][k] -= B[j][i] * B[i][k];
				}
			}
		}
	}
	vec X(n);
	// 存放在右边的b就是答案
	for (int i = 0; i < n; i++)
	{
		X[i] = B[i][n];
	}
	return X;
}
