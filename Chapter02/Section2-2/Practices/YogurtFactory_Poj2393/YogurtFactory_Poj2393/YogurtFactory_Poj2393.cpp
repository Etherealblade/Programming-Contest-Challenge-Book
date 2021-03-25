/*
Type: Greedy-Other

总结:
1. 这题完全是考数学, 其中的数学也不是很难, 但是没有
弄清各个变量之间的关系.
*/

#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N, S;
	cin >> N >> S;
	int P = 5000;	// 如何搞出这个变量的?
	long long costs = 0;

	for (int i = 0; i < N; ++i)
	{
		int C, Y;
		cin >> C >> Y;
		P = min(P + S, C);
		costs += P * Y;
	}

	cout << costs << endl;

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}

