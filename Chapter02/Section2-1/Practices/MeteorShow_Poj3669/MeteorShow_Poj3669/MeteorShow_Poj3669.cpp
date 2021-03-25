/*
bfs
为何题目这么难理解
1. 抽象, 没法转化成具体的模型
2. 即使判断出题目类型(bfs), 脑中没有思路, 很难转化成代码
*/

#pragma warning(disable : 4996)

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define INDEX_MAX 512

int map[INDEX_MAX][INDEX_MAX];
bool visited[INDEX_MAX][INDEX_MAX];
struct Meteor
{
	int x, y, t;
};
typedef Meteor P;

Meteor m[50008];
int n;
const int direction[5][2] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
	{ 0, 0 },
};
int last;

int bfs()
{
	memset(visited, 0, sizeof(visited));
	queue<P> que;
	P current;
	current.x = 0;
	current.y = 0;

	// 当前花费时间
	current.t = 0;
	que.push(current);
	while (que.size())
	{
		// backup
		P p = que.front();
		que.pop();
		for (int j = 0; j < 4; j++)
		{
			current = p;
			current.x = current.x + direction[j][0];
			current.y = current.y + direction[j][1];
			++current.t;

			if (current.x >= 0 && current.y >= 0 &&
				map[current.x][current.y] > current.t
				&& !visited[current.x][current.y])
			{
				visited[current.x][current.y] = true;
				// 爆炸时间大于当前时间, 则安全
				if (map[current.x][current.y] > last)
				{
					// 当前位置爆炸时间大于流星雨最晚落下的时间,
					// 说明跑出了流星雨范围
					return current.t;
				}
				que.push(current);
			}
		}
	}
	return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].x >> m[i].y >> m[i].t;
	}

	// 地图中每个点的值表示最早在什么时候被炸毁
	memset(map, 0x7F, sizeof(map));
	for (int i = 0; i < n; ++i)
	{
		last = max(last, m[i].t);
		for (int j = 0; j < 5; ++j)
		{
			int nx = m[i].x + direction[j][0];
			int ny = m[i].y + direction[j][1];
			if (nx >= 0 && ny >= 0 &&
				map[nx][ny] > m[i].t)
			{
				map[nx][ny] = m[i].t;
			}
		}
	}
	if (map[0][0] == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << bfs() << endl;
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}

