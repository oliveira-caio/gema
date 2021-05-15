#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	if (k == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	if (k % 2 != 0) {
		if (k == 1) {
			cout << 1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	if ((n-1) % 4 == 0) {
		cout << (n-1) / 4 << endl;
		return 0;
	}
	
	if ((n-1) % 4 == 1) {
		if (k == 2) {
			cout << (n-1) / 4 + 1 << endl;
			return 0;
		}
		cout << (n-1) / 4 << endl;
		return 0;
	}
	
	if ((n-1) % 4 == 2) {
		if (k == 2 || k == 4) {
			cout << (n-1) / 4 + 1 << endl;
			return 0;
		}
		cout << (n-1) / 4 << endl;
		return 0;
	}
	
	if ((n-1) % 4 == 3) {
		if (k == 2 || k == 4 || k == 8) {
			cout << (n-1) / 4 + 1 << endl;
			return 0;
		}
		cout << (n-1) / 4 << endl;
		return 0;
	}
}
