#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int INF = 1e7;

vector<int> memo(MAXN, INF);
int v[MAXN];
int n;

int solve(int posicao, int posicao_atual, int menor_distancia) {
	if (posicao_atual >= n) {
		if (menor_distancia < memo[posicao]) {
			memo[posicao] = menor_distancia;
			return menor_distancia;
		} else {
			return memo[posicao];
		}
	}
	
	if (memo[posicao_atual] != INF) return 1 + memo[posicao_atual];
	
	int ans = INF;
	
	for (int i = v[posicao]; i >= 1; i--) {
		if (posicao + i >= n) {
			ans = 1;
			break;
		}
		ans = min(ans, solve(posicao, posicao + i, 1 + menor_distancia));
	}
	
	memo[posicao] = ans;
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 1; i < n; i++) {
		cin >> v[i];
	}
	
	memo[n-1] = 1;
	
	for (int i = n-2; i >= 1; i--) {
		solve(i, i, 0);
	}
	
	cout << memo[1] << endl;
	
	return 0;
}
