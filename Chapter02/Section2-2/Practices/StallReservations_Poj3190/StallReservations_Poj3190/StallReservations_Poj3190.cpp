/*
Type: Greedy-Interval

Sample Input

5
1 10
2 4
3 6
5 8
4 7

Sample Output

4
1
2
3
2
4

总结:
1. 没弄懂Input和Output之间的关系
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Section
{
	unsigned int index;
	unsigned int begin;
	unsigned int end;
	bool operator < (const Section& b) const
	{
		return begin < b.begin;
	}
};

struct Stall
{
	unsigned int id;
	unsigned int end;
	bool operator < (const Stall& b) const
	{
		return end > b.end;	// 评论里有疑问
	}
	Stall() {}
	Stall(unsigned int id,
		unsigned int end) :id(id), end(end) {}
};

#define MAX_COWS 5000
Section cow[MAX_COWS];
unsigned int result[MAX_COWS]; // 每头牛从属于哪个牛栏
priority_queue<Stall> que;
// 最小堆，储存所有牛栏区间的结束点（也就是最右端）

void put_cow(const int& i, const bool& new_stall)
{
	Stall s;

	if (new_stall)
	{
		s.id = que.size() + 1;
	}
	else
	{
		s.id = que.top().id;
		que.pop();
	}

	s.end = cow[i].end;
	result[cow[i].index] = s.id;
	que.push(s);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cow[i].index = i;
		cin >> cow[i].begin;
		cin >> cow[i].end;
	}

	sort(cow, cow + N);
	put_cow(0, true);

	for (int i = 1; i < N; ++i)
	{
		put_cow(i, cow[i].begin <= que.top().end);
	}

	cout << que.size() << endl;
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}

