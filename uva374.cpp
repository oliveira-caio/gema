#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long x, long long y, long long m) {
	long long res = 1, pow = x;
	while (y > 0) {
		if (y & 1)
			res = (res * pow) % m;
		pow = (pow % m) * (pow % m) % m;
		y >>= 1;
	}
	return res;
}

int main() {
	long long x, y, m;
	char c;
	while (cin >> x >> y >> m)
		cout << bigmod(x, y, m) << endl;
	return 0;
}
