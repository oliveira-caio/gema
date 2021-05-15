#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i = 0, j, ans = 0;
	string s;

	cin >> n >> s;

	j = n-1;
	while (i < (n / 2)) {
		if (s[i] != s[j]) ans++;
		i++;
		j--;
	}
	
	cout << ans << endl;
	
	return 0;
}
