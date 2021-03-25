/*
Page 309
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A, B;

void solve()
{
	bool f = true;

	for (;;)
	{
		if (A > B)
		{
			swap(A, B);
		}

		// B是A的倍数时必胜
		if (B%A == 0)
		{
			break;
		}

		// 如果是解说中的第二种case必胜
		if (B - A > A)
		{
			break;
		}

		B = -A;
		f = !f;
	}

	if (f)
	{
		cout << "Stan wins" << endl;
	}
	else
	{
		cout << "Ollie wins" << endl;
	}
}

int main()
{
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin);

	int count = 2;
	while (count>0)
	{
		cin >> A;
		cin >> B;

		solve();
		count--;
	}

	fclose(file);
	return 0;
}

