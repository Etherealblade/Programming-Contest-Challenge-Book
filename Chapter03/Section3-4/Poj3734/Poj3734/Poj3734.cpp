// Page 202
#include <iostream>
#include "Matrix.h"
using namespace std;

// input
int N;

void solve()
{
	mat A(3, vec(3));
	A[0][0] = 2, A[0][1] = 1, A[0][2] = 0;
	A[1][0] = 2, A[1][1] = 2, A[1][2] = 2;
	A[2][0] = 0, A[2][1] = 1, A[2][2] = 2;

	A = pow(A, N);
	cout << A[0][0] << endl;
}

int main()
{
	cin >> N;
	solve();
}

