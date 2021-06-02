#include <bits/stdc++.h>
using namespace std;

int main() {	
	int n, x;

	cin >> n >> x;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int somaparcial = 0;
		for (int j = 0; j < n; j++) {
			if(((i >> j) & 1) == 1) {
				somaparcial += v[j];
			}
		}
		if (somaparcial == x) ans++;
	}

	cout << ans << endl;
	
	return 0;
}
