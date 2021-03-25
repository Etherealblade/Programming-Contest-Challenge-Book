/*
Page 127.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Input:
int N;
int **Mat;		// Matrix

int *A;			// A[i]表示第i行最后出现1的位置: 1~n-1

void solve()
{
	int res = 0;	// result
	for (int i = 0; i < N; i++)
	{
		A[i] = -1;	// 如果第i行不含1的话, 就当作-1
		for (int j = 0; j < N; j++)
		{
			if (Mat[i][j] == 1)
			{
				A[i] = j;	// good idea
			}
		}
	}

	for (int i = 0; i < N; i++)	// 冒泡
	{
		int pos = -1;	// 要移动到第i行的行 
		for (int j = i; j < N; j++)
		{
			if (A[j] <= i)	// 最后一个1的位置小于当前行
			{
				pos = j;
				break;
			}
		}

		// 交换
		for (int k = pos; k > i; k--)
		{
			swap(A[k], A[k - 1]);
			res++;
		}
	}

	printf_s("%d\n", res);
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 3;
	while (count > 0)
	{
		scanf_s("%d", &N);
		Mat = new int *[N];
		for (int i = 0; i < N; i++)
		{
			Mat[i] = new int[N];
		}
		A = new int[N];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf_s("%d", &Mat[i][j]);
			}
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

