/*
Page 141
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000

int N, K;	
double L[MAX_N];

bool judge(double x)
{
	// 判断是否满足条件
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		num += (int)(L[i] / x);
	}

	return num >= K;
}

void solve()
{
	// 初始化解的范围
	double lb = 0, ub = MAX_N;

	// 重复循环, 直到解的范围足够小
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

	cout << floor(ub * 100) / 100 << endl;
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}

	solve();

	fclose(file);
}
