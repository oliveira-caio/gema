#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1e8;

vector<int> memo(MAXN, INF);
int v[MAXN];
int n;

int solve(int posicao, int menor_distancia, int powerup) {
	int ans = 0;

	if (memo[posicao] != INF) return memo[posicao];

	if (posicao >= n) return menor_distancia;
	
	if (v[posicao] == -1) {
		memo[posicao] = INF - 1;
		return INF - 1;
	} else if (v[posicao] == 1) {
		ans = solve(posicao + 1, menor_distancia + 1, powerup);
	} else {
		ans = min(solve(posicao + 1, menor_distancia + 1, powerup),
				  solve(posicao+1+pow(2,powerup), menor_distancia+1, powerup+1));
	}

	memo[posicao] = ans;

	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		if (x == '.')
			v[i] = -1;
		else if (x == 'p')
			v[i] = 3;
		else
			v[i] = 1;
	}
	
	int ans = solve(0, 0, 1);
	if (ans == INF - 1) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	
	
	return 0;
}
