#include <bits/stdc++.h>
using namespace std;

int main() {
 	int n, m, aux = 0;
	cin >> n;

	for(int i = 0; i < n; i++) {
 		cin >> m;
 		if (m > 0 && m % 2 == 0) {
 			aux++;
 		}
 		if (m < 0 && m % 2 == 0) {
 			aux++;
 		}
 	}
	
	if (aux > 1) {
		cout << aux << endl;
 		return 0;
 	}
	
 	cout << 0 << endl;
 	return 0;
}
