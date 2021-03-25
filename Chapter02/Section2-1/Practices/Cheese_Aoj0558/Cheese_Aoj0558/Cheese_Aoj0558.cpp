/*
bfs

Input:
10 10 9
.X...X.S.X
6..5X..X1X
...XXXX..X
X..9X...X.
8.X2X..X3X
...XX.X4..
XX....7X..
X..X..XX..
X...X.XX..
..X.......

output:
91
*/

#include <iostream>
#include <iostream>
#include <queue>
using namespace std;
int w, h, n;
char map[1024][1024];
// 各点到当前工厂的距离
int d[1024][1024];
const int direction[4][2] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int factory[16][2];
typedef pair<int, int> P;

int bfs(const int& sx, const int& sy,
	const int& gx, const int& gy)
{
	//memset(d, -1, sizeof(d)); // hankcs也犯了这种错...
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			d[j][i] = -1;
		}
	}

	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	while (que.size())
	{
		P p = que.front();
		que.pop();

		// if 是终点就结束
		if (p.first == gx && p.second == gy)
		{
			break;
		}

		// 4向遍历
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.first + direction[i][0];
			int ny = p.second + direction[i][1];

			// 判断是否可以移动
			if (0 <= nx && nx < w && 0 <= ny &&
				ny < h && map[nx][ny] != 'X' &&
				d[nx][ny] == -1)
			{
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}

	return d[gx][gy];
}

int main()
{
	cin >> h >> w >> n;
	for (int i = 0; i < h; ++i)	// row
	{
		for (int j = 0; j < w; ++j)	// column
		{
			cin >> map[i][j];	// 这里要注意对应关系
			// 这里看着真别扭, 而且很烧脑
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (map[j][i] == 'S')
			{
				factory[0][0] = j;
				factory[0][1] = i;
				map[j][i] = '.';
			}
			else if (isdigit(map[j][i]))
			{
				int index = map[j][i] - '0';
				factory[index][0] = j;
				factory[index][1] = i;
			}
		}
	}

	int step = 0;
	for (int i = 0; i < n; ++i)
	{
		// 按顺序吃
		step += bfs(factory[i][0], factory[i][1],
			factory[i + 1][0], factory[i + 1][1]);
	}

	cout << step << endl;

	return 0;
}
