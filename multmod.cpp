#include <bits/stdc++.h>
using namespace std;

/*
  Fast multiplication in O(log_2(a)) time (do it preferentially with
  a < b). Here it is doing mod m, but easily changeable.
 */
long long iterative(long long a, long long b, long long m) {
	long long pow = 1, res = 0;
	while (a > 0) {
		if (a & 1)
			res = (res + (pow * b) % m) % m;
		pow <<= 1;
		a >>= 1;
	}
	return res;
}

long long recursive(long long a, long long b, long long m) {
	if (a == 0) return 0;
	long long res = recursive(a / 2, b, m);
	if (a & 1)
		return (((res << 1) % m) + b) % m;
	else
		return (res << 1) % m;
}

long long traditional(long long a, long long b, long long m) {
	long long res = 0;
	for (int i = 0; i < a; i++)
		res = (res % m + b % m) % m;
	return res;
}

int main() {
	long long a, b, m;

	cin >> a >> b >> m;

	printf("iterative: %d\n", iterative(a, b, m));
	printf("recursive: %d\n", recursive(a, b, m));
	printf("traditional: %d\n", traditional(a, b, m));

	return 0;
}
