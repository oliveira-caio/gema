#include <bits/stdc++.h>
using namespace std;

int m;

int bla(int falta, int ultima_colherada, int penultima_colherada) {
	
	int ans = 0;
	
	if (ultima_colherada == m) return 1;
	
	if (penultima_colherada != 0) {
		if (ultima_colherada % penultima_colherada != 0) return 0;
	}
	
	if (falta <= 0) {
		if (falta < 0) return 0;
		return 1;
	}
	
	penultima_colherada = ultima_colherada;
	
	for (int i = 1; i <= falta; i++) {
		ans += bla(falta - i, i, penultima_colherada);
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	m = n;

	cout << bla(n, 0, 0) << endl;
	
	return 0;
}
