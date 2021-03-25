/*
Type: Greedy-Interval

Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0

Sample Output

Case 1: 2
Case 2: 1

总结:
1. 这道题题目总算读懂了, 脑海里也形成了思路
2. 但为何还是没有勇气抛开"拐杖"? 不肯花费时间去整理思路
担心写的代码太丑.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

// 区间
struct Section
{
	double begin;
	double end;
	bool operator < (const Section& b) const
	{
		return begin < b.begin;
	}
};


int main()
{
	int n, d, __id;
	__id = 0;

	while (cin >> n >> d && n > 0)
	{
		int result = 0;
		vector<Section> s(n);

		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;

			if (result == -1)
			{
				continue;
			}
			if (y > d)
			{
				// 如果y比半径大, 一定不能覆盖
				result = -1;
				continue;
			}

			double r = sqrt(d*d - y * y);
			s[i].begin = x - r;
			s[i].end = x + r;
		}

		if (result == -1)
		{
			cout << "Case " << ++__id << ": " <<
				result << endl;
			continue;
		}

		sort(s.begin(), s.end());
		double end = -numeric_limits<double>::max();
		for (auto it : s)
		{
			if (end < it.begin)
			{
				++result;
				end = it.end;
			}
			else if (end > it.end)
			{
				end = it.end;
			}
		}

		cout << "Case " << ++__id << ": " <<
			result << endl;
	}

	return 0;
}

