/*
挑战程序设计竞赛 P35
*/

#include <iostream>
#include <queue>
using namespace std;
#define N 10

typedef pair<int, int> P;

const int INF = 100000;
int sx = 0, sy = 1;	//起点S的坐标
int ex = 9, ey = 8;	//终点E的坐标

int d[N][N];	//各个pos到起点的距离

char maze[N][N] = {
{'#','S','#','#','#','#','#','#','.','#',},
{'.','.','.','.','.','.','#','.','.','#',},
{'.','#','.','#','#','.','#','#','.','#',},
{'.','#','.','.','.','.','.','.','.','.',},
{'#','#','.','#','#','.','#','#','#','#',},
{'.','.','.','.','#','.','.','.','.','#',},
{'.','#','#','#','#','#','#','#','.','#',},
{'.','.','.','.','#','.','.','.','.','.',},
{'.','#','#','#','#','.','#','#','#','.',},
{'.','.','.','.','#','.','.','.','E','#',}
};

// 4 directions of vectors
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs()
{
	queue<P> que;

	//initialize every position as 0
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			d[i][j] = INF;
		}
	}

	//将起点加入队列, 并把这一地点的距离设置为0
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	//不断循环直到队列的长度为0
	while (que.size())
	{
		//从队列的最前端取出元素
		P p = que.front();
		que.pop();

		//若取出的状态是终点,则结束
		if (p.first == ex && p.second == ey)
		{
			break;
		}

		// 4个方向的循环
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			// 两次在判断这里写错了
			if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
				maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				//可以移动, 则加到queue, 并且到该位置的距离更新为p的距离+1
				que.push(P(nx, ny));	//这写法有点新颖
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[ex][ey];
}


int main()
{
	int res = bfs();
	cout << "Steps: " << res;
}

