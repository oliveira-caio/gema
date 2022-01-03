#include <bits/stdc++.h>
using namespace std;

/*
  Fast exponentiation iterative and recursive.
  Also implemented the traditional just for comparison.
 */
long long iterative(long long a, long long n) {
	long long res = 1, pow = a;
	while (n) {
		if (n & 1) res *= pow;
		pow *= pow;
		n >>= 1;
	}
	return res;
}

long long recursive(long long a, long long n) {
	if (n == 0) return 1;
	long long res = recursive(a, n / 2);
	if (n & 1)
		return a * res * res;
	else
		return res * res;
}

long long traditional(long long a, long long n) {
	long long res = 1;
	for (long long i = 0; i < n; i++)
		res *= a;
	return res;
}

int main() {
	long long a, n;

	cin >> a >> n;

	printf("iterative: %d\n", iterative(a, n));
	printf("recursive: %d\n", recursive(a, n));
	printf("traditional: %d\n", traditional(a, n));

	return 0;
}
