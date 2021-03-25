// Page 250

#include <iostream>
#include "computational_geometry.h"
using namespace std;

#define MAX_N 100

// input
int n;
P p[MAX_N], q[MAX_N];
int m;
int a[MAX_N], b[MAX_N];

bool g[MAX_N][MAX_N];	// 相连关系图

void solve()
{
	for (int i = 0; i < n; i++)
	{
		g[i][i] = true;
		for (int j = 0; j < i; j++)
		{
			// 判断木棍i和木棍j是否有公共点
			if ((p[i] - q[i]).det(p[j] - q[j]) == 0)
			{
				// 平行
				g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])
					|| on_seg(p[i], q[i], q[j])
					|| on_seg(p[j], q[j], p[i])
					|| on_seg(p[j], q[j], q[i]);
			}
			else
			{
				// 非平行时
				P r = intersection(p[i], q[i], p[j], q[j]);
				g[i][j] = g[j][i] = on_seg(p[i], q[i], r)
					&& on_seg(p[j], q[j], r);
			}
		}
	}

	// 通过Floyd算法判断任意两点间是否相连
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				g[i][j] |= g[i][k] && g[k][j];
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << (g[a[i] - 1][b[i] - 1] ? "Connected" :
			"Not connected") << endl;
	}

}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x;
		cin >> p[i].y;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> q[i].x;
		cin >> q[i].y;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	solve();

	fclose(file);
	return 0;
}
