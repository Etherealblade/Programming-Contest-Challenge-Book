// Page 273

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

#define MAX_N 100

// input
int N;
int X[MAX_N], Y[MAX_N], R[MAX_N];

ll cover(double x, double y, double r)
{
	//求出圆心在(x,y)半径为r的大圆能覆盖的圆的集合
	ll S = 0;
	for (int i = 0; i < N; i++)
	{
		if (R[i] <= r)
		{
			double dx = x - X[i],
				dy = y - Y[i],
				dr = r - R[i];
			if (dx*dx + dy * dy <= dr * dr)
			{
				S |= 1LL << i;
			}
		}
	}

	return S;
}

bool C(double r)
{
	vector<ll> cand;	// 一个大圆能覆盖的集合的列表
	cand.push_back(0);

	// case a
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (R[i] < r && R[j] < r)
			{
				// 计算两个圆的交点
				double x1 = X[i], y1 = Y[i], r1 = r - R[i];
				double x2 = X[j], y2 = Y[j], r2 = r - R[j];
				double dx = x2 - x1, dy = y2 - y1;
				double a = dx * dx + dy * dy;
				double b = ((r1*r1 - r2 * r2) / a + 1) / 2;
				double d = r1 * r1 / a - b * b;

				if (d >= 0)
				{
					d = sqrt(d);
					double x3 = x1 + dx * b;
					double y3 = y1 + dy * b;
					double x4 = -dy * d;
					double y4 = dx * d;

					// 考虑可能产生的误差, 因此对i和j做特别处理
					ll ij = 1LL << i | 1LL << j;
					cand.push_back(cover(x3 - x4, y3 - y4, r) | ij);
					cand.push_back(cover(x3 + x4, y3 + y4, r) | ij);
				}
			}
		}
	}

	// case b
	for (int i = 0; i < N; i++)
	{
		if (R[i] <= r)
		{
			cand.push_back(cover(X[i], Y[i], r) | 1LL << i);
		}
	}

	// 每次从可能的圆中取出2个, 并判断是否能覆盖所有的圆
	for (int i = 0; i < cand.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((cand[i] | cand[j]) == (1LL << N) - 1)
			{
				return true;
			}
		}
	}
	return false;
}


void solve()
{
	// 对半径r使用二分搜索
	double lb = 0, ub = 10000;
	for (int i = 0; i < 100; i++)
	{
		double mid = (lb + ub) / 2;
		if (C(mid))
		{
			ub = mid;
		}
		else
		{
			lb = mid;
		}
	}
	cout << ub << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> X[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> Y[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> R[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}
