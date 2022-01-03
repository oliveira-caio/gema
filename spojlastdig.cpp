#include <bits/stdc++.h>
using namespace std;

int lastdigit(int x, int y) {
	int cur = 1, pow = x % 10;
	while (y > 0) {
		if (y & 1) cur = (cur * pow) % 10;
		pow = (pow * pow) % 10;
		y >>= 1;
	}
	return cur;
}

int main() {
	int t, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		if (y == 0) {
			cout << 1 << endl;
			continue;
		} else if (x == 0 && y != 0) {
			cout << 0 << endl;
		} else {
			cout << lastdigit(x, y) << endl;
		}
	}
	return 0;
}
