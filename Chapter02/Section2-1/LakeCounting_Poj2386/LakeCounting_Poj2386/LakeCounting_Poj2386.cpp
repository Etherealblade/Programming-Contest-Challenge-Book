/*
Description:
挑战程序设计竞赛 P32

Keywords: bfs

ULR:
*/

#include <bits/stdc++.h>
using namespace std;

#define INTXT
const int MAX_N = 16;

// input
int N, M;
char field[MAX_N][MAX_N];

// current position(x,y)
void dfs(int x, int y)
{
	// replace 'W' with '.'
	field[x][y] = '.';

	//loop 8 directions
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = x + dx;
			int ny = y + dy;

			/*
			whether (nx, ny) is in the garden or not,
			and whether is 'w' or not
			*/
			if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
				field[nx][ny] == 'W')
			{
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef INTXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif

	// Input
	cin >> N;	// row
	cin >> M;	// col
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
		}
	}

	// Process
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (field[i][j] == 'W')
			{
				// start from a 'W'
				dfs(i, j);
				res++;
			}
		}
	}
	cout << "Puddles: " << res << '\n';

	return 0;
}