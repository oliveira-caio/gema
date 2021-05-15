#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, l;
	int ans = 0;
	
	cin >> s >> l;

	while (s <= l) {
		s *= 3;
		l *= 2;
		ans++;
	}

	cout << ans << endl;
	
	return 0;
}
