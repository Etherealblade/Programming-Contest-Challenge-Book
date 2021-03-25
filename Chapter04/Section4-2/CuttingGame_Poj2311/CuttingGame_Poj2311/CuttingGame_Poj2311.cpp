/*
Page 318
*/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_WH = 128;
int mem[MAX_WH][MAX_WH];
// 记忆化搜索所有的数组, 程序开始执行时全部初始化为-1

int grundy(int w, int h)
{
	if (mem[w][h] != -1)
	{
		return mem[w][h];
	}

	set<int> s;
	for (int i = 2; w - i >= 2; i++)
	{
		s.insert(grundy(i, h) ^ grundy(w - i, h));
	}
	for (int i = 2; h - i >= 2; i++)
	{
		s.insert(grundy(w, i) ^ grundy(w, h - i));
	}

	int res = 0;
	while (s.count(res))
	{
		res++;
	}

	return mem[w][h] = res;
}

void solve(int w, int h)
{
	if (grundy(w, h) != 0)
	{
		puts("Win");
	}
	else
	{
		puts("Lose");
	}
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int counter = 2;
	while (counter > 0)
	{
		int w, h;
		cin >> w;
		cin >> h;

		memset(mem, -1, sizeof(mem));

		solve(w, h);
		counter--;
	}

	/*
	下面的初始化方式导致输入: 2 2 后得到Win, Lose expected!
	因为下面的memset(), 并没有把mem的数值初始化为-1
	*/
	//mem = new int *[w*h + 1];
	//for (int i = 0; i < w*h + 1; i++)
	//{
	//	mem[i] = new int[w*h + 1];
	//}

	fclose(file);
	return 0;
}

