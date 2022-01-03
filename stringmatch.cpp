#include <bits/stdc++.h>
using namespace std;

int match(string s, string search) {
	int ans = 0, k;
	for (int i = 0; i < s.length(); i++, k = 0) {
		for (int j = 0; j < search.length(); j++) {
			if (i+k >= s.length() || s[i+k] != search[j]) break;
			k++;
		}
		if (k == search.length()) ans++;
	}
	return ans;
}

int main() {
	string s, search;
	cin >> s >> search;

	cout << match(s, search) << endl;

	return 0;
}
