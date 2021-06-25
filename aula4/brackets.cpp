#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;

	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] == ')') {
			cout << "NO" << endl;
			return 0;
		}
		if (s[i] == '(') ans++;
		if (s[i] == ')') ans--;
		if (ans < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (!ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}	
	
	return 0;
}
