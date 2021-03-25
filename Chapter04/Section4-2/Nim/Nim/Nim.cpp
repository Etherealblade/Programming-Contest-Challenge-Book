/*
Page 311
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1024

int N, Arr[MAX_N];

void solve()
{
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		x ^= Arr[i];
	}

	if (x != 0)
	{
		puts("Alice");
	}
	else
	{
		puts("Bob");
	}
}


int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count>0)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> Arr[i];
		}

		solve();
		count--;
	}
	

	return 0;
}

