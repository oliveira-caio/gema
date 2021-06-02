#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n, m, min = 0, max = 0, eq = 0;

	cin >> n >> m;

	long long int matriz[n][m];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> matriz[i][j];
		}
	}

	for(int j=0; j<m; j++) {
		for(int i=1; i<n; i++) {
			if (matriz[i][j] > matriz[i-1][j]) {
				max++;
			}
			if (matriz[i][j] < matriz[i-1][j]) {
				min++;
			}
			if (matriz[i][j] == matriz[i-1][j]) {
				eq++;
			}
		}
		if (max == n-1 || min == n-1 || eq == n-1) {
			cout << "S" << endl;
		} else {
			cout << "N" << endl;
		}
		max = 0;
		min = 0;
		eq = 0;
	}

	return 0;
}
