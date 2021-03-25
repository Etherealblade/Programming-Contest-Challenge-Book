/*
Page 313

test data:
8
1 5 6 7 9 12 14 17

*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
int N, P[MAX_N];

void solve()
{
	if (N % 2 == 1)
	{
		P[N++] = 0;
	}
	sort(P, P + N);

	int x = 0;
	for (int i = 0; i + 1 < N; i += 2)
	{
		x ^= (P[i + 1] - P[i] - 1);
	}

	if (x == 0)
	{
		puts("Bob will win");
	}
	else
	{
		puts("Georgia will win");
	}
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count > 0)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> P[i];
		}

		solve();
		count--;
	}

	fclose(file);
	return 0;
}
