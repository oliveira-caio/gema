#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n, target;
vector<int> edges[MAXN];
int visited[MAXN];

bool dfs(int search) {
	if (search == target) {
		return true;
	}
	// cout << search << endl;
	visited[search] = 1;
	for (int j = 0; j < edges[search].size(); j++) {
		int neigh = edges[search][j];
		if (!visited[neigh]) {
			if (dfs(neigh)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int m, search;
	cin >> n >> m >> search >> target;
	int adj[m+1][2];

	for (int i = 1; i < m+1; i++) {
		int x, y;
		cin >> x >> y; 
		adj[i][0] = x;
		adj[i][1] = y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	if (!dfs(search)) {
		// cout << i << endl;
		cout << "NAO" << endl;
		return 0;
	}
	
	int ans = 0;
	for (int i = 1; i < m+1; i++) {
		memset(edges, 0, sizeof(edges));
		memset(visited, 0, sizeof(visited));
		for (int j = 1; j < m+1; j++) {
			if (j == i) continue;
			else {
				edges[adj[j][0]].push_back(adj[j][1]);
				edges[adj[j][1]].push_back(adj[j][0]);
			}
		}
		if (!dfs(search)) {
			// cout << i << endl;
			cout << "NAO" << endl;
			return 0;
		}
	}

	cout << "SIM" << endl;
	return 0;
}
