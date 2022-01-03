#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1e8;

vector<int> memo(MAXN, INF);
int v[MAXN];
int n;

int solve(int posicao, int menor_distancia) {
	int ans = INF;

	if (posicao >= n-1) return menor_distancia;
	if (memo[posicao] != INF) {
		if (menor_distancia < memo[posicao]) {
			memo[posicao] = menor_distancia;
			return menor_distancia;
		}
		memo[posicao];
	}
	
	for (int i = 1; i <= v[posicao]; i++) {
		ans = min(ans, solve(posicao+i, 1+menor_distancia));
	}
	
	memo[posicao] = ans;

	return ans + 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		cin >> v[i];
	}
	
	int ans = solve(0, 0);
	cout << memo[0] << endl;
	
	return 0;
}
