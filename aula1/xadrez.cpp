#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;

	cin >> x;
	cin >> y;

	if (x % 2 != 0 && y % 2 != 0) {
		cout << (x * y) / 2 + 1 << endl;
	} else {
		cout << (x * y) / 2 << endl;
	}
  
	return 0;
}
