// Page 255

#include <iostream>
#include <algorithm>
#include "computational_geometry.h"
using namespace std;

#define MAX_N 100
const double g = 9.8;	//重力加速度

// input
int N, V, X, Y;
int L[MAX_N], B[MAX_N], R[MAX_N], T[MAX_N];

double calc(double vy, double t)
{
	// 计算以vy的速度竖直向上射出t秒后的位置
	return vy * t - g * t*t / 2;
}

int cmp(double lb, double ub, double a)
{
	// a 相对lb和ub的位置
	return a < lb + EPS ? -1 : a > ub - EPS ? 1 : 0;
}

bool check(double qx, double qy)
{
	// 判断当射出路径经过点(qx,qy)时, 卵是否能击中猪

	/*
	设初始速度在x方向和y方向的分量分别为vx和vy, 设通过(qx, qy)的
	时间为t
	求解连理方程式xv^2+vy^2=V^2, vx*t=qx, vy*t-1/2gt^2=qy
	*/
	double a = g * g / 4,
		b = g * qy - V * V,
		c = qx * qx + qy * qy;
	double D = b * b - 4 * a*c;
	if (D<0 && D>-EPS)
	{
		D = 0;
	}
	if (D < 0)
	{
		return false;
	}

	for (int d = -1; d < 1; d += 2)
	{
		//验证联立方程式的两个解的循环
		double t2 = (-b + d * sqrt(D)) / (2 * a);
		if (t2 <= 0)
		{
			continue;
		}
		double t = sqrt(t2);
		double vx = qx / t,
			vy = (qy + g * t*t / 2) / t;

		// 判断是否通过猪的正上方
		double yt = calc(vy, X / vx);
		if (yt < Y - EPS)
		{
			continue;
		}

		bool ok = true;
		for (int i = 0; i < N; i++)
		{
			if (L[i] >= X)
			{
				continue;
			}
			// 判断在猪正上方的鸟和猪之间是否有障碍物
			if (R[i] == X && Y <= T[i] && B[i] <= yt)
			{
				ok = false;
			}

			// 判断在飞到猪正上方之前是否会撞到障碍物
			int yL = cmp(B[i], T[i], calc(vy, L[i] / vx));
			int yR = cmp(B[i], T[i], calc(vy, R[i] / vx));
			int xH = cmp(L[i], R[i], vx*(vy / g));
			int yH = cmp(B[i], T[i], calc(vy, vy / g));

			if (xH == 0 && yH >= 0 && yL < 0)
			{
				ok = false;
			}
			if (yL*yR <= 0)
			{
				ok = false;
			}
		}
		if (ok)
		{
			return true;
		}
	}
	return false;
}


void solve()
{
	// 截掉猪以右的障碍物
	for (int i = 0; i < N; i++)
	{
		R[i] = min(R[i], X);
	}

	bool ok = check(X, Y);
	for (int i = 0; i < N; i++)
	{
		ok |= check(L[i], T[i]);
		ok |= check(R[i], T[i]);
	}

	cout << (ok ? "Yes" : "No") << endl;
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> N;
		cin >> V;
		cin >> X;
		cin >> Y;
		for (int i = 0; i < N; i++)
		{
			cin >> L[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> B[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> R[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> T[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

