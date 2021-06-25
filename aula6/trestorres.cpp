#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const long long INF = 1e9 + 7;
long long memo[MAXN][MAXN][MAXN];

long long solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (memo[a][b][c] != -1) return memo[a][b][c];
	
	long long ans = 0;
	if (a <= b) {
		ans += solve(a, b-a, c) % INF;
	}
	if (a <= c) {
		ans += solve(a, b, c-a) % INF;
	}
	if (b <= a) {
		ans += solve(a-b, b, c) % INF;
	}
	if (b <= c) {
		ans += solve(a, b, c-b) % INF;
	}
	if (c <= a) {
		ans += solve(a-c, b, c) % INF;
	}
	if (c <= b) {
		ans += solve(a, b-c, c) % INF;
	}
	
	memo[a][b][c] = ans % INF;

	return ans % INF;
}

int main() {
	memset(memo, -1, sizeof(memo));
	int a, b, c;
	cin >> a >> b >> c;

	cout << solve(a, b, c) << endl;

	return 0;
}
