/*
Type: Basic DP
定义dp[i]表示第i个时间段挤奶能够得到的最大值，拆开来说，
就是前面 i – 1个时间段任取0到i – 1个时间段挤奶，然后加上
这个时间段（i）的产奶量之和。dp[i]满足如下递推关系：

第i个时间段挤奶的最大值 = 前 i – 1 个时间段挤奶最大值中的最大值 +
第i次产奶量。

注意此处的第i个时间段不等同于第i次

此题的代码非常清晰
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval
{
	int starting_hour, ending_hour, efficiency;
	bool operator < (const Interval& i) const
	{
		return starting_hour < i.starting_hour;
	}
};

Interval interval[1024];
int dp[1024];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; ++i)
	{
		cin >> interval[i].starting_hour >>
			interval[i].ending_hour >>
			interval[i].efficiency;

		// 实际的结束时间还需要加上休息时间
		interval[i].ending_hour += R;
	}

	sort(interval, interval + M);

	for (int i = 0; i < M; ++i)
	{
		dp[i] = interval[i].efficiency;

		for (int j = 0; j < i; ++j)
		{
			if (interval[j].ending_hour <=
				interval[i].starting_hour)
			{
				dp[i] = max(dp[i], dp[j] +
					interval[i].efficiency);
			}
		}
	}

	cout << *max_element(dp, dp + M) << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

