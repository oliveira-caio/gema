#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, ans = 0, n, h;

	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i > 0) {
			ans = ans + 4 * abs(a-b);
		}
		b = a;
	}

	cout << ans << endl;
	
	return 0;
}
