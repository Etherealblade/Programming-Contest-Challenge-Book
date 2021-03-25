/*
DP 
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>

#define MAX_N 16
int x[MAX_N], y[MAX_N], dp[1 << MAX_N];
// dp[S] := 点集为S时的最省面积
using namespace std;

struct Rect
{
	int coverd; // 内含点集
	int area;   // 面积

	Rect(const int& coverd, const int& area) :
		coverd(coverd), area(area)
	{

	}

	void add(int i)
	{
		coverd |= 1 << i;
	}
};

/*
* 点k是否在点i和点j围成的矩形中
*/
bool is_in(int i, int j, int k)
{
	return ((x[i] - x[k]) * (x[j] - x[k]) <= 0) &&
		((y[i] - y[k]) * (y[j] - y[k]) <= 0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> x[i] >> y[i];
		}

		vector<Rect> rarray;


		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				Rect r((1 << i) | (1 << j), max(1,
					(int const &)abs(x[i] - x[j])) *
					max(1, (int const &)abs(y[i] - y[j])));
				for (int k = 0; k < n; ++k)
				{
					if (is_in(i, j, k))
					{
						r.add(k);
					}
				}
				rarray.push_back(r);
			}
		}

		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;  // 包含0个点的矩形的面积是0
		for (vector<Rect>::iterator it =
			rarray.begin(); it != rarray.end(); ++it)
		{
			for (int s = 0; s < 1 << n; ++s)
			{
				int ns = s | it->coverd;
				if (dp[s] != 0x3f3f3f3f && ns != s)
				{
					dp[ns] = min(dp[ns],
						dp[s] + it->area);
				}
			}
		}

		cout << dp[(1 << n) - 1] << endl;
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

	return 0;
}
