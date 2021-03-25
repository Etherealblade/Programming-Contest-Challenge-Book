// PartialSum214.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Input:
int a[] = {1,2,4,7};
int n = 4;
int k = 15;	// 15 No, 13 Yes;

// 已经从前i项得到了sum,然后对i之后分支
bool dfs(int i, int sum)
{
	if (i == n)
	{
		return sum == k;
	}

	// 不加a[i]的case
	if (dfs(i + 1, sum))
	{
		return true;
	}

	// 加上a[i]的case
	if (dfs(i + 1, sum + a[i]))
	{
		return true;
	}

	return false;
}

int main()
{
	if (dfs(0, 0))
	{
		printf("Yes\n");
	}
	else
		printf("No\n");
}

