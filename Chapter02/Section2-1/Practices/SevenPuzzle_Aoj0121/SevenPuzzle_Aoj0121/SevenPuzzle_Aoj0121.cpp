/*
bfs + dp
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<string, int> dp;
int direction[4] = { 1, -1, 4, -4 };

void bfs()
{
	queue<string> que;
	que.push("01234567");
	dp["01234567"] = 0;

	while (!que.empty())
	{
		string now = que.front();
		que.pop();

		// p是'0'的位置
		int p = 0;
		for (int j = 0; j < 8; ++j)
		{
			if (now[j] == '0')
			{
				p = j;
				break;
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int n = p + direction[i];
			if (0 <= n && n < 8 &&
				!(p == 3 && i == 0) && // 右上角不能再往右了
				!(p == 4 && i == 1))   // 左下角不能再往左了
			{
				string next = now;
				swap(next[p], next[n]);
				if (dp.find(next) == dp.end())	
				{
					// 上面的if 应该是在end()之前没有相等的value, 
					// 所以干脆就等于end了, 意思是搜索完毕了
					dp[next] = dp[now] + 1;
					que.push(next);
				}

			}
		}

	}

}


int main()
{
	bfs();
	string line;
	while (getline(cin, line))
	{
		auto r = remove(line.begin(), line.end(), ' ');
		line.erase(r, line.end());
		// remove 剥离掉' ', 那erase的目的是什么? 
		// 调试给出的值很诡异! 对string的库函数不熟悉...
		cout << dp[line] << endl;
	}

	return 0;
}
