/*
Type: Greedy-Interval

Sample Input:

3 10
1 7
3 6
6 10

Sample Output

2

感悟:
1. 首先一定读懂题目, 题目没读懂就去copy别人的代码,
这样是不会有提高的.
2. 读懂了题目才会有思路, 有了思路才能转化成代码
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_COWS 2500

int N, T;
struct Cow
{
	int begin;	// 开始时间 
	int end;	// 结束时间 
};
Cow cow[MAX_COWS];


bool is_greater(const Cow& a, const Cow& b)
{
	return a.begin < b.begin ||
		(a.begin == b.begin && a.end > b.end);
}

int solve()
{
	int used_cows = 0;
	int end = 0;
	int index = 0;
	while (end < T)
	{
		int begin = end + 1;

		// 寻找一头既能从begin干起, 又能一直干到最远的牛
		for (int i = index; i < N; i++)
		{
			if (cow[i].begin <= begin)
			{
				// 能够覆盖起始点
				if (cow[i].end >= begin)
				{
					// 将终点延长到最远
					end = max(end, cow[i].end);
				}
			}
			else
			{
				// 不能覆盖起始点, 说明上一头牛的终点就是最远点
				// 需要换一头牛了
				index = i;
				// 这里为何要改变循环不变量的初始值?
				// 修改后跳出for, 所以没毛病
				break;
			}
		}

		// 没找到这样的牛, 这个case失败
		if (begin > end)
		{
			return -1;
		}
		else
		{
			++used_cows;
		}
	}

	return used_cows;
}

int main()
{
	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		cin >> cow[i].begin >> cow[i].end;
	}
	sort(cow, cow + N, is_greater);
	cout << solve() << endl;

	return 0;
}

