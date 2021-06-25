#include <bits/stdc++.h>
using namespace std;

int n, m;
long long memo[20][2][20][20];

long long solve(string num, int i, bool eq, int quatro, int sete) {
	if (i == num.size()) {
		if (quatro == n || sete == m) return 1;
		return 0;
	}

	if (memo[i][eq][quatro][sete] != -1) {
		return memo[i][eq][quatro][sete];
	}

	int lim = 9;
	long long res = 0;
	if (eq) lim = num[i] - '0';
	for (int d = 0; d <= lim; d++) {
		int new_i = i + 1;
		bool new_eq = eq;
		if (d != lim) new_eq = false;

		int new_quatro = quatro;
		if (d == 4) new_quatro++;

		int new_sete = sete;
		if (d == 7) new_sete++;

		res += solve(num, new_i, new_eq, new_quatro, new_sete);
	}

	memo[i][eq][quatro][sete] = res;
	
	return memo[i][eq][quatro][sete];
}

int main() {
	long long left, right;
	string l, r;
	cin >> n >> m;
	cin >> l >> r;
	left = stoll(l, nullptr, 10);
	l = to_string(left-1);
	memset(memo, -1, sizeof(memo));
	right = solve(r, 0, true, 0, 0);	
	memset(memo, -1, sizeof(memo));
	left = solve(l, 0, true, 0, 0);
	cout << right - left << endl;
		
	return 0;
}
