#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> edges[MAXN];
vector<int> visited(MAXN, 0);

void dfs(int cur) {
	visited[cur] = 1;
	for (int j = 0; j < edges[cur].size(); j++) {
		int neigh = edges[cur][j];
		if (!visited[neigh]) {
			dfs(neigh);
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> aux(n+1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y); // adiciona rua ligando o bairro x com o y
		edges[y].push_back(x);
		aux[x]++; // marca que tem rua saindo do bairro x
		aux[y]++;
	}

	int ans = 0;
	for (int i = 1; i < n+1; i++) { // percorre todos os bairros
		if (!visited[i]) { // verifica se eu já não visitei aquele bairro
			ans++; // se não visitei, adiciona um e manda dfs pra eliminar
			dfs(i); // os bairros que eu consigo chegar a partir desse
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
