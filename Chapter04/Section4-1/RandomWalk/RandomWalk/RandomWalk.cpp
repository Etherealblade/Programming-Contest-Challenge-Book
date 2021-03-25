/*
Page 288
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "gauss_jordan.h"
using namespace std;

#define MAX_N 100

// Input
int N, M;
char grid[MAX_N][MAX_N];

bool can_goal[MAX_N][MAX_N];	// can_goal[x][y]为true的话, (x,y)可以达到终点
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y)
{
	// 搜索可以到达终点的点
	can_goal[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
			!can_goal[nx][ny] && grid[nx][ny] != '#')
		{
			dfs(nx, ny);
		}
	}

}

void solve()
{
	mat A(N*M, vec(N*M, 0));
	vec b(N*M, 0);

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			can_goal[x][y] = false;
		}
	}

	dfs(N - 1, M - 1);

	// 构建矩阵
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			// 到达终点, 或者是(x,y)无法到达终点的情况
			if (x == N - 1 && y == M - 1 ||
				!can_goal[x][y])
			{
				A[x*M + y][x*M + y] = 1;
				continue;
			}

			// 其他情况
			int move = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M
					&& grid[nx][ny] == '.')
				{
					A[x*M + y][nx*M + ny] = -1;
					move++;
				}
			}

			b[x*M + y] = A[x*M + y][x*M + y] = move;
		}
	}

	vec res = gauss_jordan(A, b);
	printf_s("%.8f\n", res[0]);
}

int main()
{

	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 3;
	while (count > 0)
	{
		cin >> N;
		cin >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> grid[i][j];
			}
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

