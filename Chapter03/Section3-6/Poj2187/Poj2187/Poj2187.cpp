// Page 261. 把代码抄一遍都累死, 到底何时才能独立解题

#include <iostream>
#include <vector>
#include <algorithm>
#include "computational_geometry.h"
using namespace std;

#define MAX_N 100

// input
int N;
P ps[MAX_N];

bool cmp_x(const P& p, const P& q)
{
	if (p.x != q.x)
	{
		return p.x < q.x;
	}

	return p.y < q.y;
}

vector<P> convex_hull(P* ps, int n)
{
	sort(ps, ps + n, cmp_x);
	int k = 0;
	vector<P> qs(n * 2);	// 构造中的凸包

	// 构造凸包的下侧
	for (int i = 0; i < n; i++)
	{
		while (k > 1 && (qs[k - 1] - qs[k - 2]).det(
			ps[i] - qs[k - 1]) <= 0)
		{
			k--;
		}
		qs[k++] = ps[i];
	}

	// 构造凸包的上侧
	for (int i = n - 2, t = k; i >= 0; i--)
	{
		while (k > t && (qs[k - 1] - qs[k - 2]).det(
			ps[i] - qs[k - 1]) <= 0)
		{
			k--;
		}
		qs[k++] = ps[i];
	}

	qs.resize(k - 1);
	return qs;
}

double dist(P p, P q)
{
	return (p - q).dot(p - q);
}


void solve()
{
	vector<P> qs = convex_hull(ps, N);
	double res = 0;
	for (int i = 0; i < qs.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			res = max(res, dist(qs[i], qs[j]));
		}

	}
	
	cout << res << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ps[i].x;
		cin >> ps[i].y;
	}

	solve();

	fclose(file);
	return 0;
}
