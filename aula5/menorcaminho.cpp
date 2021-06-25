#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> edges[MAXN];
int dist[MAXN];

int bfs(int source, int target) {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	dist[source] = 0;
	q.push(source);

	while(q.size()) {
		int frente = q.front();
		q.pop();
		for (int i = 0; i < edges[frente].size(); i++) {
			int neigh = edges[frente][i];
			if (dist[neigh] == -1) {
				dist[neigh] = dist[frente] + 1;
				q.push(neigh);
			}
		}
	}

	return dist[target];
}

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	int ans = bfs(a, b);
	cout << ans << endl;

	return 0;
}
