/*
Type: Greed-Other

总结:
1. 确定题目类型之后, 要快速选择相关的DS,
此题就用了最大堆
2. 此题不难, 还算有点人性
*/
#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	priority_queue<double> que;

	for (int i = 0; i < N; ++i)
	{
		double l;
		cin >> l;
		que.push(l);
	}

	while (que.size() != 1)
	{
		double a = que.top(); que.pop();
		double b = que.top(); que.pop();
		que.push(2 * sqrt(a * b));
	}

	cout.setf(ios::fixed);
	cout.precision(3);
	cout << que.top() << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}

