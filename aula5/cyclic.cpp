#include <bits/stdc++.h>
using namespace std;
     
const int MAXN = 1e5 + 5;
vector<int> edges[2 * MAXN];
vector<int> visited(2 * MAXN, 0);
bool vecbool[2 * MAXN];

bool dfs(int cur) {
	visited[cur] = 1;
     
	if (edges[cur].size() != 2) { // se o atual falhar, significa que os vizinhos também vão
		vecbool[cur] = false;
		return false;
	}
	
	int neighl = edges[cur][0];
	int neighr = edges[cur][1];
	if (edges[neighl].size() != 2) { // se um dos vizinhos falhar, o atual também vai e o outro vizinho do atual também
		visited[neighl] = 1;
		visited[neighr] = 1;
		vecbool[neighl] = false;
		vecbool[cur] = false;
		vecbool[neighr] = false;
		return false;
	}
	if (edges[neighr].size() != 2) { // o mesmo que o de cima
		visited[neighr] = 1;
		visited[neighl] = 1;
		vecbool[neighr] = false;
		vecbool[cur] = false;
		vecbool[neighl] = false;
		return false;
	}
	if (!visited[neighl]) {
		if (!dfs(neighl)) {
			vecbool[neighl] = false;
			vecbool[cur] = false;
			vecbool[neighr] = false;
			return false;
		}
	}
	if (!visited[neighr]) {
		if (!dfs(neighr)) {
			vecbool[neighl] = false;
			vecbool[cur] = false;
			vecbool[neighr] = false;
			return false;
		}
	}
	
	if (visited[neighl]) return vecbool[neighl];
	if (visited[neighr]) return vecbool[neighr];
	
	return true;
}
     
int main() {
	memset(vecbool, 1, sizeof(vecbool));
	int n, m;
	cin >> n >> m;
        
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
     
	int ans = 0;
	bool tmp;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			tmp = dfs(i);
			vecbool[i] = tmp;
			// cout << tmp << endl;
			if (tmp) {
				// cout << i << endl;
				ans++;
			}
		}
	}
        
	cout << ans << endl;
        
	return 0;
}
