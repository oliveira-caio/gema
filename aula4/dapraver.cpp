#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int mapa[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mapa[i][j] = 1;
			char x;
			cin >> x;
			if (x == 35) mapa[i][j] = 0;  // #
			if (x == 76) mapa[i][j] = -1; // left
			if (x == 85) mapa[i][j] = -2; // up
			if (x == 68) mapa[i][j] = -3; // down
			if (x == 82) mapa[i][j] = -4; // right
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapa[i][j] == -1) {
				int k = j;
				while (k >= 0 && mapa[i][k] != 0) {
					mapa[i][k] = -80;
					k--;
				}
				continue;
			}
			if (mapa[i][j] == -2) {
				int k = i;
				while (k >= 0 && mapa[k][j] != 0) {
					mapa[k][j] = -80;
					k--;
				}
				continue;
			}
			if (mapa[i][j] == -3) {
				int k = i;
				while (k < n && mapa[k][j] != 0) {
					mapa[k][j] = -80;
					k++;
				}
				continue;
			}
			if (mapa[i][j] == -4) {
				int k = j;
				while (k < m && mapa[i][k] != 0) {
					mapa[i][k] = -80;
					k++;
				}
				continue;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cout << mapa[i][j] << " ";
			if (mapa[i][j] == 1) ans++;
		}
		// cout << endl;
	}

	if (ans == 0) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	if (ans == 1) {
		cout << "ONLY ONE SOLUTION" << endl;
		return 0;
	}

	if (ans > 1) {
		cout << "MULTIPLE SOLUTIONS" << endl;
		return 0;
	}
}
