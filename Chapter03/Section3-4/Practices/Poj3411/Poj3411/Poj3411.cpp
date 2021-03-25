#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_N 10 + 1

using namespace std;

class Road
{
public:
	int a, b, c, P, R;

	Road(int a, int b, int c, int P, int R) :
		a(a), b(b), c(c), P(P), R(R)
	{

	}
};

class State
{
public:
	int current,    // 当前位置
		cost,		// 总花费
		S;			// 已通过的城市

	State(int current, int cost, int S) :
		current(current), cost(cost), S(S)
	{}

	bool operator>(const State &other) const
	{
		return cost > other.cost;
	}
};

vector<Road> edge[MAX_N];  // 边的集合,edge[from]
bool visited[MAX_N][1 << MAX_N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int N, m;
	cin >> N >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c, P, R;
		cin >> a >> b >> c >> P >> R;
		edge[a].push_back(Road(a, b, c, P, R));
	}

	priority_queue<State,
		vector<State>, greater<State> > que;

	// 现在位于起点1，花费是0，已通过的城市的集合是{1}
	que.push(State(1, 0, 1 << 1));

	memset(visited, 0, sizeof(visited));
	State result(-1, -1, -1);

	while (!que.empty())
	{
		State p = que.top();
		que.pop();

		if (visited[p.current][p.S])
		{
			continue;
		}

		visited[p.current][p.S] = true;

		if (p.current == N)
		{
			result = p;
			break;
		}

		for (auto& it : edge[p.current])
		{
			Road e = it;
			int cost = p.cost;

			if (p.S & (1 << e.c))	// 不懂其中含义
			{
				cost += min(e.P, e.R);	
			}
			else
			{
				cost += e.R;
			}
			que.push(State(e.b, cost,
				p.S | (1 << e.b)));	// 不知其意
		}

	}

	if (result.current == -1)
	{
		cout << "impossible\n";
	}
	else
	{
		cout << result.cost << endl;
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}