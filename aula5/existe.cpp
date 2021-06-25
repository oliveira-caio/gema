#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 5;
const int BLA = 1e3 + 5;
int dist[MAXN];
int adj[BLA][BLA];
vector<int> edges[BLA];
int n;
 
void bfs(int source) {
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
}
 
int main() {
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
			if (i == j && adj[i][j] != 0) {
				cout << "nao" << endl;
				return 0;
			}
			if (adj[i][j] == 1) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
 
	for (int i = 0; i < n; i++) {
		bfs(i);
		for (int j = i+1; j < n; j++) {
			if (adj[i][j] != adj[j][i]) {
				cout << "nao" << endl;
				return 0;				
			} else if (adj[i][j] == 1 || adj[i][j] == -1) {
				continue;
			} else if (adj[i][j] != dist[j]) {
				cout << "nao" << endl;
				return 0;
			}
		}		
	}
 
	cout << "sim" << endl;	
	return 0;
}
