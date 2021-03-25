/*
P150 反转
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 16

// input
int N;
int dir[MAX_N];	// 牛的方向, 0:F, 1:B
int f[MAX_N];	// 区间[i, i+K-1]是否进行反转

int calc(int k)
{
	/*
	固定K, 求对应的最小操作次数
	无解的话则返回-1
	*/
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0;	// f的和

	for (int i = 0; i + k <= N; i++)
	{
		// 计算区间[i,i+k-1]
		if ((dir[i] + sum) % 2 != 0)
		{
			// 前端的牛面朝后方
			res++;
			f[i] = 1;
		}

		sum += f[i];
		if (i - k + 1 >= 0)
		{
			sum -= f[i - k + 1];	// Why?
		}
	}

	// 检查剩下的k头牛是否有面朝后面的情况
	for (int i = N - k + 1; i < N; i++)
	{
		if ((dir[i] + sum) % 2 != 0)
		{
			// no solution, Why?
			return -1;
		}
		if (i - k + 1 >= 0)
		{
			sum -= f[i - k + 1];	// Why?
		}
	}

	return res;
}

void solve()
{
	int K = 1, M = N;
	for (int k = 1; k <= N; k++)
	{
		int m = calc(k);
		if (m >= 0 && M > m)
		{
			M = m;	//M 是次数
			K = k;	//K 是一次转K头牛
		}
	}
	printf_s("%d %d\n", K, M);
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int counter = 2;
	while (counter > 0)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> dir[i];
		}

		solve();
		counter--;
	}

	fclose(file);
	return 0;
}
