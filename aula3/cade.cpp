#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> k;
			if (k == 0) {
				cout << i << " " << j << endl;
				return 0;
			}
		}	
	}
}
