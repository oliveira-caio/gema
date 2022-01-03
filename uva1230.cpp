#include <bits/stdc++.h>
using namespace std;

int modex(int x, int y, int n) {
	int res = 1, pow = x;
	while (y > 0) {
		if (y & 1)
			res = (res * pow) % n;
		pow = (pow % n) * (pow % n) % n;
		y >>= 1;
	}
	return res;
}

int main() {
	int c, x, y, n;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> x >> y >> n;
		cout << modex(x, y, n) << endl;
	}
	return 0;
}
