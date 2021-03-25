// Page 196

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10

// input
int n, m;
bool color[MAX_N][MAX_N];	// 0: white, 1: black

int rec(int i, int j, bool used[MAX_N][MAX_N])
{
	// 现在查看格子是(i,j), used 表示哪些格子已经被覆盖过
	if (j == m)
	{
		// 到下一行
		return rec(i + 1, 0, used);
	}

	if (i == n)
	{
		// 已经覆盖了所有的空格
		return 1;
	}

	if (used[i][j] || color[i][j])
	{
		// 不需要再(i,j)上放置砖块
		return rec(i, j + 1, used);
	}

	// 尝试2中放法
	int res = 0;
	used[i][j] = true;
	// 横着放
	if (j + 1 < m && !used[i][j + 1] && !color[i][j + 1])
	{
		used[i][j + 1] = true;
		res += rec(i, j + 1, used);
		used[i][j + 1] = false;
	}
	// 竖着放
	if (i + 1 < n && !used[i + 1][j] && !color[i + 1][j])
	{
		used[i + 1][j] = true;
		res += rec(i, j + 1, used);
		used[i + 1][j] = false;
	}

	used[i][j] = false;
	return res;
}

void solve_rec()
{
	bool used[MAX_N][MAX_N];
	memset(used, 0, sizeof(used));
	cout << "solve_rec: " << rec(0, 0, used) << endl;
}

int dp[2][1 << MAX_N];	// dp 数组(滚动数组循环利用)
void solve_dp()
{
	int *crt = dp[0], *next = dp[1];
	crt[0] = 1;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			for (int used = 0; used < 1 << m; used++)
			{
				if ((used >> j & 1) || color[i][j])
				{
					// 不需要再(i,j)放置砖块
					next[used] = crt[used & ~(1 << j)];
				}
				else
				{
					// 尝试2种放法
					int res = 0;
					// 横着放
					if (j + 1 < m && !(used >> (j + 1) & 1)
						&& !color[i][j + 1])
					{
						res += crt[used | 1 << (j + 1)];
					}
					// 竖着放
					if (i + 1 < n && !color[i + 1][j])
					{
						res += crt[used | 1 << j];
					}

					next[used] = res;
				}
			}
			swap(crt, next);
		}
	}

	cout << "solve_dp: " << crt[0] << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> color[i][j];
		}
	}

	solve_rec();
	solve_dp();

	fclose(file);
	return 0;
}

