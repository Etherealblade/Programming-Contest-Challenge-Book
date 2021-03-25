/*
Type: Greedy- Other
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

struct Cow
{
	int T;
	int D;
	bool operator < (const Cow& c) const
	{
		return this->T * c.D < c.T * this->D;
	}
};
Cow cow[1000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	int total_destory = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> cow[i].T >> cow[i].D;
		total_destory += cow[i].D; // 总的损害
	}

	sort(cow, cow + N);	// non-descending order

	unsigned long long destroied = 0;
	for (int i = 0; i < N; i++)
	{
		total_destory -= cow[i].D;

		// 损害维持时间为2倍的 moving 牛耗时
		destroied += total_destory * cow[i].T * 2;
	}

	cout << destroied << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

