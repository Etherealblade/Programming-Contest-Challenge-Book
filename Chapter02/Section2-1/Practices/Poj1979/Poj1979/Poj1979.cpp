/*
test data:
6  9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.

*/
#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_W 20
#define MAX_H 20
char room[MAX_W][MAX_H];
int W, H;
const int direction[4][2] =
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int step = 0;

int dfs(const int& y, const int& x)
{
	room[y][x] = '#';
	++step;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + direction[i][1];
		int ny = y + direction[i][0];

		if (nx >= 0 && nx < W && ny >= 0 && ny < H
			&& room[ny][nx] == '.')
		{
			dfs(ny, nx);
		}
	}

	return step;
}

int main()
{

	scanf_s("%d%d", &W, &H);	// 6列, 9行

	int x, y;
	//for (y = 0; y < H; ++y)
	//{
	//	/*
	//	注意这里数据的构造, y对应于H行, x对应于W列
	//	*/
	//	for (x = 0; x < W; ++x)
	//	{
	//		//scanf_s("%c", &room[x][y]);	// 用scanf_s会返回28
	//		cin >> room[y][x];	// x 是行, y 是列
	//		// 这样输入岂不成了6*9, 而Input date中是9*6. 记住这输入方式
	//	}
	//}

	for (y = 0; y < H; y++)
	{
		for (x = 0; x < W; x++)
		{
			char node;
			cin >> node;	// 这里输入有空格, 上面的输入没有
			//scanf("%c", &node);	// 若把cin改成scanf, 则输出有误:28
			room[y][x] = node;
		}
	}


	bool found = false;
	for (y = 0; y < H; ++y)
	{
		for (x = 0; x < W; ++x)
		{
			if (room[y][x] == '@')
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			break;
		}
	}

	cout << dfs(y, x) << endl;

	return 0;
}
