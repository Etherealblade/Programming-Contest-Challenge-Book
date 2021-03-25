/*
Page 153
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 8

// input
int M, N;

// 输入, 0白, 1黑
int tile[MAX_N][MAX_N];


// 格子坐标
const int dx[5] = { -1,0,0,0,1 };
const int dy[5] = { 0,-1,0,1,0 };



int opt[MAX_N][MAX_N];	// 保存最优解
int flip[MAX_N][MAX_N];	// 保存中间结果

int get(int x, int y)
{
	// 查询(x,y)的颜色
	int c = tile[x][y];
	for (int d = 0; d < 5; d++)
	{
		int x2 = x + dx[d],
			y2 = y + dy[d];
		if (x2 >= 0 && x2 < M &&
			y2 >= 0 && y2 < N)
		{
			c += flip[x2][y2];
		}
	}
	return c % 2;
}

int calc()
{
	// 求出第1行确定情况下的最少操作次数
	// 不存在解的话返回-1
	// 求出从第2行开始的翻转方法
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (get(i - 1, j) != 0)
			{
				// (i-1,j)是黑色的话, 则必须翻转这个格子
				flip[i][j] = 1;
			}
		}
	}

	// 判断最后一行是否全白
	for (int j = 0; j < N; j++)
	{
		/*
		what if 最后一行全白, 但是其他行有黑?
		为何最后一行是否全白,可以作为方案的标准
		*/
		if (get(M - 1, j) != 0)
		{
			//no solution
			return -1;
		}
	}

	// 统计翻转的次数
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res += flip[i][j];
		}
	}

	return res;
}

void solve()
{
	int res = -1;

	// 按照字典序尝试第一行的所有可能性
	for (int i = 0; i < 1 << N; i++)
	{
		/*
		int i = 0; i < 1 << N; i++
		将集合{0,1,...,n-1}的所有自己枚举出来
		*/
		memset(flip, 0, sizeof(flip));
		for (int j = 0; j < N; j++)
		{
			flip[0][N - j - 1] = i >> j & 1;
			/*
			i >> j & 1
			第j个元素属于集合i
			*/
		}

		int num = calc();
		if (num >= 0 && (res<0 || res>num))
		{
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}

	if (res < 0)
	{
		//no solution
		printf_s("Impossible\n");
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 此题很难, 但是能学个打印方式也不错
				cout << opt[i][j] <<
					(j + 1 == N ? '\n' : ' ');
			}
		}
		cout << endl;
	}
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int couter = 2;
	while (couter > 0)
	{
		cin >> M;
		cin >> N;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> tile[i][j];
			}
		}

		solve();
		couter--;
	}

	fclose(file);
	return 0;
}

