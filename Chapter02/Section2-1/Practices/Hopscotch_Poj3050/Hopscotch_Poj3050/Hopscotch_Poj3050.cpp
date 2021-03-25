/*
Sample Input
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

Sample Output
15
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int map[5][5];
const int direction[4][2] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};
set<int> results;

void dfs(const int& x, const int& y,
	const int& step, const int& number)
{
	if (step == 5)
	{
		// 跳房子结束
		results.insert(number);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			dfs(nx, ny, step + 1,
				number * 10 + map[nx][ny]);
		}
	}
}

int main()
{
	int i, j;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			cin >> map[j][i];
		}
	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			dfs(i, j, 0, map[i][j]);
		}
	}

	cout << endl << results.size() << endl;
	return 0;
}
