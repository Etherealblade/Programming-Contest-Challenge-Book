/*
Page158
*/

#include <iostream>
#include <algorithm>
using namespace std;

// input
#define N 2
int H = 10;
int R = 10;
int T = 100;

double y[N];	// 球的最终位置
const double g = 10.0;

double calc(int T)
{
	// 求出T时刻球的位置
	if (T < 0)
	{
		return H;
	}
	double t = sqrt(2 * H / g);
	int k = (int)(T / t);
	if (k % 2 == 0)
	{
		double d = T - k * t;
		return H - g * d*d / 2;
	}
	else
	{
		double d = k * t + t - T;
		return H - g * d*d / 2;

	}
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		y[i] = calc(T - i);
	}

	sort(y, y + N);
	for (int i = 0; i < N; i++)
	{
		printf_s("%.2f%c", y[i] + 2 * R*i / 100.0,
			i + 1 == N ? '\n' : ' ');
	}
}

int main()
{
	solve();
}
