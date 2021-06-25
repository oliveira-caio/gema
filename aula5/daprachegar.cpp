#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, target;
vector<int> edges[MAXN];
vector<int> visited(MAXN, 0);

bool dfs(int search) {
	if (search == target) {
		return true;
	}

	visited[search] = 1;

	for (int j = 0; j < edges[search].size(); j++) {
		int neigh = edges[search][j];
		if (!visited[neigh]) {
			if (dfs(neigh)) return true;
		}
	}

	return false;
}

int main() {
	int m, search;
	cin >> n >> m >> search >> target;


	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; 
		edges[x].push_back(y);
	}

	if (dfs(search)) {
		cout << "SIM" << endl;
		return 0;
	}

	cout << "NAO" << endl;
	return 0;
}
