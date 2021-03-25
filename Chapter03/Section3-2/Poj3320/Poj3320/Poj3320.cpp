/*
Page149
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define P 5
int arr[P] = { 1,8,8,8,1 };

void solve()
{
	// 计算全部知识点的总数
	set<int> all;
	for (int i = 0; i < P; i++)
	{
		all.insert(arr[i]);
	}
	int n = all.size();

	// 利用尺取法求解
	int s = 0, t = 0, num = 0;
	map<int, int> count;	//知识点->出现次数的映射
	int res = P;
	for (;;)
	{
		while (t < P&&num < n)
		{
			if (count[arr[t++]]++ == 0)
			{
				//出现新的知识点
				num++;
			}
		}

		if (num < n)
		{
			break;
		}

		res = min(res, t - s);
		if (--count[arr[s++]] == 0)
		{
			//某个知识点的出现次数为0了
			num--;
		}
	}

	printf_s("%d\n", res);
}

int main()
{
	solve();
}

