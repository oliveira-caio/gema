#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans = 0;
	string s;
	getline (cin,s);
	unordered_set<char> uset;

	for (int i = 1; i < (s.size()-1); i++) {
		if (s[i] == ' ') continue;
		if (s[i] == ',') continue;
		if (uset.find(s[i]) != uset.end()) {
			continue;
		}
		uset.insert(s[i]);
		ans++;
	}

	cout << ans << endl;
	
	return 0;
}
