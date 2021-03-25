/*
Page 143
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define  MAX_N 1000

// input
int n, k;
int w[MAX_N], v[MAX_N];

double y[MAX_N];	// v-x*w

bool judge(double x)
{
	// 判断是否满足条件
	for (int i = 0; i < n; i++)
	{
		y[i] = v[i] - x * w[i];
	}

	sort(y, y + n);

	// 计算y数组中从大到小前k个数的和
	double sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += y[n - i - 1];
	}

	return sum >= 0;
}

void solve()
{
	double lb = 0;
	double ub = MAX_N;

	for (int i = 0; i < 100; i++)
	{
		double mid = (lb + ub) / 2;
		if (judge(mid))
		{
			lb = mid;
		}
		else
		{
			ub = mid;
		}
	}

	cout << ub << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	solve();

	fclose(file);
	return 0;
}
