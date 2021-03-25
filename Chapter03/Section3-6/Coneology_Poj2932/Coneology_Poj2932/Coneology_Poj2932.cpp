// Page 258

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "computational_geometry.h"
using namespace std;

#define MAX_N 16

// input
int N;
double x[MAX_N], y[MAX_N], r[MAX_N];

bool inside(int i, int j)
{
	// 判断圆i是否在圆j的内部
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return dx * dx + dy * dy <= r[j] * r[j];
}

void solve()
{
	// 枚举关键点
	vector<pair<double, int>> events;
	for (int i = 0; i < N; i++)
	{
		events.push_back(make_pair(x[i] - r[i], i));
		events.push_back(make_pair(x[i] + r[i], i + N));
	}
	sort(events.begin(), events.end());

	// 平面扫描
	set<pair<double, int>> outers;
	vector<int> res;

	for (int i = 0; i < events.size(); i++)
	{
		int id = events[i].second % N;
		if (events[i].second < N)
		{
			set<pair<double, int>>::iterator it =
				outers.lower_bound(make_pair(y[id], id));

			if (it != outers.end() && inside(id, it->second))
			{
				continue;
			}
			if (it != outers.begin() &&
				inside(id, (--it)->second))
			{
				continue;
			}

			res.push_back(id);
			outers.insert(make_pair(y[id], id));
		}
		else
		{
			outers.erase(make_pair(y[id], id));
		}
	}

	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] + 1 << (i + 1 ==
			res.size() ? '\n' : ' ');
	}
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> y[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> r[i];
	}

	solve();

	fclose(file);
	return 0;
}
