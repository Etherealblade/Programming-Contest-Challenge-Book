/*
Page 269
*/
#include <iostream>
#include "Auxiliary_MaxFlow.h"

const int MAX = 8;
const int dx[4] = { -1,-1,1,1 };
const int dy[4] = { -1,0,-1,0 };
FILE *stream;

// Input
int M, N;
char seat[MAX][MAX];	// 座位

void solve()
{
	int num = 0;
	V = M * N;
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (seat[y][x] == '.')
			{
				num++;
				for (int k = 0; k < 4; k++)
				{
					int x2 = x + dx[k];
					int y2 = y + dy[k];

					if (x2 >= 0 && x2 < N && y2 >= 0 &&
						y2 < M && seat[y2][x2] == '.')
					{
						// 下一行略显诡异, 为何不是下下行, 下下行居然可得同样结果
						//add_edge(x*M + y, x2*M + y2);
						add_edge(y*N + x, y2*N + x2);

					}
				}
			}
		}
	}
	printf_s("%d\n", num - bipartite_matching());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen_s(&stream, "in.txt", "r", stdin);
#endif

	while (cin >> M >> N && M)
	{
		clear();
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> seat[i][j];
			}
		}

		solve();
	}


#ifndef ONLINE_JUDGE
	fclose(stream);
#endif

	return 0;
}

