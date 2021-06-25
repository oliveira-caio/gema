#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
int memo[MAXN][MAXN];
string x, y;

int lcs(int i, int j) {
	if (i == x.size() || j == y.size()) return 0;
	if (memo[i][j] != -1) return memo[i][j];

	int ans = max(lcs(i + 1, j), lcs(i, j+1));
	if (x[i] == y[j]) {
		ans = 1 + lcs(i+1, j+1);
	}
	memo[i][j] = ans;
	return ans;	
}

int main() {
	memset(memo, -1, sizeof(memo));
	int i = 0, j = 0;
	cin >> x >> y;

	cout << lcs(i, j) << endl;
	
	return 0;
}
