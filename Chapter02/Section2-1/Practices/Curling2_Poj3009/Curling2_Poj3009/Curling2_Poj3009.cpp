/*
逻辑太难了(题目要求多), 如果精神状态不好, 还要强上这样的题, 真的会崩溃
*/
#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h;
int map[32][32];
int sx, sy;
int min_step;
const int direction[4][2] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

void dfs(const int& x, const int& y, int step)
{
	if (step >= 10 || step > min_step)
	{
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x;
		int ny = y;

		// 让石头往固定得方向一直飞
		while (nx >= 0 && nx < w &&
			ny >= 0 && ny < h)
		{
			switch (map[nx][ny])
			{
			case 0:
			{
				// 继续飞
				nx += direction[i][0];
				ny += direction[i][1];
			}
			break;

			case 3:
			{
				// 到家了
				if (step + 1 < min_step)
				{
					min_step = step + 1;
				}
				nx = -1;
			}
			break;

			case 1:
			{
				// 撞到了block
				if (!(nx - direction[i][0] == x &&
					ny - direction[i][1] == y))
				{
					//中间有空地, 不是紧挨着block
					// 石头消失
					map[nx][ny] = 0;
					// 后退一步
					dfs(nx - direction[i][0],
						ny - direction[i][1], step + 1);
					// 恢复地图, 供下一个方向尝试
					map[nx][ny] = 1;
				}
				// 开始下一个方向
				nx = -1;

			}
			break;

			default:
				break;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while (cin >> w >> h, w != 0)
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[j][i];
			}
		}
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[j][i] == 2)
				{
					sx = j;
					sy = i;
					i = h;
					break;
				}
			}
		}

		map[sx][sy] = 0;
		min_step = 11;
		dfs(sx, sy, 0);
		if (min_step > 10)
		{
			min_step = -1;
		}
		cout << min_step << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

