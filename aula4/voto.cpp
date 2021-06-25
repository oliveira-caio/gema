#include <bits/stdc++.h>

using namespace std;

int main() {
	string k, v;
	long int n;
	int sexta = 0, quarta = 0;
	cin >> n;

	unordered_set<pair<string, string>> myset;
	set<string> pessoas;
	for (int i = 0; i < n; i++) {
		cin >> k >> v;
		if (pessoas.find(k) == pessoas.end()) {
			myset.insert(make_pair(k, v));
			pessoas.insert(k);
		}
	}

	for (auto x : myset) {
		if (x.second == "quarta") quarta++;
		if (x.second == "sexta") sexta++;
	}

	if (quarta > sexta) {
		cout << "quarta" << endl;
		return 0;
	}

	if (sexta > quarta) {
		cout << "sexta" << endl;
		return 0;
	}

	cout << "empate" << endl;
	
	return 0;
}
